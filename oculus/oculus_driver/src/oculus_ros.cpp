#include <oculus_driver/oculus_ros.h>
#include <oculus_driver/util.h>
#include <oculus_msgs/HMDInfo.h>
#include <OVR_CAPI.h>
#include <iostream>
#include "../LibOVR/Src/CAPI/CAPI_HMDState.h"
#include <tf/transform_datatypes.h>

namespace oculus_driver
{

    OculusRos::OculusRos(ros::NodeHandle& node)
    : parent_frame("base_link")
    , oculus_frame("oculus")
    , UsingDebugHmd(false)
    , node(node)
    , Hmd(nullptr)
    , PositionTrackingEnabled(false)
    {
        ROS_INFO("Oculus Rift Object Created");
    }

    bool OculusRos::init()
    {

        ROS_INFO("Oculus Rift System Starting");

        ros::NodeHandle private_node("~");
        private_node.getParam("parent_frame", parent_frame);
        private_node.getParam("oculus_frame", oculus_frame);
	
		ovr_Initialize();
		Hmd= ovrHmd_Create(0);
		if (!Hmd)
		{
		    ROS_INFO("Unable to create HMD: %s", ovrHmd_GetLastError(NULL));

			// If we didn't detect an Hmd, create a simulated one for debugging.
			Hmd = ovrHmd_CreateDebug(ovrHmd_DK2);
			UsingDebugHmd = true;
			ROS_INFO("Tying to create virtual HMD...");
			if (!Hmd)
			{   // Failed Hmd creation.
			  ROS_INFO("Virtual HMD creation failed!");
				return false;
			}
			ROS_INFO("Virtual HMD created!");
		
		
		}
		//register publisher
		else{
		        hmd_pub = node.advertise<oculus_msgs::HMDInfo>("/oculus/hmd_info", 10);
		        o_pub = node.advertise<geometry_msgs::Quaternion>("/oculus/orientation", 10);
		        p_pub = node.advertise<geometry_msgs::Pose>("/oculus/pose", 10);
		    }
		// Start the sensor which provides the Rift’s pose and motion.
		ovrHmd_ConfigureTracking(Hmd, ovrTrackingCap_Orientation |
						  ovrTrackingCap_MagYawCorrection |
						  ovrTrackingCap_Position, 0);



		return true;
	}

    OculusRos::~OculusRos()
    {
        ovrHmd_Destroy(Hmd);
    	ovr_Shutdown();
    }

    void OculusRos::publish()
    {

        ros::Time now = ros::Time::now();
	
		// Query the HMD for the current tracking state.
		ovrTrackingState ts  = ovrHmd_GetTrackingState(Hmd, ovr_GetTimeInSeconds());

		//get HMDState from Handle and extract HMDInfo
		OVR::CAPI::HMDState* hmds = (OVR::CAPI::HMDState*)Hmd->Handle;


		//if tracking active
		if (ts.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)) 
		{
		  
			//get sensor data 
			ovrPoseStatef pose = ts.HeadPose;
			ovrSensorData RawSensorData=ts.RawSensorData;
			

			//get Information and publish
			oculus_msgs::HMDInfo hmd_msg;
			convertHMDInfoToMsg(hmds->OurHMDInfo, hmd_msg);

			
			//confert Orientation to Ros msg and publish
			geometry_msgs::Quaternion q_msg;
			geometry_msgs::Pose p_msg;
			convertPoseToMsg(pose.ThePose, p_msg);
			convertQuaternionToMsg(pose.ThePose.Orientation, q_msg);
			hmd_pub.publish(hmd_msg);
			p_pub.publish(p_msg);
			o_pub.publish(q_msg);
			

			//define transform
			tf::Transform transform;
			//tf cam
			transform.setOrigin(tf::Vector3(0.0, 0.0, 1.0) );
	        	transform.setRotation(tf::Quaternion(0, 0, 0, 1));
	                     
	        	br.sendTransform(tf::StampedTransform(transform, now, "base_link", "cam"));
			
			//tf oculus
			// Getting Euler angles
			tf::Quaternion squat(q_msg.x, q_msg.y, q_msg.z, q_msg.w);
			tf::Matrix3x3 matrix(squat);
			double roll, pitch, yaw;
			matrix.getRPY(roll, pitch, yaw);
			// Setting roll and pitch to zero, leaving yaw free to move only
			squat.setRPY(0, 0, yaw);
	        	        
	        	transform.setOrigin(tf::Vector3(0.0,0.0,0.0));
	        	transform.setRotation(squat);
	        	br.sendTransform(tf::StampedTransform(transform,
	                       now,
	                       parent_frame,
	                       oculus_frame));
	                       
		}
		else{
			ROS_INFO("No pose information available");
		}
        
    }

} 	// namespace oculus_driver

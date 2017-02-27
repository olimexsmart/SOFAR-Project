#ifndef __OCULUS_DRIVER_OCULUS_ROS__
#define __OCULUS_DRIVER_OCULUS_ROS__

#include <OVR.h>
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

namespace oculus_driver
{

    class OculusRos
    {
        public:
            explicit OculusRos(ros::NodeHandle& node);
            virtual bool init();
            virtual void publish();
            virtual ~OculusRos();
        private:
            bool IsInfoLoaded;
        	bool UsingDebugHmd;
            std::string parent_frame;
            std::string oculus_frame;
            ros::NodeHandle node;
	    	ovrHmd Hmd;
            ros::Publisher o_pub;
            ros::Publisher p_pub;
            ros::Publisher hmd_pub;
            tf::TransformBroadcaster br;
	    bool PositionTrackingEnabled;
    };

}  // namespace oculus_driver

#endif  // __OCULUS_DRIVER_OCULUS_ROS__

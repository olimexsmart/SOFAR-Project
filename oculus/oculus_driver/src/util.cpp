#include <oculus_driver/util.h>

namespace oculus_driver
{
  

    void convertHMDInfoToMsg(const OVR::HMDInfo& info, oculus_msgs::HMDInfo& msg)
    {
        msg.display_device_name = info.DisplayDeviceName;
        msg.product_name = info.ProductName;
        msg.manufacturer = info.Manufacturer;
        msg.version = (unsigned )info.Version;
        msg.horizontal_resolution = info.ResolutionInPixels.w;
        msg.vertical_resolution = info.ResolutionInPixels.h;
        msg.horizontal_screen_size = info.ScreenSizeInMeters.w;
        msg.vertical_screen_size = info.ScreenSizeInMeters.h;
        msg.vertical_screen_center = info.CenterFromTopInMeters;
        //msg.eye_to_screen_distance = info.
        msg.lens_separation_distance = info.LensSeparationInMeters;
        //msg.interpupillary_distance = info.InterpupillaryDistance;
        //msg.distortion_K.push_back(info.DistortionK[0]);
        //msg.distortion_K.push_back(info.DistortionK[1]);
        //msg.distortion_K.push_back(info.DistortionK[2]);
        msg.distortion_K.push_back(0);
		msg.distortion_K.push_back(0);
		msg.distortion_K.push_back(0);
        msg.desktop_x = info.DesktopX;
        msg.desktop_y = info.DesktopY;
        msg.display_id = info.DisplayId;
    }

    

    void convertQuaternionToMsg(const OVR::Quatf& quaternion,geometry_msgs::Quaternion& msg)
    {
        msg.x = quaternion.x;
        msg.y = quaternion.y;
        msg.z = quaternion.z;
        msg.w = quaternion.w;
    }
    
    void convertPositionToMsg(const OVR::Vector3f& position, geometry_msgs::Point& msg){
    	msg.x=position.x;
    	msg.y=position.y;
    	msg.z=position.z;
    }


	void convertPoseToMsg(const OVR::Posef& pose, geometry_msgs::Pose& msg){
		msg.position.x=pose.Translation.x;
		msg.position.y=pose.Translation.y;
		msg.position.z=pose.Translation.z;
		msg.orientation.x=pose.Rotation.x;
		msg.orientation.y=pose.Rotation.y;
		msg.orientation.z=pose.Rotation.z;
		msg.orientation.w=pose.Rotation.w;
	}
	
}  // namespace oculus_ros

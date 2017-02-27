#ifndef __OCULUS_DRIVER_UTIL__
#define __OCULUS_DRIVER_UTIL__

#include <OVR.h>
#include <oculus_msgs/HMDInfo.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <OVR_Stereo.h>

namespace oculus_driver
{
    void convertHMDInfoToMsg(const OVR::HMDInfo& info, oculus_msgs::HMDInfo& msg);
    void convertQuaternionToMsg(const OVR::Quatf& quaternion,geometry_msgs::Quaternion& msg);
    void convertPositionToMsg(const OVR::Vector3f& position,geometry_msgs::Point& msg);
    void convertPoseToMsg(const OVR::Posef& pose, geometry_msgs::Pose& msg);
    
    
}  // namespace oculus_driver

#endif  // __OCULUS_DRIVER_UTIL__

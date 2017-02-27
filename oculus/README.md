ROS node for Oculus Rift
========================
This is [ROS](http://ros.org) driver for [Oculus Rift](http://www.oculusvr.com).
see http://developer.oculusvr.com for Oculus Rift SDK.

Install
-----------------
Make sure you have downloaded and compiled the oculus sdk.
https://developer.oculus.com/downloads/pc/0.4.3-beta/Oculus_SDK_for_Linux_%28Experimental%29/
before invoking the make command, run ConfigureDebian.sh
Also make sure oculusd is running before starting the ros node


Packages
------------------
* oculus_driver: oculus rift HMD ROS driver.
* oculus_msgs: oculus HMD message definitions.


Nodes
=============

oculus_node (in oculus_driver package)
------------------
publishes sensor data and HMD information of Oculus Rift.

### publish

* /oculus/orientation (geometry_msgs/Quaternion) orientation of sensor.
* /oculus/hmd_info (oculus_ros/HMDInfo) HMD device info.
* /tf
* /oculus/pose (geometry_msgs/Pose) Pose of the oculus

### param
* ~frequency (double: default 10.0) [Hz] rate of publish
* ~parent_frame (string: default parent) tf frame name of parent
* ~oculus_frame (string: default oculus) tf frame name of oculus


License
-----------
BSD

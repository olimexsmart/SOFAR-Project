ROS node for Stereo Image Rendering for Oculus rift 
===================================================
This package is based on the ros package https://github.com/eokeeffe/ros-oculus-monocular_viewer.
It was modified in such a way that the node integrates the stereo camera streams instead of only the single camera stream.

Install
-----------------
clone the package into your src folder in the catkin_ws and run catkin_make

Nodes
=============

oculus-stereo_node
------------------
renders the 2 image streams for the oculus rift


KEYBORD SHORTCUTS FOR ADJUSTING THE RENDERING PARAMETERS
========================================================

* Insert:     Inter pupilar distance +
* Delete:     Inter pupilar distance -
* Home:		Picture Size +
* End:		Picture Size -
* H:          DistortionK0 -
* Y:			DistortionK0 +
* J:			DistortionK1 -
* U:			DistortionK1 +
* K:			DistortionK2 -
* I:			DistortionK2 +
* L:			DistortionK3 -
* O:			DistortionK3 +



### subscibe

* /left/image_raw
* /right/image_raw


License
-----------
BSD

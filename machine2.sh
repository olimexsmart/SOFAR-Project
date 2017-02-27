#!/bin/bash
export ROS_IP=ip.of.this.machine
export ROS_MASTER_URI=http://ip.of.the.roscore:11311

#   Visualizer
roslaunch p3dx_description rviz.launch &
sleep 10
echo "RVIZ launch"

#   Link toghether the frame of the map and the world
rosrun tf static_transform_publisher 0 0 0 0 0 0 map odom 1 &
sleep 3
echo "TF transform"

#   Launch the server that build the map
rosrun octomap_server octomap_server_node /cloud_in:=/camera/depth/points &
sleep 3
echo "Octomap server"

#   Screen grabber lauch, parameters of the windows capture should be set in the launche file
roslaunch screen_grab screengrab.launch &
sleep 5
echo "Screen grabber"

#   Stereo visualization
rosrun oculus-stereo oculus-stereo_node /left/image_raw:=/image /right/image_raw:=/image &
sleep 2
echo "Stereo visualizer"

#   You need to have 0.4.3 beta OculusSDK dowloaded, ./ConfigureDebian.sh, make, and run the ./oculusd
INSERT_YOUR_PATH_HERE./oculusd &
sleep 3
echo "oculusd"

#   Oculus driver to get orientation data
rosrun oculus_driver oculus-node &
echo "Orientation running"

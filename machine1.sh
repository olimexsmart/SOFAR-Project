#!/bin/bash
#   This basic script launches the Gazebo simulator,
#   starts mapping the OctoMap, launches the RVIZ visualizer
#   and finally launches the basic interface for controlling the robot.


#   The ROS core is the first thing to launch
export ROS_IP=ip.of.this.machine
export ROS_MASTER_URI=http://ip.of.the.roscore:11311

roscore &
sleep 5
echo "ROS core"

#   Gazebo with Pioneer and Willow Garage world
roslaunch p3dx_gazebo gazebo.launch &
sleep 10
echo "Gazebo launch"

#   Keyboard control
echo "Teleop running..."
rosrun p3dx_mover mover.py

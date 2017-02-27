# - Config file for the FooBar package
# It defines the following variables
#  OculusSDK_INCLUDE_DIRS - include directories for OculusSDK
#  OculusSDK_LIBRARIES    - libraries to link against
#  OculusSDK_EXECUTABLE   - the bar executable (NONE)
 
# Compute paths
get_filename_component(OculusSDK_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(OculusSDK_INCLUDE_DIRS "/home/tman/ros_catkin_ws/src/ros-oculus-monocular_viewer/LibOVR/LibOVR;/home/tman/ros_catkin_ws/src/ros-oculus-monocular_viewer/LibOVR/LibOVR/OculusSDK/Include")
message("CONF_INCLUDE>>> /home/tman/ros_catkin_ws/src/ros-oculus-monocular_viewer/LibOVR/LibOVR;/home/tman/ros_catkin_ws/src/ros-oculus-monocular_viewer/LibOVR/LibOVR")

set(OculusSDK_LIBRARY_DIRS /home/tman/ros_catkin_ws/src/ros-oculus-monocular_viewer/LibOVR/LibOVR)

# These are IMPORTED targets created by FooBarTargets.cmake
set(OculusSDK_LIBRARIES ovr)

#set(OculusSDK_EXECUTABLE)
set(OculusSDK_FOUND TRUE)

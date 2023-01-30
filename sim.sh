source ../../devel/setup.bash

cd ~/PX4-Autopilot
DONT_RUN=1 make px4_sitl_default gazebo

source Tools/setup_gazebo.bash $(pwd) $(pwd)/build/px4_sitl_default
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)/Tools/sitl_gazebo
# export GAZEBO_RESOURCE_PATH=$GAZEBO_RESOURCE_PATH:~/e2es_ws/src/E2ES/gazebo
# export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:~/e2es_ws/src/E2ES/gazebo/models
# export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:~/e2es_ws/devel/lib
# echo $GAZEBO_RESOURCE_PATH
# echo $GAZEBO_MODEL_PATH
# echo $GAZEBO_PLUGIN_PATH
roslaunch scout_gazebo_sim alan_ugv_uav_gazebo.launch
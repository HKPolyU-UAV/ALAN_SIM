# ALAN Gazebo Simulation


## 1.	Introduction of Function Package
This repo is based upon [AgileX Gazebo Simulation Package](https://github.com/agilexrobotics/ugv_gazebo_sim), which was intentionally modified for project [ALAN](https://github.com/pattylo/alan), a novel framework for autonomous dynamic landing utilizing a non-robocentric approach. 

## 2.	Pre-requisite

### Development Environment

​   We tested it on ubuntu 20.04 + [ROS Noetic desktop full](http://wiki.ros.org/noetic/Installation/Ubuntu)

### Download and install required function package

​	Download and install ros-control function package, ros-control is the robot control middleware provided by ROS

```
sudo apt-get install ros-noetic-ros-control
```

​	Download and install ros-controllers function package, ros-controllers are the kinematics plug-in of common models provided by ROS

```
sudo apt-get install ros-noetic-ros-controllers
```

​	Download and install gazebo-ros function package, gazebo-ros is the communication interface between gazebo and ROS, and connect the ROS and Gazebo

```
sudo apt-get install ros-noetic-gazebo-ros
```

​	Download and install gazebo-ros-control function package, gazebo-ros-control is the communication standard controller between ROS and Gazebo

```
sudo apt-get install ros-noetic-gazebo-ros-control
```

​	Download and install joint-state-publisher-gui package.This package is used to visualize the joint control.

```
sudo apt-get install ros-noetic-joint-state-publisher-gui 
```

​	Download and install teleop-twist-keyboard function package, telop-twist-keyboard is keyboard control function package, the robot can be controlled to move forward, left, right and backward through "i", "j", "l",and "," on the keyboard

```
sudo apt-get install ros-noetic-teleop-twist-keyboard 
```



## 3.	About Usage

### 1、1.	Create workspace, download simulation model function package and compile

​		Open a new terminal and create a workspace named alang_ws, enter in the terminal:

```
mkdir alang_ws
```

​		Enter the alang_ws folder

```
cd alang_ws
```

​		Create a folder to store function package named src

```
mkdir src
```

​		Enter the src folder

```
cd src
```

​		Initialize folder

```
catkin_init_workspace
```

​		Download simulation model function package

```
git clone https://github.com/agilexrobotics/ugv_sim.git
```

​		Enter the alang_ws folder

```
cd alang_ws
```

​		Confirm whether the dependency of the function package is installed
```
rosdep install --from-paths src --ignore-src -r -y 
```

​		Compile

```
catkin_make
```



### 2、2.	Run the star file of scout_v2 and scout_mini, and visualize the urdf file in Rviz

​	Enter the alang_ws folder

```
cd alang_ws
```

​	Declare the environment variable

```
source devel/setup.bash
```

​	Run the start file of scout_v2 model and visualize the model in Rviz

```
roslaunch scout_description display_scout_v2.launch 
```

![img](image/scoutv2_rviz.png) 

​	Run the start file of scout_mini model and visualize the model in Rviz

```
roslaunch scout_description display_scout_mini.launch 
```

![img](image/scout_mini_rviz.png) 

### 3、3.	Start the gazebo simulation environment of scout_v2 and scout_mini and control scout_v2 and scout_mini movement in the gazebo

​	Enter the alang_ws folder

```
cd alang_ws
```

​	Declare the environment variable

```
source devel/setup.bash
```

​	Start the simulation environment of scout_v2

```
roslaunch scout_gazebo_sim scout_empty_world.launch
```

![img](image/scoutv2_gazebo.png) 

#Control by keyboard, the scout2.0 and scout_mini can be controlled to move forward, left, right and backward through "i", "j", "l",and "," on the keyboard

```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py 
```

![img](image/teleop.png) 

​	Start the simulation environment of scout_mini

```
roslaunch scout_gazebo_sim scout_mini_playpen.launch
```

![img](image/scout_mini_gazebo.png) 

#Control by keyboard, the scout2.0 and scout_mini can be controlled to move forward, left, right and backward through "i", "j", "l",and "," on the keyboard

```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py 
```

![img](image/teleop.png) 



 


#include <ros/ros.h>
#include <cmath>
#include <random>
#include <gazebo_msgs/ModelStates.h>
#include <type_traits>
#include <tf/tf.h>

#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>

using namespace std;
static int indi = 0;
static int state_i = 0;

static geometry_msgs::PoseStamped ugv_pose;
static geometry_msgs::TwistStamped ugv_velo;
static nav_msgs::Odometry ugv_odom;
static sensor_msgs::Imu ugv_imu;

static geometry_msgs::Pose ugv_pose_pre;
static double t_pre;

static ros::Publisher ugv_pose_pub, ugv_velo_pub, ugv_imu_pub, ugv_odom_pub;

void msg_set()
{
    ugv_velo.twist.linear.x = (ugv_pose.pose.position.x - ugv_pose_pre.position.x) / (ros::Time::now().toSec() - t_pre);
    ugv_velo.twist.linear.y = (ugv_pose.pose.position.y - ugv_pose_pre.position.y) / (ros::Time::now().toSec() - t_pre);
    ugv_velo.twist.linear.z = (ugv_pose.pose.position.z - ugv_pose_pre.position.z) / (ros::Time::now().toSec() - t_pre);

    ugv_velo.header.stamp = ros::Time::now();
    ugv_velo.header.frame_id = "world";
}

void physique_car_state_callback(
    const gazebo_msgs::ModelStates::ConstPtr& msg
)
{
    gazebo_msgs::ModelStates state = *msg;

    if(indi == 0)
    {
        for(int i = 0; i < state.name.size(); i++)
        {
            if(state.name[i] == "scout/")
            {
                state_i = i;
                indi++;
            }
        }
    }

    ugv_pose.header.stamp = ros::Time::now();
    ugv_pose.header.frame_id = "world";
    ugv_pose.pose = state.pose[state_i];
    msg_set();

    ugv_pose_pub.publish(ugv_pose);
    ugv_velo_pub.publish(ugv_velo);
    ugv_odom_pub.publish(ugv_odom);
    ugv_imu_pub.publish(ugv_imu);

    ugv_pose_pre = ugv_pose.pose;
    t_pre = ros::Time::now().toSec();
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "physique_car");
    ros::NodeHandle nh;

    ros::Subscriber physique_car_state_sub;

    physique_car_state_sub = nh.subscribe<gazebo_msgs::ModelStates>(
        "/gazebo/model_states", 
        1, 
        &physique_car_state_callback
    );  

    ugv_pose_pub = nh.advertise<geometry_msgs::PoseStamped>(
        "/vrpn_client_node/gh034_car/pose",
        1
    );

    ugv_velo_pub = nh.advertise<geometry_msgs::TwistStamped>(
        "/vrpn_client_node/gh034_car/twist",
        1
    );

    ugv_odom_pub = nh.advertise<nav_msgs::Odometry>(
        "/vrpn_client_node/gh034_car/odom",
        1
    );

    ugv_imu_pub = nh.advertise<sensor_msgs::Imu>(
        "/vrpn_client_node/gh034_car/imu",
        1
    );

    ros::spin();  

    return 0;    
}
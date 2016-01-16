#include "Particle.h"
#include "inc/ros.h"

ros::NodeHandle nh;
Timer timer_ros(ROS_SAMPLING_PERIOD, cb_ros);

void init_ros(){
	nh.initNode();
}

void cb_ros(){
	nh.spinOnce();
}
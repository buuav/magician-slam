#ifndef INC_ROS_H_
#define INC_ROS_H_

#include "Particle.h"
#include "lib/ros/ros.h"
#include "lib/ros/ros/time.h"

#define ROS_SAMPLING_PERIOD 1

extern ros::NodeHandle nh;
extern Timer timer_ros;

void init_ros();
void cb_ros();

#endif
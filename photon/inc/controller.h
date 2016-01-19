#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include "Particle.h"
#include "inc/ros.h"
#include "lib/ros/geometry_msgs/Twist.h"

#define PIN_PWMA D2
#define PIN_AIN2 D4
#define PIN_AIN1 D5
#define PIN_BIN1 D6
#define PIN_BIN2 D7
#define PIN_PWMB D3

void init_controller();
void cb_controller(const geometry_msgs::Twist&);

#endif

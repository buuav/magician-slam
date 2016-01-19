#ifndef INC_IMU_H_
#define INC_IMU_H_

#include "Particle.h"
#include "inc/ros.h"
#include "lib/Adafruit_BNO055/Adafruit_BNO055.h"
#include "lib/Adafruit_BNO055/utility/imumaths.h"
#include "lib/ros/geometry_msgs/QuaternionStamped.h"
#include "lib/ros/geometry_msgs/Vector3Stamped.h"

#define IMU_SAMPLING_PERIOD 40
extern Timer timer_imu;

void init_imu();
void cb_imu();

#endif
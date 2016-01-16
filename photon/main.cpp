#include "Particle.h"
#include "inc/ros.h"
#include "inc/imu.h"
#include "inc/controller.h"

SYSTEM_MODE(SEMI_AUTOMATIC)

void setup(){
	init_ros();
	init_imu();
	init_controller();
}

void loop(){
}
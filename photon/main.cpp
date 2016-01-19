#include "Particle.h"
#include "inc/ros.h"
#include "inc/imu.h"
#include "inc/controller.h"
#include "inc/encoder.h"

SYSTEM_MODE(SEMI_AUTOMATIC)

void setup(){
	init_ros();
	init_imu();
	init_controller();
	init_encoder();
}

void loop(){
}
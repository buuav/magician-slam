#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include "Particle.h"
#include "inc/ros.h"
#include "lib/ros/std_msgs/UInt16MultiArray.h"

#define PIN_IRQ_ENCODER_LEFT    A0
#define PIN_IRQ_ENCODER_RIGHT   A1
#define ENCODER_UPDATE_PERIOD   200

extern Timer timer_encoder;

void init_encoder();
void cb_encoder();

void isr_encoder_l();
void isr_encoder_r();

#endif

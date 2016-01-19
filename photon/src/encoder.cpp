#include "inc/encoder.h"

volatile uint16_t ticks_counter[] = {0, 0};
Timer timer_encoder(ENCODER_UPDATE_PERIOD, cb_encoder);

std_msgs::UInt16MultiArray ticks_msg;
std_msgs::MultiArrayDimension ticks_array_dim;
uint16_t ticks_data[2];
ros::Publisher pub_ticks("encoder_ticks", &ticks_msg);

void init_encoder(){
	ticks_array_dim.label = "motors";
	ticks_array_dim.size = 2;
	ticks_array_dim.stride = 2;
	ticks_msg.layout.dim = &ticks_array_dim;
	ticks_msg.layout.dim_length = 1;
	ticks_msg.layout.data_offset = 0;
	ticks_msg.data = ticks_data;
	ticks_msg.data_length = 2;

	nh.advertise(pub_ticks);

	attachInterrupt(PIN_IRQ_ENCODER_LEFT, isr_encoder_l, CHANGE);
	attachInterrupt(PIN_IRQ_ENCODER_RIGHT, isr_encoder_r, CHANGE);
	timer_encoder.start();
}

void cb_encoder(){
	for(int i=0; i<2; i++){
		ticks_data[i] = ticks_counter[i];
		ticks_counter[i] = 0;
	}
	pub_ticks.publish(&ticks_msg);
}

void isr_encoder_l(){
	ticks_counter[0]++;
}
void isr_encoder_r(){
	ticks_counter[1]++;
}


#include "inc/controller.h"

geometry_msgs::Twist cmd_vel_msg;
ros::Subscriber<geometry_msgs::Twist> sub_vel("crawler0/cmd_vel", &cb_controller);

void init_controller(){
	nh.subscribe(sub_vel);

	pinMode(PIN_PWMA, OUTPUT);
	pinMode(PIN_PWMB, OUTPUT);
	pinMode(PIN_AIN1, OUTPUT);
	pinMode(PIN_AIN2, OUTPUT);
	pinMode(PIN_BIN1, OUTPUT);
	pinMode(PIN_BIN2, OUTPUT);
}

void cb_controller(const geometry_msgs::Twist &cmd_vel_msg){
	int16_t left_wheel = 255 * (0.6 * cmd_vel_msg.linear.x - 0.4 * cmd_vel_msg.angular.z);
	analogWrite(PIN_PWMA, abs(left_wheel));
	digitalWrite(PIN_AIN1, left_wheel < 0 ? LOW : HIGH);
	digitalWrite(PIN_AIN2, left_wheel < 0 ? HIGH : LOW);
	int16_t right_wheel = 255 * (0.6 * cmd_vel_msg.linear.x + 0.4 * cmd_vel_msg.angular.z);
	analogWrite(PIN_PWMB, abs(right_wheel));
	digitalWrite(PIN_BIN1, right_wheel > 0 ? LOW : HIGH);
	digitalWrite(PIN_BIN2, right_wheel > 0 ? HIGH : LOW);
}

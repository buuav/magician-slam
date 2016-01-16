#include "Particle.h"
#include "inc/imu.h"
#include "inc/ros.h"

Adafruit_BNO055 bno = Adafruit_BNO055();
Timer timer_imu(IMU_SAMPLING_PERIOD, cb_imu);

ros::Time msg_timestamp;
uint32_t msg_seq = 0;
const char msg_frame_id[] = "base_link";
geometry_msgs::QuaternionStamped orientation_msg;
geometry_msgs::Vector3Stamped angular_vel_msg, linear_accel_msg;
orientation_msg.header.frame_id = msg_frame_id;
angular_vel_msg.header.frame_id = msg_frame_id;
linear_accel_msg.header.frame_id = msg_frame_id;
ros::Publisher pub_orientation("crawler0/orientation", &orientation_msg);
ros::Publisher pub_angular_vel("crawler0/angular_velocity", &angular_vel_msg);
ros::Publisher pub_linear_accel("crawler0/linear_acceleration", &linear_accel_msg);

imu::Quaternion orientation;
imu::Vector<3> linear_accel, angular_vel;


void init_imu(){
	if(!Wire.isEnabled())	Wire.begin();
	if(!bno.begin()){
		Serial.println("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
		while(1);
	}
	delay(1000);
	bno.setExtCrystalUse(true);

	nh.advertise(pub_orientation);
	nh.advertise(pub_angular_vel);
	nh.advertise(pub_linear_accel);

	timer_imu.start();
}
void cb_imu(){
	msg_timestamp = nh.now();
	orientation = bno.getQuat();
	orientation_msg.header.seq = msg_seq;
	orientation_msg.header.stamp = msg_timestamp;
	orientation_msg.quaternion.x = orientation.x();
	orientation_msg.quaternion.y = orientation.y();
	orientation_msg.quaternion.z = orientation.z();
	orientation_msg.quaternion.w = orientation.w();
	pub_orientation.publish(&orientation_msg);

	angular_vel = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
	angular_vel_msg.header.seq = msg_seq;
	angular_vel_msg.header.stamp = msg_timestamp;
	angular_vel_msg.vector.x = angular_vel.x();
	angular_vel_msg.vector.y = angular_vel.y();
	angular_vel_msg.vector.z = angular_vel.z();
	pub_angular_vel.publish(&angular_vel_msg);

	linear_accel = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
	linear_accel_msg.header.seq = msg_seq;
	linear_accel_msg.header.stamp = msg_timestamp;
	linear_accel_msg.vector.x = linear_accel.x();
	linear_accel_msg.vector.y = linear_accel.y();
	linear_accel_msg.vector.z = linear_accel.z();
	pub_linear_accel.publish(&linear_accel_msg);

	msg_seq++;
}

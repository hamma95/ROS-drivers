#include <ros.h>
#include <std_msgs/Float32.h>

#define lmotor1 6    // left motor forward
#define lmotor2 10   // left motor backward
#define rmotor1 3   // right motor forward
#define rmotor2 9     // right motor backward

ros::NodeHandle nh;

void rmotor_cb( const std_msgs::Float32& toggle_msg){

	float speed=toggle_msg.data;


	if (speed >= 0){




		analogWrite(rmotor1,speed);
		analogWrite(rmotor2, 0);
	}

	if (speed < 0) {


		analogWrite(rmotor1, 0);
		analogWrite(rmotor2,-speed);
	}




	}

void lmotor_cb( const std_msgs::Float32& toggle_msg){
	
	float speed=toggle_msg.data;


	if (speed >= 0){
		analogWrite(lmotor1,speed);
		analogWrite(lmotor2, 0);
	}

	if (speed < 0) {
		analogWrite(lmotor1, 0);
		analogWrite(lmotor2,-speed);
	}




	}



	



ros::Subscriber<std_msgs::Float32> lwheel_sub("lmotor_cmd", &lmotor_cb );
ros::Subscriber<std_msgs::Float32> rwheel_sub("rmotor_cmd", &rmotor_cb );


void setup(){

	pinMode(lmotor1, OUTPUT);
    pinMode(lmotor2, OUTPUT);
    pinMode(rmotor1, OUTPUT);
    pinMode(rmotor2, OUTPUT);
	Serial.begin(57600);
	nh.initNode();
	nh.subscribe(lwheel_sub);
	nh.subscribe(rwheel_sub);

	
  







}




void loop(){

	nh.spinOnce();

}

#include <ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int64.h>
#include <std_msgs/Float32.h>


//declaring stuff
int lwheel,rwheel=0;
ros::NodeHandle  nh;
std_msgs::Int16 lwheelMsg;
std_msgs::Int16 rwheelMsg;
ros::Publisher lwheelPub("lwheel", &lwheelMsg); 
ros::Publisher rwheelPub("rwheel", &rwheelMsg); 




void count_lwheel()  // counts from the speed sensor
{
  lwheel++;
}

void count_rwheel()  // counts from the speed sensor
{
  rwheel++;
     }



void setup() 
{
 
  Serial.begin(9600); 
  attachInterrupt(0, count_lwheel, RISING); //pin 2 
  attachInterrupt(1, count_rwheel, RISING); //pin3, increase counter when speed sensor pin goes High
  nh.initNode();
  nh.advertise(lwheelPub);
  nh.advertise(rwheelPub);

} 

void loop() {

   
//publish encoder ticks to ros
lwheelMsg.data = lwheel;  
rwheelMsg.data = rwheel;  
lwheelPub.publish(&lwheelMsg);
rwheelPub.publish(&rwheelMsg);
nh.spinOnce();



  }



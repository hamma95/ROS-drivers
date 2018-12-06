#include <ros.h>
#include <ros/time.h>
#include <NewPing.h>
#include <sensor_msgs/LaserScan.h>

#define SONAR_NUM 3      // Number of sensors.
#define MAX_DISTANCE 400 // Maximum distance (in cm) to ping.

double laser_frequency = 1/0.09;
//ros stuff
ros::NodeHandle nh;
sensor_msgs::LaserScan laser;
ros::Publisher pub_scan( "/scan", & laser);




NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(4, 5, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(6, 7, MAX_DISTANCE), 
  NewPing(8, 9, MAX_DISTANCE)
};

void setup() {
  Serial.begin(57600); // Open serial monitor at 115200 baud to see ping results.
    nh.initNode();
    nh.advertise(pub_scan);


    //popûlate the laser scan message
  laser.header.frame_id = "laser_frame";
  laser.angle_min = -1.57/2;
  laser.angle_max = 1.57/2;
  laser.angle_increment = 1.57 / SONAR_NUM;
  laser.time_increment = (1 / laser_frequency) / (SONAR_NUM);
  laser.range_min = 0.02;
  laser.range_max = 4;
  laser.ranges.resize(SONAR_NUM);





}




long range_time=0;
long laser_time = 90;

void loop() { 


//get reading from 3 sonars,one every 30 ms
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through each sensor and display results.

    //Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    if(millis()>=range_time) {


      laser.ranges[i]=0.01*sonar[i].ping_cm() ;
      range_time =  millis() + 29;
    }    
  }


//publish a laser reading every 90 ms
  if (millis()>=laser_time) {
  
   laser.header.stamp = nh.now();

   pub_scan.publish(&laser);

   laser_time = millis() + 90;

  }




  nh.spinOnce();

}
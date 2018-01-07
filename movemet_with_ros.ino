
///Ros based movement code for the AUV


#include<Servo.h>
#include<ros.h>
#include<std_msgs/Int16.h>

ros::NodeHandle  nh;
Servo myservo1,myservo2;

void motor1Control(const std_msgs::Int16& cmd_msg){
  myservo1.writeMicroseconds(cmd_msg.data);
}
void motor2Control(const std_msgs::Int16& cmd_msg){
  myservo2.writeMicroseconds(cmd_msg.data);
}
ros::Subscriber<std_msgs::Int16> sub1("esc1", motor1Control);
ros::Subscriber<std_msgs::Int16> sub2("esc2", motor2Control);


void setup() {
  nh.initNode();
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  myservo1.attach(10);
  myservo2.attach(9);
  myservo1.writeMicroseconds(1500);
  myservo2.writeMicroseconds(1500);
}

void loop() {
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  nh.spinOnce();
  delay(1);
}


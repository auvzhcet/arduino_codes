#include<Servo.h>
int signal;
Servo myservo1,myservo2;
void setup() {
  Serial.begin(9600);
  myservo1.attach(9);
  myservo2.attach(10);
}

void loop() {
  char x=Serial.read();
  if(x=='W')                               //forward motion
   {  myservo1.writeMicroseconds(1400);
      myservo2.writeMicroseconds(1600);
    }
  if(x=='S')                              //backward motion
   {  myservo1.writeMicroseconds(1600);
      myservo2.writeMicroseconds(1400);
    }
  if(x=='D')                               //clockwise motion
  {   myservo1.writeMicroseconds(1600);
      myservo2.writeMicroseconds(1600);
  }
    if(x=='A')                             //anticlockwise motion 
    {myservo1.writeMicroseconds(1400);
    myservo2.writeMicroseconds(1400);
      }
    if(x=='Q')                              //stationary
   {  myservo1.writeMicroseconds(1500);
      myservo2.writeMicroseconds(1500);
        
        }
}


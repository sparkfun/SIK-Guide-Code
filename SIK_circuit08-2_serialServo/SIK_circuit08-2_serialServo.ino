/*
SparkFun Inventor's Kit
Example sketch 08-2

SINGLE SERVO

  Sweep a servo back and forth through its full range of motion.

  A "servo", short for servomotor, is a motor that includes 
  feedback circuitry that allows it to be commanded to move to
  specific positions. This one is very small, but larger servos
  are used extensively in robotics to control mechanical arms,
  hands, etc. You could use it to make a (tiny) robot arm,
  aircraft control surface, or anywhere something needs to be
  moved to specific positions.


This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


#include <Servo.h>  // servo library

Servo servo1;  // servo control object

int angle; 

void setup()
{
  servo1.attach(9, 900, 2100);
  Serial.begin(9600);
}


void loop()
{
  serialServo();  
}


void serialServo()
{
  int speed;
  
  Serial.println("Type an angle (0-180) into the box above,");
  Serial.println("then click [send] or press [return]");
  Serial.println();  // Print a blank line

  // In order to type out the above message only once,
  // we'll run the rest of this function in an infinite loop:

  while(true)  // "true" is always true, so this will loop forever.
  {
    // First we check to see if incoming data is available:
  
    while (Serial.available() > 0)
    {
      // If it is, we'll use parseInt() to pull out any numbers:     
      angle = Serial.parseInt();
  
      // Because servo.write() only works with numbers from
      // 0 to 180, we'll be sure the input is in that range:
  
      angle = constrain(angle, 0, 180);
      
      // We'll print out a message to let you know that the
      // number was received:
      
      Serial.print("Setting angle to ");
      Serial.println(angle);
  
      // And finally, we'll move the servo to its new position!
      
      servo1.write(angle);
    }
  }
}




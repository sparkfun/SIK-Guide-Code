/*
SparkFun Inventor's Kit
Example sketch 08-1

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


void setup()
{

  servo1.attach(9, 900, 2100);  //Connect the servo to pin 9
								//with a minimum pulse width of
								//900 and a maximum pulse width of
								//2100. 

}


void loop()
{
  int position;
  
  // To control a servo, you give it the angle you'd like it
  // to turn to. Servos cannot turn a full 360 degrees, but you
  // can tell it to move anywhere between 0 and 180 degrees.

  // Change position at full speed:

  servo1.write(90);    // Tell servo to go to 90 degrees

  delay(1000);         // Pause to get it time to move

  servo1.write(180);   // Tell servo to go to 180 degrees

  delay(1000);         // Pause to get it time to move

  servo1.write(0);     // Tell servo to go to 0 degrees

  delay(1000);         // Pause to get it time to move
  
 
	// Tell servo to go to 180 degrees, stepping by two degrees each step
 
  for(position = 0; position < 180; position += 2)
  {
    servo1.write(position);  // Move to next position
    delay(20);               // Short pause to allow it to move
  }

  // Tell servo to go to 0 degrees, stepping by one degree each step

  for(position = 180; position >= 0; position -= 1)
  {                                
    servo1.write(position);  // Move to next position
    delay(20);               // Short pause to allow it to move
  }
}


/*
SparkFun Inventor's Kit
Example sketch 09

FLEX SENSOR

  Use the "flex sensor" to change the position of a servo
  
  In the previous sketch, we learned how to command a servo to
  mode to different positions. In this sketch, we'll introduce
  a new sensor, and use it to control the servo.
  
  A flex sensor is a plastic strip with a conductive coating.
  When the strip is straight, the coating will be a certain
  resistance. When the strip is bent, the particles in the coating
  get further apart, increasing the resistance. You can use this
  sensor to sense finger movement in gloves, door hinges, stuffed
  animals, etc. See http://www.sparkfun.com/tutorials/270 for
  more information.
  
This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


// Include the servo library to add servo-control functions:

#include <Servo.h> 

Servo servo1;	//Create a servo "object", called servo1. 
				//Each servo object controls one servo (you 
				//can have a maximum of 12). 

const int flexPin = A0; //Define analog input pin to measure
						//flex sensor position. 


void setup() 
{ 
   
  Serial.begin(9600); //Set serial baud rate to 9600 bps

  servo1.attach(9); // Enable control of a servo on pin 9
} 


void loop() 
{ 
  int flexPosition;    // Input value from the analog pin.
  int servoPosition;   // Output value to the servo.

  // Read the position of the flex sensor (0 to 1023):
  
  flexPosition = analogRead(flexPin);


  servoPosition = map(flexPosition, 600, 900, 0, 180);
  servoPosition = constrain(servoPosition, 0, 180);

  // Now we'll command the servo to move to that position:

  servo1.write(servoPosition);

  
  Serial.print("sensor: ");
  Serial.print(flexPosition);
  Serial.print("  servo: ");
  Serial.println(servoPosition);
  
  
  delay(20);  // wait 20ms between servo updates
} 



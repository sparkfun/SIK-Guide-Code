/********************************************************************
 * SparkFun Inventor's Kit
 * Example sketch 12
 * 
 * SPINNING A MOTOR
 * 
 * This example requires that you drive your motor using a switching 
 * transistor. The Arduino is only capable of sourcing about 40 mA of 
 * current per pin and a motor requires upwards of 150 mA. 
 *
 * Look at the wiring diagram in the SIK Guide - Circuit #12 or read the 
 * notes in the readme tab for more information on wiring.
 * 
 * This sketch was written by SparkFun Electronics,
 * with lots of help from the Arduino community.
 * This code is completely free for any use.
 * Visit http://learn.sparkfun.com/products/2 for SIK information.
 * Visit http://www.arduino.cc to learn about the Arduino.
 * 
 * Version 2.0 6/2012 MDG
 * Version 2.1 8/2014 BCH
 *******************************************************************/

const int motorPin = 9;  // Connect the base of the transistor to pin 9.
                         // Even though it's not directly connected to the motor,
                         // we'll call it the 'motorPin'

void setup()
{
  pinMode(motorPin, OUTPUT);  // set up the pin as an OUTPUT
  Serial.begin(9600);         // initialize Serial communications
}


void loop()
{ // This example basically replicates a blink, but with the motorPin instead.
  int onTime = 3000;  // milliseconds to turn the motor on
  int offTime = 3000; // milliseconds to turn the motor off

  analogWrite(motorPin, 255); // turn the motor on (full speed)
  delay(onTime);                // delay for onTime milliseconds
  analogWrite(motorPin, 0);  // turn the motor off
  delay(offTime);               // delay for offTime milliseconds

  // Uncomment the functions below by taking out the //. Look below for the
  // code examples or documentation.
  
  // speedUpandDown(); 
  // serialSpeed();
}

// This function accelerates the motor to full speed,
// then decelerates back down to a stop.
void speedUpandDown()
{
  int speed;
  int delayTime = 20; // milliseconds between each speed step

  // accelerate the motor
  for(speed = 0; speed <= 255; speed++)
  {
    analogWrite(motorPin,speed);	// set the new speed
    delay(delayTime);           	// delay between speed steps
  }
  // decelerate the motor
  for(speed = 255; speed >= 0; speed--)
  {
    analogWrite(motorPin,speed);	// set the new speed
    delay(delayTime);           	// delay between speed steps
  }
}


// Input a speed from 0-255 over the Serial port
void serialSpeed()
{
  int speed;

  Serial.println("Type a speed (0-255) into the box above,");
  Serial.println("then click [send] or press [return]");
  Serial.println();  // Print a blank line

  // In order to type out the above message only once,
  // we'll run the rest of this function in an infinite loop:

  while(true)  // "true" is always true, so this will loop forever.
  {
    // Check to see if incoming data is available:
    while (Serial.available() > 0)
    {
      speed = Serial.parseInt();  // parseInt() reads in the first integer value from the Serial Monitor.
      speed = constrain(speed, 0, 255); // constrains the speed between 0 and 255
                                        // because analogWrite() only works in this range.

      Serial.print("Setting speed to ");  // feedback and prints out the speed that you entered.
      Serial.println(speed);

      analogWrite(motorPin, speed);  // sets the speed of the motor.
    }
  }
}





/*
SparkFun Inventor's Kit
Example sketch 10

SOFT POTENTIOMETER

  Use the soft potentiometer to change the color
  of the RGB LED

  The soft potentiometer is a neat input device that detects 
  pressure along its length. When you press it down with a finger
  (it works best on a flat surface), it will change resistance
  depending on where you're pressing it. You might use it to make
  a piano or light dimmer; here we're going to use it to control
  the color of an RGB LED.
  

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


// Constants for LED connections 
const int RED_LED_PIN = 9;    // Red LED Pin
const int GREEN_LED_PIN = 10; // Green LED Pin
const int BLUE_LED_PIN = 11;  // Blue LED Pin

const int SENSOR_PIN = 0;      // Analog input pin

// Global PWM brightness values for the RGB LED.
// These are global so both loop() and setRGB() can see them.

int redValue, greenValue, blueValue;


void setup()
{
  // No need for any code here
  // analogWrite() sets up the pins as outputs
}


void loop()
{
  int sensorValue;
  
  sensorValue = analogRead(SENSOR_PIN); // Read the voltage from the softpot (0-1023)

  setRGB(sensorValue); 	//Set a RGB LED to a position on the "rainbow" of all colors
						//based on the sensorValue
}

void setRGB(int RGBposition)
{
  int mapRGB1, mapRGB2, constrained1, constrained2;
 
  mapRGB1 = map(RGBposition, 0, 341, 255, 0);
  constrained1 = constrain(mapRGB1, 0, 255);

  mapRGB2 = map(RGBposition, 682, 1023, 0, 255);
  constrained2 = constrain(mapRGB2, 0, 255);

  redValue = constrained1 + constrained2; //Create the red peak
  
  //Create the green peak
  //Note that we are nesting functions (which requires fewer variables)
  
  greenValue = constrain(map(RGBposition, 0, 341, 0, 255), 0, 255)
             - constrain(map(RGBposition, 341, 682, 0,255), 0, 255);

  //Create the blue peak          
  blueValue = constrain(map(RGBposition, 341, 682, 0, 255), 0, 255)
            - constrain(map(RGBposition, 682, 1023, 0, 255), 0, 255);

 // Display the new computed "rainbow" color
  analogWrite(RED_LED_PIN, redValue);
  analogWrite(GREEN_LED_PIN, greenValue);
  analogWrite(BLUE_LED_PIN, blueValue);

  }

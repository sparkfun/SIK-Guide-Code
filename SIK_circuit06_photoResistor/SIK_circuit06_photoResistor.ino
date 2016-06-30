/******************************************************************
 * SparkFun Inventor's Kit
 * Example sketch 06
 * 
 * PHOTO RESISTOR
 * 
 * Use a photoresistor (light sensor) to control the brightness
 * of a LED.
 * 
 * This sketch was written by SparkFun Electronics,
 * with lots of help from the Arduino community.
 * This code is completely free for any use.
 * Visit http://learn.sparkfun.com/products/2 for SIK information.
 * Visit http://www.arduino.cc to learn about the Arduino.
 * 
 * Version 2.0 6/2012 MDG
 * Version 2.1 9/2014 BCH
/*****************************************************************/

// As usual, we'll create constants to name the pins we're using.
// This will make it easier to follow the code below.

const int sensorPin = 0;
const int ledPin = 9;

// We'll also set up some global variables for the light level:
int lightLevel;
int calibratedlightLevel; // used to store the scaled / calibrated lightLevel
int maxThreshold = 0;     // used for setting the "max" light level
int minThreshold = 1023;   // used for setting the "min" light level

void setup()
{
  pinMode(ledPin, OUTPUT);    // Set up the LED pin to be an output.
  Serial.begin(9600);
}

void loop()
{
  lightLevel = analogRead(sensorPin);  // reads the voltage on the sensorPin
  Serial.print(lightLevel);
  //autoRange();  // autoRanges the min / max values you see in your room.

  calibratedlightLevel = map(lightLevel, 0, 1023, 0, 255);  // scale the lightLevel from 0 - 1023 range to 0 - 255 range.
                                                  // the map() function applies a linear scale / offset.
                                                  // map(inputValue, fromMin, fromMax, toMin, toMax);
  Serial.print("\t"); 		  // tab character
  Serial.print(calibratedlightLevel);   // println prints an CRLF at the end (creates a new line after)

  analogWrite(ledPin, calibratedlightLevel);    // set the led level based on the input lightLevel.
}
/******************************************************************
 * void autoRange()
 * 
 * This function sets a minThreshold and maxThreshold value for the
 * light levels in your setting. Move your hand / light source / etc
 * so that your light sensor sees a full range of values. This will
 * "autoCalibrate" to your range of input values.
/*****************************************************************/

void autoRange()
{
  if (lightLevel < minThreshold)  // minThreshold was initialized to 1023 -- so, if it's less, reset the threshold level.
    minThreshold = lightLevel;

  if (lightLevel > maxThreshold)  // maxThreshold was initialized to 0 -- so, if it's bigger, reset the threshold level.
    maxThreshold = lightLevel;

  // Once we have the highest and lowest values, we can stick them
  // directly into the map() function.
  // 
  // This function must run a few times to get a good range of bright and dark values in order to work.

  lightLevel = map(lightLevel, minThreshold, maxThreshold, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
}




/* SparkFun Inventor's Kit
 Example sketch 02 -- POTENTIOMETER
 
 Measure the position of a potentiometer and use it to
 control the blink rate of an LED. Turn the knob to make
 it blink faster or slower!
 
 This sketch was written by SparkFun Electronics,
 with lots of help from the Arduino community.
 This code is completely free for any use.
 Visit http://learn.sparkfun.com/products/2 for SIK information.
 Visit http://www.arduino.cc to learn about the Arduino.
 
 Version 2.0 6/2012 MDG
 */

int sensorPin = A0;    // The potentiometer is connected to analog pin 0                  
int ledPin = 13;      // The LED is connected to digital pin 13
int sensorValue;	//We declare another integer variable to store the value of the potentiometer

void setup() // this function runs once when the sketch starts up
{
  pinMode(ledPin, OUTPUT);
}

void loop() // this function runs repeatedly after setup() finishes
{
  sensorValue = analogRead(sensorPin);    

  digitalWrite(ledPin, HIGH);     // Turn the LED on
  delay(sensorValue);             // Pause for sensorValue in milliseconds
  digitalWrite(ledPin, LOW);      // Turn the LED off
  delay(sensorValue);             // Pause for sensorValue in milliseconds
}


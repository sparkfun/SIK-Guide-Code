/******************************************************************
 * SparkFun Inventor's Kit
 * Example sketch 05 -- PUSH BUTTONS
 * 
 *   Use pushbuttons for digital input
 * 
 *   Connect one side of the pushbutton to GND, and the other
 *   side to a digital pin. When we press down on the pushbutton,
 *   the pin will be connected to GND, and therefore will be read
 *   as "LOW" by the Arduino.
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

const int button1Pin = 2;  // pushbutton 1 pin
const int button2Pin = 3;  // pushbutton 2 pin
const int ledPin =  13;    // LED pin

int button1State, button2State;  // variables to hold the pushbutton states


void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

  // Set up the LED pin to be an output:
  pinMode(ledPin, OUTPUT);      
}

void loop()
{
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // if button1 or button 2 are pressed (but not both)
  if (((button1State == LOW) && (button2State == HIGH)) || ((button1State == HIGH) && (button2State == LOW)))
  {
    digitalWrite(ledPin, HIGH);  // turn the LED on
  }
  else
  {
    digitalWrite(ledPin, LOW);  // turn the LED off
  }
}

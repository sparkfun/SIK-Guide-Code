/******************************************************************
 * SparkFun Inventor's Kit
 * Example sketch 05 -- PUSH BUTTONS (v2)
 *
 *   Use pushbuttons for digital input
 *
 *   Connect one side of the pushbutton to GND, and the other
 *   side to a digital pin. When we press down on the pushbutton,
 *   the pin will be connected to GND, and therefore will be read
 *   as "LOW" by the Arduino.
 * 
 *   This is a variation (v2) to the code in the SIK. This example shows
 *   how to create and use what is called a state-machine to increment
 *   your Arduino through several program states.
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

const int buttonPin = 2;   // pushbutton pin
const int redPin = 9;      // red LED pin
const int greenPin = 10;   // green LED pin
const int bluePin = 11;    // blue LED pin

int buttonState;    // variables to hold the pushbutton states
int progState = 0;  // progState is used as a state variable

void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(buttonPin, INPUT);

  // Set up the LED pin to be an output:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  // if button pressed, increment the state machine
  if (buttonState == LOW)
  {
    progState = progState + 1;
    if (progState > 3)
    {
      progState = 0;
    }
    // this is a while() loop. It continues to run whatever code
    // is between its { } while the statement ( ) is TRUE
    // This example, we do nothing, but wait. This ensures that we don't
    // continue to increment the state machine until the *next* button press.

    while (digitalRead(buttonPin) == LOW)
    {
      // do nothing
    }
    delay(100);  
    // Short 0.1 second delay to "de-bounce" the circuit. See what happens if 
    // you comment this line out. Test with various short or long presses of 
    // the button. Watch the sequence of colors. Is it still Red-White-Blue?
  }

  //****************************************************************//
  // This part is the state machine. It checks the state variable
  // and then does a different thing based on what state it is in.
  //****************************************************************//
  if (progState == 0)
  {
    // red
    analogWrite(9, 255);
    analogWrite(10, 0);
    analogWrite(11, 0);
  }
  else if (progState == 1)
  {
    // white
    analogWrite(9, 255);
    analogWrite(10, 255);
    analogWrite(11, 255);
  }
  else if (progState == 2)
  {
    // blue
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 255);
  }
  else if (progState == 3) // state 3
  {
    // turn off the RGB LED
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
  }
}

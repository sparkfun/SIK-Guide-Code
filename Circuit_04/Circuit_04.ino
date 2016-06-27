/******************************************************************
 * SparkFun Inventor's Kit
 * Example sketch 04 -- MULTIPLE LEDs
 * 
 *   Make eight LEDs dance. Dance LEDs, dance!
 * This sketch was written by SparkFun Electronics,
 * with lots of help from the Arduino community.
 * Visit http://learn.sparkfun.com/products/2 for SIK information.
 * Visit http://www.arduino.cc to learn about the Arduino.
 * 
 * Version 2.0 6/2012 MDG
 * Version 2.1 9/2014 BCH
/*****************************************************************/
int ledPins[] = {2,3,4,5,6,7,8,9};   // Defines an array to store the pin numbers of the 8 LEDs. 
// An array is like a list variable that can store multiple numbers.
// Arrays are referenced or "indexed" with a number in the brackets [ ]. See the example below. 

void setup()
{
  // setup all 8 pins as OUTPUT - notice that the list is "indexed" with a base of 0.
  pinMode(ledPins[0],OUTPUT);  // ledPins[0] = 2
  pinMode(ledPins[1],OUTPUT);  // ledPins[1] = 3
  pinMode(ledPins[2],OUTPUT);  // ledPins[2] = 4
  pinMode(ledPins[3],OUTPUT);  // ledPins[3] = 5
  pinMode(ledPins[4],OUTPUT);  // ledPins[4] = 6
  pinMode(ledPins[5],OUTPUT);  // ledPins[5] = 7
  pinMode(ledPins[6],OUTPUT);  // ledPins[6] = 8
  pinMode(ledPins[7],OUTPUT);  // ledPins[7] = 9
}

void loop()
{
  oneAfterAnother();  // Light up all the LEDs in turn
  
  //oneOnAtATime();         // Turn on one LED at a time,
  
  //pingPong();             // Light the LEDs middle to the edges

  //marquee();              // Chase lights like you see on signs

  //randomLED();            // Blink LEDs randomly
}

/******************************************************************
 * oneAfterAnother()
 * 
 * This function does exactly the same thing as oneAfterAnotherNoLoop(),
 * but it takes advantage of for() loops and the array to do it with
 * much less typing.
/*****************************************************************/
void oneAfterAnother()
{
  int index;
  int delayTime = 100; // milliseconds to pause between LEDs
                       // make this smaller for faster switching

  // Turn all the LEDs on:  
  for(index = 0; index <= 7; index = index + 1)  // step through index from 0 to 7
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);                
  }                                  

  // Turn all the LEDs off: 
  for(index = 7; index >= 0; index = index - 1)  // step through index from 7 to 0
  {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);
  }               
}
 
/*****************************************************************
 * oneOnAtATime()
 * 
 * This function will step through the LEDs, lighting only one at
 * a time. It turns each LED ON and then OFF before going to the 
 * next LED.
/****************************************************************/

void oneOnAtATime()
{
  int index;
  int delayTime = 100; // milliseconds to pause between LEDs
                       // make this smaller for faster switching
  
  for(index = 0; index <= 7; index = index + 1)   // step through the LEDs, from 0 to 7
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }

  for(index = 7; index >= 0; index = index - 1)   // step through the LEDs, from 7 to 0
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
}

 
/*****************************************************************
 * pingPong()
 * 
 * This function will step through the LEDs, lighting one at at 
 * time in both directions. There is no delay between the LED off
 * and turning on the next LED. This creates a smooth pattern for
 * the LED pattern.
/****************************************************************/
void pingPong()
{
  int index;
  int delayTime = 100; // milliseconds to pause between LEDs
   
  for(index = 0; index <= 7; index = index + 1)   // step through the LEDs, from 0 to 7
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
 
  for(index = 7; index >= 0; index = index - 1)   // step through the LEDs, from 7 to 0
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
}

/*****************************************************************
 * marquee()
 * 
 * This function will mimic "chase lights" like those around signs.
/****************************************************************/
void marquee()
{
  int index;
  int delayTime = 200; // milliseconds to pause between LEDs
 
  // Step through the first four LEDs
  // (We'll light up one in the lower 4 and one in the upper 4)
  
  for(index = 0; index <= 3; index++) // Step from 0 to 3
  {
    digitalWrite(ledPins[index], HIGH);    // Turn a LED on
    digitalWrite(ledPins[index+4], HIGH);  // Skip four, and turn that LED on
    delay(delayTime);                      // Pause to slow down the sequence
    digitalWrite(ledPins[index], LOW);     // Turn the LED off
    digitalWrite(ledPins[index+4], LOW);   // Skip four, and turn that LED off
  }
}

/*****************************************************************
 * randomLED()
 * 
 * This function will turn on random LEDs. Can you modify it so it
 * also lights them for random times?
/****************************************************************/
void randomLED()
{
  int index;
  int delayTime;
  
  index = random(8);	// pick a random number between 0 and 7
  delayTime = 100;
	
  digitalWrite(ledPins[index], HIGH);  // turn LED on
  delay(delayTime);                    // pause to slow down
  digitalWrite(ledPins[index], LOW);   // turn LED off
}

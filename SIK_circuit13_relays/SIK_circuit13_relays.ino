/********************************************************************
 * SparkFun Inventor's Kit
 * Example sketch 13
 * 
 * RELAYS
 * 
 * A relay is a electrically-controlled mechanical switch. It has an 
 * electro-magnetic coil that either opens or closes a switch. Because
 * it is a physical switch, a relay can turn on and off large devices
 * like BIG motors, spot lights, and lamps.
 * 
 * To create enough current to excite the electro-magnet, we need to use
 * the transistor circuit from the last example. Each time we excite the relay
 * you should hear an audible clicking sound of the switch.
 *  
 * This sketch was written by SparkFun Electronics, 
 * with lots of help from the Arduino community.
 * This code is completely free for any use.
 *
 * Visit http://learn.sparkfun.com/sik for SIK information.
 * Visit http://www.arduino.cc to learn about the Arduino.
 * 
 * Version 2.0 6/2012 MDG
 * Version 2.1 8/2014 BCH
 *******************************************************************/

const int relayPin = 2;	    // This pin drives the transistor (which drives the relay)
const int timeDelay = 1000; // delay in ms for on and off phases

// You can make timeDelay shorter, but note that relays, being
// mechanical devices, will wear out quickly if you try to drive
// them too fast.


void setup()
{
  pinMode(relayPin, OUTPUT);  // set pin as an output
}


void loop()                    
{
  digitalWrite(relayPin, HIGH);  // turn the relay on
  
  delay(timeDelay);              // wait for one second
  
  digitalWrite(relayPin, LOW);   // turn the relay off
  
  delay(timeDelay);              // wait for one second
} 


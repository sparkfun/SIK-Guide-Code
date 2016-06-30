/*****************************************************************
Hardware connections:

  Shift register:
  
    Plug in the chip so it bridges the center "canyon"
    on the breadboard.
    
    The shift register has 16 pins. They are numbered
    counterclockwise starting at the pin 1 mark (notch
    in the end of the chip). See the datasheet above
    for a diagram.

    74HC595 pin		LED pin		Arduino pin
    
    1  (QB)		LED 2 +
    2  (QC)		LED 3 +
    3  (QD)		LED 4 +
    4  (QE)		LED 5 +
    5  (QF)		LED 6 +
    6  (QG)		LED 7 +
    7  (QH)		LED 8 +
    8  (GND)				GND
    
    9  (QH*)
    10 (SRCLR*)				5V
    11 (SRCLK)				Digital 3
    12 (RCLK)				Digital 4
    13 (OE*)				GND
    14 (SER)				Digital 2
    15 (QA)		LED 1 +
    16 (VCC)				5V
  
  LEDs:
  
    After making the above connections to the positive (longer)
    legs of the LEDs, connect the negative side (short lead) of
    each LED to a 330 Ohm resistor, and connect the other side
    of each resistor to GND.
******************************************************************/

/*****************************************************************
// We're going to use the same functions we played with back
// in circuit 04, "Multiple LEDs", we've just replaced
// digitalWrite() with a new function called shiftWrite()
// (see below). We also have a new function that demonstrates
// binary counting.
******************************************************************/

/*****************************************************************
void shiftWrite()

// This function lets you make the shift register outputs
// HIGH or LOW in exactly the same way that you use digitalWrite().

// Like digitalWrite(), this function takes two parameters:

//    "desiredPin" is the shift register output pin
//    you want to affect (0-7)

//    "desiredState" is whether you want that output
//    to be HIGH or LOW

// Inside the Arduino, numbers are stored as arrays of "bits",
// each of which is a single 1 or 0 value. Because a "byte" type
// is also eight bits, we'll use a byte (which we named "data"
// at the top of this sketch) to send data to the shift register.
// If a bit in the byte is "1", the output will be HIGH. If the bit
// is "0", the output will be LOW.

// To turn the individual bits in "data" on and off, we'll use
// a new Arduino commands called bitWrite(), which can make
// individual bits in a number 1 or 0.
{
// First we'll alter the global variable "data", changing the
// desired bit to 1 or 0 using bitWrite().

// Now we'll actually send that data to the shift register.
// The shiftOut() function does all the hard work of
// manipulating the data and clock pins to move the data
// into the shift register. 

// Once the data is in the shift register, we still need to
// make it appear at the outputs. We'll toggle the state of
// the latchPin, which will signal the shift register to "latch"
// the data to the outputs. (Latch activates on the low-to
// -high transition).

******************************************************************/

/*****************************************************************
void oneAfterAnother()

// This function will light one LED, delay for delayTime, then light
// the next LED, and repeat until all the LEDs are on. It will then
// turn them off in the reverse order.

// We use a for() loop to step through turning all the LED on 
// and then off. 
******************************************************************/

/*****************************************************************
void oneOnAtATime()

// This function will light one LED, delay for delayTime, then turn
// off the LED. It will then repeat with the next LED, and cycle. 

// We use a for() loop to step through turning each LED on and then off. 
******************************************************************/

/*****************************************************************
void pingPong()

// This function will light one LED, delay for delayTime, then turn
// off the LED. It will then repeat with the next LED, and reverse 
// the pattern to LED 1. 

// We use a for() loop to step through turning each LED on and off,
// and create a "ping pong" visual effect. 
******************************************************************/

/*****************************************************************
void randomLED()

// This function turns on and off a random LED. 

// The random() function will return a semi-random number each
// time it is called. See http://arduino.cc/en/Reference/Random
// for tips on how to make random() more random.

// We then use the number returned by random() to determine which 
// LED to turn on and off. 
******************************************************************/

/*****************************************************************
void marquee()

// This function will mimic "chase lights" like those around signs.

// We use a for() loop to step through turning on every 4th LED. 
// We then wait for delayTime, turn off the group of LEDs, and
// move to the next group of every 4th LED. 

******************************************************************/

/*****************************************************************
void binaryCount()

Numbers are stored internally in the Arduino as arrays of "bits",
each of which is a 1 or 0. Just like the base-10 numbers we use
every day, The position of the bit affects the magnitude of its 
contribution to the total number:

Bit position   Contribution
0              1
1              2
2              4
3              8
4              16
5              32
6              64
7              128

To build any number from 0 to 255 from the above 8 bits, just
select the contributions you need to make. The bits will then be
1 if you use that contribution, and 0 if you don't.

This function will increment the "data" variable from 0 to 255
and repeat. When we send this value to the shift register and LEDs,
you can see the on-off pattern of the eight bits that make up the
byte. See http://www.arduino.cc/playground/Code/BitMath for more
information on binary numbers.
******************************************************************/
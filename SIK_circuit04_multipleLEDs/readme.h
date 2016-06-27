/******************************************************************
 * Hardware connections:
 * 
 * You'll need eight LEDs, and eight 330 Ohm resistors
 * (orange-orange-brown).
 * 	
 *     For each LED, connect the negative side (shorter leg)
 *     to a 330 Ohm resistor.
 *   
 *     Connect the other side of the resistors to GND.
 *   
 *     Connect the positive side (longer leg) of the LEDs
 *     to Arduino digital pins 2 through 9.
/*****************************************************************/

// In this sketch, we'll use "for() loops" to step variables from
// one value to another, and perform a set of instructions for 
// each step. For() loops are a very handy way to get numbers to
// count up or down.

// Every for() loop has three statements separated by
// semicolons (;):

//   1. Something to do before starting
//   2. A test to perform; as long as it's true, keep looping
//   3. Something to do after each loop (increase a variable)

// For the for() loop below, these are the three statements:

//   1. index = 0;    Before starting, make index = 0.
//   2. index <= 7;   If index is less or equal to 7,
//                    run the following code.
//			(When index = 8, continue with the sketch.)
//   3. index++	Putting "++" after a variable means
//                    "add one to it".
//			(You can also use "index = index + 1".)

// Every time you go through the loop, the statements following
// the for() (within the brackets) will run.

// When the test in statement 2 is finally false, the sketch
// will continue.


// Here we'll use a for() loop to initialize all the LED pins
// to outputs. This is much easier than writing eight separate
// statements to do the same thing.

// This for() loop will make index = 0, then run the pinMode()
// statement within the brackets. It will then do the same thing
// for index = 2, index = 3, etc. all the way to index = 7.


  // This loop() calls functions that we've written further below.
  // We've disabled some of these by commenting them out (putting
  // "//" in front of them). To try different LED displays, remove
  // the "//" in front of the ones you'd like to run, and add "//"
  // in front of those you don't to comment out (and disable) those
  // lines.



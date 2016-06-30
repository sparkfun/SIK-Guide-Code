/******************************************************************
 * Hardware connections:
 * 
 * Pushbuttons:
 * 
 * Pushbuttons have two contacts that are connected if you're
 * pushing the button, and disconnected if you're not.
 * 
 * The pushbuttons we're using have four pins, but two pairs
 * of these are connected together. The easiest way to hook up
 * the pushbutton is to connect two wires to any opposite corners.
 * 
 * Connect any pin on pushbutton 1 to ground (GND).
 * Connect the opposite diagonal pin of the pushbutton to
 * digital pin 2.
 * 
 * Connect any pin on pushbutton 2 to ground (GND).
 * Connect the opposite diagonal pin of the pushbutton to
 * digital pin 3.
 * 
 * Also connect 10K resistors (brown/black/red) between
 * digital pins 2 and 3 and 5V. These are called "pullup"
 * resistors. They ensure that the input pin will be either
 * 5V (unpushed) or GND (pushed), and not somewhere in between.
 * (Remember that unlike analog inputs, digital inputs are only
 * HIGH or LOW.)
 * 
 * LED:
 * 
 * Most Arduinos, including the Uno, already have an LED
 * and resistor connected to pin 13, so you don't need any
 * additional circuitry.
 * 
 * But if you'd like to connect a second LED to pin 13,
 * connect the positive side of your LED to Arduino digital pin 13.
 * Connect the negative side of your LED to a 330 Ohm resistor, and
 * connect the other side of the resistor to ground.
 * 
*****************************************************************/

/******************************************************************
We being this sketch the same as our previous push button example
by defining the button pins and setting the pins as outputs.

The push buttons act as inputs to change the state of the system. 
On each loop, the Arduino checks the whether a button is being pushed. 
If so, the state is incremented by 1, and the Arduino changes the behavior
of the LEDs based on the value of the state variable. 
*****************************************************************/
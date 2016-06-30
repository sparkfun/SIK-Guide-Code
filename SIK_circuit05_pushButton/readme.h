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
/*****************************************************************/

/******************************************************************
 * What happens when you're not pushing the button?
 * In this state, the pin is disconnected from everything, which 
 * we call "floating". What will the pin read as then, HIGH or LOW?
 * It's hard to say, because there's no solid connection to either
 * 5 Volts or GND. The pin could read as either one.
 * 
 * To deal with this issue, we connect a small (10K, or 10,000 Ohm)
 * resistance between the pin and 5 Volts. This "pullup" resistor
 * will ensure that when you're NOT pushing the button, the pin will
 * still have a weak connection to 5 Volts, and therefore read as
 * HIGH.
 * 
 *
 * (Advanced: when you get used to pullup resistors and know when
 * they're required, you can activate internal pullup resistors
 * on the ATmega processor in the Arduino. See
 * http://arduino.cc/en/Tutorial/DigitalPins for information.)
 * 
 *
 * Since a pushbutton has only two states (pushed or not pushed),
 * we've run them into digital inputs. To read an input, we'll
 * use the digitalRead() function. This function takes one
 * parameter, the pin number, and returns either HIGH (5V)
 * or LOW (GND).
 * 
 * 
 * Remember that if the button is being pressed, it will be
 * connected to GND. If the button is not being pressed,
 * the pullup resistor will connect it to 5 Volts.
 * 
 * So the state will be LOW when it is being pressed,
 * and HIGH when it is not being pressed.
 *
 * In this example, the LED turns on only when one button is pressed.
 * 
 * Let's translate that into computer code. The Arduino gives you
 * special logic functions to deal with true/false logic:
 * 
 * A == B means "EQUIVALENT". This is true if both sides are the same.
 * A && B means "AND". This is true if both sides are true.
 * A || B means "OR". This is true if either side is true.
 * !A means "NOT". This makes anything after it the opposite (true or false).
 * 
 * We can use these operators to translate the above sentences
 * into logic statements (Remember that LOW means the button is
 * being pressed)
 * 
 * "If either button is being pressed, light up the LED"
 * becomes:
 *  if ((button1State == LOW) && (button2State == HIGH)) // Only button1 is pushed, light the LED
 *  if ((button1State == HIGH) && (button2State == LOW)) // Only button2 is pushed, light the LED
 * 
 *  Combine these two with an OR (||) 
 *  if ((button1State == LOW) && (button2State == HIGH)) || ((button1State == HIGH) && (button2State == LOW)) 
 *
 * As you can see, logic operators can be combined to make complex decisions!
 *
 * Don't forget that we use = when we're assigning a value,
 * and use == when we're testing a value for equivalence.

/*****************************************************************/

/******************************************************************
 * Hardware connections:
 * ======================
 * An RGB LED is actually three LEDs (red, green, and blue) in
 * one package. When you run them at different brightnesses,
 * the red, green and blue mix to form new colors.
 * 
 * Starting at the flattened edge of the flange on the LED,
 * the pins are ordered RED, COMMON, GREEN, BLUE.
 * 
 * Connect RED to a 330 Ohm resistor. Connect the other end
 * of the resistor to digital pin 9.
 * 
 * Connect COMMON pin to GND.
 * 
 * Connect GREEN to a 330 Ohm resistor. Connect the other end
 * of the resistor to digital pin 10.
 * 
 * Connect BLUE to a 330 Ohm resistor. Connect the other end
 * of the resistor to digital pin 11.
 * 
/*****************************************************************/


/******************************************************************
 * This example shows the use of functions to simplify the code 
 * in the main loop() of your sketch.
 *
 * Functions are basically new commands that we write. This is 
 * useful to keep your code clean, easy to read, and efficient.
 * 
 * In this example, we have three new functions:
 *   mainColors(), showSpectrum(), and RGB(int color)
 * 	
 * mainColors() steps through eight colors by turning on the individual
 * LEDs (RED, BLUE, and GREEN) on and off in various combinations. This
 * function turns the LEDs full-on and full-off. If you want to generate
 * more than eight colors, you can do so by varying the brightness of the 
 * individual LEDs between full-on and full-off. 
 * 
 * The analogWrite() function lets us do this. This function lets you dim
 * an LED from full-off to full-on over 255 steps. 
 *
 * RGB(int color) - takes an input parameter, "color" and uses this in
 *   its code. A variable called "color" is passed into this function
 *   with the value of the number in parentheses.  
 * 
 * showSpectrum() steps through all the colors of the RGB LED, displaying a
 * rainbow. showSpectrum() calls RGB(int color) over and over again to do this.
 *
 *
 * ===================
 * Calling functions:
 * ===================
 * Making a call to a function means referencing or using the code. Because
 * both mainColors() and showSpectrum() both have no parameters between the 
 * parentheses, we call them with a simple line such as:
 *
 * mainColors();    or      showSpectrum();
 * 
 * RGB(int color), on the other hand, has an input parameter, "color." 
 * To call RGB, you must pass it an integer value. To use RGB to display all RED, 
 * you would write the line:
 *
 * RGB(0);     // displays all RED
 *
 * or, if you wanted to show a color in between RED and GREEN
 *
 * RGB(128);   // half way between RED and GREEN.
 * 
/*****************************************************************/
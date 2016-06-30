/**************************************************************
Hardware connections:

  Soft potentiometer:

    The soft potentiometer is the large plastic strip with three
    pins. We'll be connecting it as a voltage divider, just like
    we did with the knob-type potentiometer back in circuit #2.

    Connect the middle pin to ANALOG IN pin 0 on the Arduino.
    Connect one side to 5V.
    Connect the other side to GND.
	Also connect a 10K resistor from the middle pin to GND.

    TIP: the soft pot will only work while you're actively
    pressing on it; at other times it will "float" to random
    values. To prevent this, we've added a 10K pull-down resistor
    to the middle pin (output voltage). This will keep the output
    at zero volts when the pot is not being pressed.

  RGB LED:

    An RGB LED is actually three LEDs (red, green, and blue)
    in one package. When we run them at different brightnesses,
    they mix to form new colors.
    
    Starting at the flattened edge of the flange on the LED,
    the pins are ordered RED, COMMON, GREEN, BLUE.
    
    Connect RED to a 330 Ohm resistor.
    Connect the other end of the resistor to Arduino digital pin 9.
  
    Connect COMMON to GND.
  
    Connect GREEN through a 330 Ohm resistor.
    Connect the other end of the resistor to Arduino digital pin 10.
  
    Connect BLUE through a 330 Ohm resistor.
    Connect the other end of the resistor to Arduino digital pin 11.
**************************************************************/
// Note that the LED pins must be PWM pins, 
// which are marked with "PWM" or have a "~" symbol
// next to them on the board.
/**************************************************************
void setRGB()
// Decodes sensorValue into a position, and set a RGB LED to a 
// position on the "rainbow" of all colors.
// RGBposition should be in the range of 0 to 1023 (such as
// from an analog input).

// Here we take RGBposition and turn it into three RGB values.

// The three values are computed so that the colors mix and 
// produce a rainbow of colors across the 0-1023 input range.

// For each channel (red green blue), we're creating a "peak"
// a third of the way along the 0-1023 range. By overlapping
// these peaks with each other, the colors are mixed together.
// This is most easily shown with a diagram:
// http://sfecdn.s3.amazonaws.com/education/SIK/SchematicImages/Misc/RGB_function.jpg

// Create the red peak, which is centered at 0.
// (Because it's centered at 0, half is after 0, and half
// is before 1023):

// Create the green peak, which is centered at 341
// (one-third of the way to 1023):

// Note that on the green and blue peaks, 
// we've nested the functions by putting the map() function inside 
// the constrain() function. This can make your
// code more compact, and requires fewer variables.

// Create the blue peak, which is centered at 682
// (two-thirds of the way to 1023).

// Now we have all three brightnesses,
// we just need to display the computed color.

**************************************************************/
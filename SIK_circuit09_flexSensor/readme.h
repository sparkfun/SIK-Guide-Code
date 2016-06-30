/***********************************************************
Hardware connections:

  Flex sensor:

    The flex sensor is the plastic strip with black stripes.
    It senses bending away from the striped side.
    
    The flex sensor has two pins, and since it's a resistor,
    the pins are interchangeable.
    
    Connect one of the pins to ANALOG IN pin 0 on the Arduino.
    Connect the same pin, through a 10K Ohm resistor (brown
    black orange) to 5V.
    Connect the other pin to GND.

  Servo:
  
    The servo has a cable attached to it with three wires.
    Because the cable ends in a socket, you can use jumper wires
    to connect between the Arduino and the servo. Just plug the
    jumper wires directly into the socket.
    
    Connect the RED wire (power) to 5 Volts (5V)
    Connect the WHITE wire (signal) to digital pin 9
    Connect the BLACK wire (ground) to ground (GND)
  
    Note that servos can use a lot of power, which can cause your
    Arduino to reset or behave erratically. If you're using large
    servos or many of them, it's best to provide them with their
    own separate 5V supply. See this Arduino Forum thread for info:
    http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1239464763
*****************************************************************/

// Use the serial monitor window to help debug our sketch, and set 
// the baud rate to 9600 bps. 

//The flex sensor will output a value on the analog pin, based on the degree 
// of its flex. Because the voltage divider circuit only returns a portion
// of the 0-1023 range of analogRead(), we'll map() that range
// to the servo's range of 0 to 180 degrees. The flex sensors
// we use are usually in the 600-900 range.

// Because every flex sensor has a slightly different resistance,
// the 600-900 range may not exactly cover the flex sensor's
// output. To help tune our program, we'll use the serial port to
// print out our values to the serial monitor window.

// Note that all of the serial prints are "print" except for the
// last line which is "println". This puts everything on the
// same line, then sends a final carriage return to move to
// the next line.

// After you upload the sketch, turn on the serial monitor
// (the magnifying-glass icon to the right of the icon bar).
// You'll be able to see the sensor values. Bend the flex sensor
// and note its minimum and maximum values. If you replace the
// 600 and 900 in the map() function above, you'll exactly match
// the flex sensor's range with the servo's range.

// Make sure you don't bend the flex sensor too sharply, or you could
// permanently damage the sensor. No right angle bends! 
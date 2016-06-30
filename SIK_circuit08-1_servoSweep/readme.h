/**********************************************************
Hardware connections:

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
**********************************************************/

// If we had to write a sketch to control a servo from scratch,
// it would be a lot of work. Fortunately, others have done the
// hard work for you. We're going to include a "library"
// that has the functions needed to drive servos.

// A library is an set of additional functions you can add to
// your sketch. Numerous libraries are available for many uses,
// see http://arduino.cc/en/Reference/Libraries for information
// on the standard libraries, and Google for others. When you're
// using a new part, chances are someone has written a library
// for it.

// Once you "include" a library, you'll have access to those
// functions. You can find a list of the functions in the servo
// library at: http://arduino.cc/en/Reference/Servo
// Most libraries also have example sketches you can load from
// the "file/examples" menu.

// We create a servo "object", called servo1. You should
// create one of these for each servo you want to control. 
// You can control a maximum of twelve servos on the Uno 
// using this library. (Other servo libraries may let you
// control more). Note that this library disables PWM on
// pins 9 and 10!

// We "attach" the servo1 object to digital pin 9.
// If you want to control more than one servo, attach more
// servo objects to the desired pins (must be digital).

// Attach tells the Arduino to begin sending control signals
// to the servo. Servos require a continuous stream of control
// signals, even if you're not currently moving them.
// While the servo is being controlled, it will hold its 
// current position with some force. If you ever want to
// release the servo (allowing it to be turned by hand),
// you can call servo1.detach().
/**********************************************************
// Change position at a slower speed:

// To slow down the servo's motion, we use a for() loop
// to give it a bunch of intermediate positions, with 20ms
// delays between them. You can change the step size to make 
// the servo slow down or speed up. Note that the servo can't
// move faster than its full speed, and you won't be able
// to update it any faster than every 20ms.
**********************************************************/
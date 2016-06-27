/*
SparkFun Inventor's Kit
Example sketch 08-2

SINGLE SERVO

  Sweep a servo back and forth through its full range of motion.

  A "servo", short for servomotor, is a motor that includes 
  feedback circuitry that allows it to be commanded to move to
  specific positions. This one is very small, but larger servos
  are used extensively in robotics to control mechanical arms,
  hands, etc. You could use it to make a (tiny) robot arm,
  aircraft control surface, or anywhere something needs to be
  moved to specific positions.

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

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


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

#include <Servo.h>  // servo library

// Once you "include" a library, you'll have access to those
// functions. You can find a list of the functions in the servo
// library at: http://arduino.cc/en/Reference/Servo
// Most libraries also have example sketches you can load from
// the "file/examples" menu.

// Now we'll create a servo "object", called myservo. You should
// create one of these for each servo you want to control. 
// You can control a maximum of twelve servos on the Uno 
// using this library. (Other servo libraries may let you
// control more). Note that this library disables PWM on
// pins 9 and 10!

Servo servo1;  // servo control object

int angle; 

void setup()
{
  // We'll now "attach" the servo1 object to digital pin 9.
  // If you want to control more than one servo, attach more
  // servo objects to the desired pins (must be digital).

  // Attach tells the Arduino to begin sending control signals
  // to the servo. Servos require a continuous stream of control
  // signals, even if you're not currently moving them.
  // While the servo is being controlled, it will hold its 
  // current position with some force. If you ever want to
  // release the servo (allowing it to be turned by hand),
  // you can call servo1.detach().

  servo1.attach(9, 900, 2100);
  Serial.begin(9600);
}


void loop()
{
  serialServo();  
}


void serialServo()
{
  int speed;
  
  Serial.println("Type an angle (0-180) into the box above,");
  Serial.println("then click [send] or press [return]");
  Serial.println();  // Print a blank line

  // In order to type out the above message only once,
  // we'll run the rest of this function in an infinite loop:

  while(true)  // "true" is always true, so this will loop forever.
  {
    // First we check to see if incoming data is available:
  
    while (Serial.available() > 0)
    {
      // If it is, we'll use parseInt() to pull out any numbers:     
      angle = Serial.parseInt();
  
      // Because analogWrite() only works with numbers from
      // 0 to 255, we'll be sure the input is in that range:
  
      angle = constrain(angle, 0, 180);
      
      // We'll print out a message to let you know that the
      // number was received:
      
      Serial.print("Setting angle to ");
      Serial.println(angle);
  
      // And finally, we'll set the speed of the motor!
      
      servo1.write(angle);
    }
  }
}




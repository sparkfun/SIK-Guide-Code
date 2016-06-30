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

// In this sketch, we use serial input to control the servo's 
// position. 

// The Arduino accepts serial input for an new position from the user.
// Because users could input something additional besides a number, 
// we must parse out the numerical values using parseInt(). 
 
// Because the servo can only work at angles between 0 and 180, we
// constrain the input value using constrain() and then write the 
// mapped value as the servo's new position. 

// The Arduino will print out the new angle over the serial monitor 
// and move the servo. Once the servo is in its new position, the Arduino
// waits for the user to input a new servo angle. 
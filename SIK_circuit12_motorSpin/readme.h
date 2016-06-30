/*******************************************************************
 * Use a transistor to spin a motor at different speeds.
 * We'll also show you how to input data from the serial port
 * (see the serialSpeed() function below).
 * 
 * Motors are the basis for thousands of things in our daily lives,
 * and the Arduino can control them. Here we'll use pulse-width
 * modulation (PWM) to vary the speed of a motor.
 * 
 * The Arduino pins are strong enough to light small LEDs (up to
 * 40 milliAmps), but they're not strong enough to run motors and
 * other power-hungry parts. (This motor needs 50-100mA).
 * Because the motor needs more current than an Arduino pin can
 * provide, we'll use a transistor to do the heavy lifting.
 * A transistor is a solid-state switch. When we give it a small
 * amount of current, it can switch a much larger current.
 * The transistors in your kit (BC337) can switch up to 800mA.
 *
 * **NOTE:** Do not attempt to draw more than 400mA through your 
 * Arduino when powered only via USB. USB ports can only source up  
 * to 500mA and attempting to draw more than that can lead to the 
 * Arduino malfunctioning or other hardware issues. 
 * 
 * You can turn a transistor on and off using the digitalWrite()
 * function, but you can also use the analogWrite() function to
 * vary the speed of the motor. The analogWrite() function pulses
 * a pin, varying the width of the pulse from 0% to 100%. We call
 * this technique "PWM", for "Pulse-Width Modulation".
 * 
 * One thing to keep in mind is that when you lower the speed of
 * a motor using PWM, you're also reducing the torque (strength)
 * of the motor. For PWM values below 50 or so, the motor won't have
 * enough torque to start spinning. It will start spinning when you
 * raise the speed a bit.
 ******************************************************************/
  
/******************************************************************* 
 * Hardware connections:
 * 
 * Transistor:
 * 
 * The transistor has three pins. Looking at the flat side with the
 * pins down, the order is COLLECTOR, BASE, EMITTER.
 * 
 * Connect the black wire on the motor to the
 * COLLECTOR pin on the transistor.
 * 
 * Connect the BASE pin through a 330 Ohm resistor to
 * digital pin 9.
 * 
 * Connect the EMITTER pin to GND.
 * 
 * Motor:
 * 
 * You've already connected the black wire on the motor to the
 * COLLECTOR pin on the transistor.
 * 
 * Connect the other (red) wire on the motor to 5V.
 * 
 * Flyback diode:
 * 
 * When the motor is spinning and suddenly turned off, the
 * magnetic field inside it collapses, generating a voltage spike.
 * This can damage the transistor. To prevent this, we use a
 * "flyback diode", which diverts the voltage spike "around" the
 * transistor.
 * 
 * Connect the side of the diode with the band (cathode) to 5V
 * Connect the other side of the diode (anode) to the black wire
 * on the motor.
 
 * Keep in mind that if the diode is inserted backwards, the motor
 * may appear to function normally. However, this can lead to other 
 * issues with your circuit, so double check this! 
 ******************************************************************/
 
/******************************************************************* 
 void speedUpandDown()
 
// This function accelerates the motor to full speed,
// then decelerates back down to a stop. We use a for() loop to increase
// and then decrease the speed. 
 ******************************************************************/
  
/******************************************************************* 
void serialSpeed()

// This function allows the user to declare a motor speed from 0-255. 
// The speed is input via the Serial terminal. 
******************************************************************/
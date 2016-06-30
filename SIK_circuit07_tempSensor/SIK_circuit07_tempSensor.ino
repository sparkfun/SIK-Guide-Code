/******************************************************************
 SparkFun Inventor's Kit
 Example sketch 07 - TEMPERATURE SENSOR

  Use the "serial monitor" window to read a temperature sensor.

  The TMP36 is an easy-to-use temperature sensor that outputs
  a voltage that's proportional to the ambient temperature.
  You can use it for all kinds of automation tasks where you'd
  like to know or control the temperature of something.

  More information on the sensor is available in the datasheet:
  http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Sensors/Temp/TMP35_36_37.pdf

  Even more exciting, we'll start using the Arduino's serial port
  to send data back to your main computer! Up until now, we've
  been limited to using simple LEDs for output. We'll see that
  the Arduino can also easily output all kinds of text and data.

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
******************************************************************/


// We'll use analog input 0 to measure the temperature sensor's
// signal pin.

const int temperaturePin = A0;


void setup()
{

	Serial.begin(9600); //Initialize serial port & set baud rate to 9600 bits per second (bps)
}


void loop()
{


	float voltage, degreesC, degreesF; //Declare 3 floating point variables

	voltage = getVoltage(temperaturePin); //Measure the voltage at the analog pin

	degreesC = (voltage - 0.5) * 100.0; // Convert the voltage to degrees Celsius

	degreesF = degreesC * (9.0 / 5.0) + 32.0; //Convert degrees Celsius to Fahrenheit
	
	//Now print to the Serial monitor. Remember the baud must be 9600 on your monitor!
	// These statements will print lines of data like this:
	// "voltage: 0.73 deg C: 22.75 deg F: 72.96"
	
	Serial.print("voltage: ");
	Serial.print(voltage);
	Serial.print("  deg C: ");
	Serial.print(degreesC);
	Serial.print("  deg F: ");
	Serial.println(degreesF);

	delay(1000); // repeat once per second (change as you wish!)
}


float getVoltage(int pin) 	//Function to read and return
							//floating-point value (true voltage)
							//on analog pin 
{

	return (analogRead(pin) * 0.004882814);	
	// This equation converts the 0 to 1023 value that analogRead()
	// returns, into a 0.0 to 5.0 value that is the true voltage
	// being read at that pin.
}

// Other things to try with this code:

//   Turn on an LED if the temperature is above or below a value.

//   Read that threshold value from a potentiometer - now you've
//   created a thermostat!


/*
SparkFun Inventor’s Kit
Circuit 1D-RGB Nightlight

Turns an RGB LED on or off based on the light level read by a photoresistor.
Change colors by turning the potentiometer.

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
 */

int photoresistor = A0;          //variable for storing the photoresistor value
int potentiometer = A1;          //variable for storing the photoresistor value
int threshold = 700;            //if the photoresistor reading is lower than this value the light wil turn on

//LEDs are connected to these pins
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup() {
  Serial.begin(9600);           //start a serial connection with the computer

  //set the LED pins to output
  pinMode(RedPin,OUTPUT);
  pinMode(GreenPin,OUTPUT);
  pinMode(BluePin,OUTPUT);
}

void loop() {
  
  photoresistor = analogRead(A0);         //read the value of the photoresistor
  potentiometer = analogRead(A1);

  Serial.print("Photoresistor value:");
  Serial.print(photoresistor);          //print the photoresistor value to the serial monitor
  Serial.print("  Potentiometer value:");
  Serial.println(potentiometer);          //print the photoresistor value to the serial monitor
  
  if(photoresistor < threshold){          //if it's dark (the photoresistor value is below the threshold) turn the LED on
    //These nested if staments check for a variety of ranges and 
    //call different functions based on the current potentiometer value.
    //Those functions are found at the bottom of the sketch. 
    if(potentiometer > 0 && potentiometer <= 150)
      red();
    if(potentiometer > 150 && potentiometer <= 300)
      orange();
    if(potentiometer > 300 && potentiometer <= 450)
      yellow(); 
    if(potentiometer > 450 && potentiometer <= 600)
      green();
    if(potentiometer > 600 && potentiometer <= 750)
      cyan();
    if(potentiometer > 750 && potentiometer <= 900)
      blue(); 
    if(potentiometer > 900)
      magenta();  
  } 
  else {                                //if it isn't dark turn the LED off
    
    turnOff();                            //call the turn off function
    
  }  
  
  delay(100);                             //short delay so that the printout is easier to read
}

void red (){
    
    //set the LED pins to values that make red    
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 0);
}
void orange (){
    
    //set the LED pins to values that make orange
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 50);
    analogWrite(BluePin, 0);
}
void yellow (){
    
    //set the LED pins to values that make yellow
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 100);
    analogWrite(BluePin, 0);
}
void green (){
    
    //set the LED pins to values that make green    
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 100);
    analogWrite(BluePin, 0);
}
void cyan (){
    
    //set the LED pins to values that make cyan    
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 100);
    analogWrite(BluePin, 100);
}
void blue (){
    
    //set the LED pins to values that make blue
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 100);
}
void magenta (){
    
    //set the LED pins to values that make magenta   
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 100);
}
void turnOff (){
  
    //set all three LED pins to 0 or OFF
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 0);
}


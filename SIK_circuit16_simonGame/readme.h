/*****************************************************************
Hardware connections:

Buzzer: 
	Connect the positive leg (+) to pin 4 of the Arduino.
	Connect the other leg to pin 7 of the Arduino.
	
LEDs:
	Connect the negative (shorter) leg of each LED to GND. 
	
	Yellow LED: 
		Connect the positive (longer leg) to a 330 Ohm resistor. 
		Connect the other side of the resistor to pin 5 on the
		Arduino.
		
	Blue LED: 
		Connect the positive (longer leg) to a 330 Ohm resistor. 
		Connect the other side of the resistor to pin 13 on the
		Arduino.
	Green LED:
		Connect the positive (longer leg) to a 330 Ohm resistor. 
		Connect the other side of the resistor to pin 3 on the
		Arduino.
	Red LED: 
		Connect the positive (longer leg) to a 330 Ohm resistor. 
		Connect the other side of the resistor to pin 2 on the
		Arduino.

Buttons: 
	Button Red:	
		Connect any pin on the red pushbutton to ground (GND).
		Connect the opposite diagonal pin of the pushbutton to
		digital pin 2
	Button Green:	
		Connect any pin on the green pushbutton to ground (GND).
		Connect the opposite diagonal pin of the pushbutton to
		digital pin 2
	Button Yellow:	
		Connect any pin on  the yellow pushbutton  to ground (GND).
		Connect the opposite diagonal pin of the pushbutton to
		digital pin 2
	Button Blue:	
		Connect any pin on the blue pushbutton  to ground (GND).
		Connect the opposite diagonal pin of the pushbutton to
		digital pin 2
******************************************************************/

/*****************************************************************
How to Play:

Once the circuit is powered, the buzzer will beep a few times, 
and all four LEDs should begin blinking. The game begins once you
press any of the four buttons. 

Once the game has started, a random LED will blink. Press the button 
associated with that color LED to replicate the pattern. With a 
successful guess, the pattern will repeat, this time adding another
random LED. The player is to follow the pattern for as long as possible, 
with each successful guess resulting in an additional layer of complexity 
added to the original pattern. 

Game Modes:

There are three modes available.
 
* Memory - 	This mode starts by default, and is the classic Simon game.

* Battle - 	This mode starts if the green button is held down on power up, 
			and allows two players to battle.
			
			A player begins by pressing a button then handing it to the other player
			That player repeats the button and adds one, then passes back.
			This function returns when someone loses
			
* BeeGees - This mode starts if the yellow button is held down on power up. 

******************************************************************/
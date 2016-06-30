/***************************************************************
 *  The buzzer in your Inventor's Kit is an electromechanical
 * component you can use to make noise. Inside the buzzer is a
 * coil of wire and a small magnet. When current flows through 
 * the coil, it becomes magnetized and pulls towards the magnet,
 * creating a tiny "click". When you do this thousands of times
 * per second, you create tones.
 * 
 * The Arduino has a built-in command called tone() which clicks
 * the buzzer at a certain frequency. This sketch knows the
 * frequencies of the common notes, allowing you to create songs.
 * We're never going to let you down!
 **************************************************************/

 /**************************************************************** 
 * Hardware connections:
 * 
 * The buzzer has two pins. One is positive and one is negative.
 * The postitive pin is marked by a "+" symbol on both the top
 * and bottom of the buzzer.
 * 
 * Connect the positive pin to Arduino digital pin 9.
 * (Note that this must be a PWM pin.)
 * Connect the negative pin to GND.
 * 
 * Tip: if the buzzer doesn't fit into the breadboard easily,
 * try rotating it slightly to fit into diagonal holes.
 * 
 **************************************************************/

/*****************************************************************
 * This sketch uses the tone() command to play notes.
 * 
 * Usage: tone([pin], [frequency]);
 * 
 * note  frequency
 * c     262 Hz
 * d     294 Hz
 * e     330 Hz
 * f     349 Hz
 * g     392 Hz
 * a     440 Hz
 * b     494 Hz
 * C     523 Hz
 * 
 * Other useful commands: noTone([pin]); and delay([time_ms]);
 * 
 * For more information, see http://arduino.cc/en/Tutorial/Tone
 ****************************************************************/

// In this sketch, we introduce an array or a list. Here is an array called notes[] that is
// an array of individual characters. Each character is designated by a ' ' and separated
// by commas. The spaces ' ' represent a rest note.

/***************************************************************** 
frequency() 
// This is a specially written function takes a note as a character (a-g), 
// and returns the corresponding frequency in Hz for the tone() function.

// The char_names and frequencies arrays hold the note characters and their
// corresponding frequencies. The last "C" note is uppercase
// to separate it from the first lowercase "c". If you want to
// add more notes, you'll need to use unique characters.

// For the "char" (character) type, we put single characters
// in single quotes.

 ****************************************************************/

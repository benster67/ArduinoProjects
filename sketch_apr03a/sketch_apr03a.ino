#include <Keyboard.h>



/*
 Keyboard Message test

 For the Arduino Leonardo and Micro.

 Sends a text string when a button is pressed.

 The circuit:
 * pushbutton attached from pin 4 to +5V
 * 10-kilohm resistor attached from pin 4 to ground

 created 24 Oct 2011
 modified 27 Mar 2012
 by Tom Igoe
 modified 11 Nov 2013
 by Scott Fitzgerald

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/KeyboardMessage
 */

/*You pressed the button 1 times.*/

const int buttonPin = 4;  
const int buttonPin2 = 8;
int 
// input pin for pushbutton
int previousButtonState = HIGH;
int previousButtonState2 = HIGH;// for checking the state of a pushButton
int counter = 0;                  // button push counter

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
  if ((buttonState != previousButtonState)
      // and it's currently pressed:
      && (buttonState == HIGH)) {
    // increment the button counter
    counter++;
    // type out a message
    Keyboard.print("You pressed the button ");
    Keyboard.print(counter);
    Keyboard.println(" times.");

    int buttonState2 = digitalRead(buttonPin2);
    if ((buttonState2 != previousButtonState2)) {
    counter++;
    // type out a message
    Keyboard.print("You pressed the second BUTTON");
    Keyboard.print(counter);
    Keyboard.println(" times.");
    
  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState;
  previousButtonState2 = butttonState2;
}

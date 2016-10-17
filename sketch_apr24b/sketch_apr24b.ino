#include <Keyboard.h>

#include <HID.h>



const int buttonPin = 2;
const int buttonPin1 = 3;
const int buttonPin2 = 4;
const int buttonPin3 = 5;
const int buttonPin4 = 6;
const int buttonPin5 = 7;
const int buttonPin6 = 8;
const int buttonPin7 = 9;
const int buttonPin8 = 10;
const int buttonPin9 = 11;
const int buttonPin10 = 12;
const int buttonPin11 = 13;
const int buttonPin12 = A0;
const int buttonPin13 = A1;
const int buttonPin14 = A2;
const int buttonPin15 = A3;

int previousButtonState = LOW;
int previousButtonState1 = LOW;
int previousButtonState2 = LOW;
int previousButtonState3 = LOW;
int previousButtonState4 = LOW;
int previousButtonState5 = LOW;
int previousButtonState6 = LOW;
int previousButtonState7 = LOW;
int previousButtonState8 = LOW;
int previousButtonState9 = LOW;
int previousButtonState10 = LOW;
int previousButtonState11 = LOW;
int previousButtonState12 = LOW;
int previousButtonState13 = LOW;
int previousButtonState14 = LOW;
int previousButtonState15 = LOW;


void setup() {
        pinMode(buttonPin, INPUT);
        pinMode(buttonPin1, INPUT);
        pinMode(buttonPin2, INPUT);
        pinMode(buttonPin3, INPUT);
        pinMode(buttonPin4, INPUT);
        pinMode(buttonPin5, INPUT);
        pinMode(buttonPin6, INPUT);
        pinMode(buttonPin7, INPUT);
        pinMode(buttonPin8, INPUT);
        pinMode(buttonPin9, INPUT);
        pinMode(buttonPin10, INPUT);
        pinMode(buttonPin11, INPUT);
        pinMode(buttonPin12, INPUT);
        pinMode(buttonPin13, INPUT);
        pinMode(buttonPin14, INPUT);
        pinMode(buttonPin15, INPUT);
        Serial.begin(9600);

}


void loop() {
        int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
  if ((buttonState != previousButtonState) 
      // and it's currently pressed:
      && (buttonState == HIGH)) {
                Keyboard.begin();
                Keyboard.print("1a1");
                Keyboard.end();
                delay (1500);
                Serial.println(buttonState);
        }
        else {
          goto button2;
        }

        button2: int buttonState2 = digitalRead(buttonPin1);
        if ((buttonState2 != previousButtonState1)
        && (buttonState2 == HIGH)) {
          Keyboard.begin();
                Keyboard.print("2a2");
                Keyboard.end();
                delay (1500);
                Serial.println(buttonState2);
        }
        else {
          goto button3;
          }

        button3: int buttonState3 = digitalRead(buttonPin2);
        if ((buttonState3 != previousButtonState2)
        && (buttonState3 == HIGH)) {
          Keyboard.begin();
                Keyboard.print("3a3");
                Keyboard.end();
                delay (1500);
                Serial.println(buttonState3);
        }
        else {
          goto button4;
          }

        button4: int buttonState4 = digitalRead(buttonPin2);
        if ((buttonState4 != previousButtonState3)
        && (buttonState4 == HIGH)) {
          Keyboard.begin();
                Keyboard.print("4a4");
                Keyboard.end();
                delay (1500);
                Serial.println(buttonState4);
        }
        else {
          goto button5;
          }

        button5: int buttonState5 = digitalRead(buttonPin3);
        if ((buttonState5 != previousButtonState4)
        && (buttonState5 == HIGH)) {
          Keyboard.begin();
                Keyboard.print("5a5");
                Keyboard.end();
                delay (1500);
                Serial.println(buttonState5);
        }
        else {
          goto button6;
          }

        button6: int buttonState6 = digitalRead(buttonPin4);
        if ((buttonState6 != previousButtonState5)
        && (buttonState6 == HIGH)) {
          Keyboard.begin();
                Keyboard.print("6a6");
                Keyboard.end();
                delay (1500);
                Serial.println(buttonState6);
        }
        else {
          goto button7;
          }

        button7: ;
}
/* 6a66a66a66a66a66a66a66a66a6a56a61a12a23a31a12a25a53a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a23a34a45a56a61a12a3a34a45a51a12a23a34a44a45a5
 */  
 

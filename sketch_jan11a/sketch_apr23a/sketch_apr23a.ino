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

int previousButtonState = HIGH;
int previousButtonState1 = HIGH;
int previousButtonState2 = HIGH;
int previousButtonState3 = HIGH;
int previousButtonState4 = HIGH;
int previousButtonState5 = HIGH;
int previousButtonState6 = HIGH;
int previousButtonState7 = HIGH;
int previousButtonState8 = HIGH;
int previousButtonState9 = HIGH;
int previousButtonState10 = HIGH;
int previousButtonState11 = HIGH;
int previousButtonState12 = HIGH;
int previousButtonState13 = HIGH;
int previousButtonState14 = HIGH;
int previousButtonState15 = HIGH;


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
        Keyboard.begin();

}


void loop() {
        int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
  if ((buttonState != previousButtonState);
      // and it's currently pressed:
      && (buttonState == HIGH)) {
                Keyboard.print("1a1");
        }
        else ({goto button2});

        button2: int buttonState2 = digitalRead(buttonPin1);
        if ((buttonState2 != previousButtonState1);
        && (buttonState2 == HIGH)) {
                Keyboard.print("2a2")
        }
        else ({goto button3});

        button3: int buttonState3 = digitalRead(buttonPin2);
        if ((buttonState3 != previousButtonState2);
        && (buttonState3 == HIGH)) {
                Keyboard.print("3a3");
        }
        else ({goto button4});

        button4: int buttonState4 = digitalRead(buttonPin2);
        if ((buttonState4 != previousButtonState3);
        && (buttonState4 == HIGH)) {
                Keyboard.print("4a4");
        }
        else ({goto button5});

        button5: int buttonState5 = digitalRead(buttonPin3);
        if ((buttonState5 != previousButtonState4);
        && (buttonState5 == HIGH)) {
                Keyboard.print("5a5");
        }
        else ({goto button6})

        button6: int buttonState6 = digitalRead(buttonPin4);
        if ((buttonState6 != previousButtonState5);
        && (buttonState6 == HIGH)) {
                Keyboard.print("6a6");
        }
        else ({goto button7});

        button7:
}

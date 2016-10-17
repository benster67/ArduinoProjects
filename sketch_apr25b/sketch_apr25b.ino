// Gozer 4/16/2016
// larson scanner code with logic and interrupts
// for a "catch the led" game

//debounce and interrupt variables
const int buttonInterrupt = 0;  // Button interrupt 0 is internally mapped to  pin 2
volatile int buttonState = LOW; //initial button state
volatile boolean triggered = false;//tells us if the interrupt has been triggered 
volatile long lastDebounceTime = 0;// the last time the interrupt was triggered
long debounceDelay = 5;//the debounce time; decrease if quick button presses are ignored

//create an array of integers that will hold the pin number
//assignments.  The array is efficient, fast and allows easy expansion
//for more leds
int leds[] = {8, 9, 10, 11, 12};

//#define The number of LEDS
//sizeof(leds)/sizeof(int) returns the total number of bytes in the array
//divided by the size of an int in bytes. This results
//in the number of elements in the array leds[].
//#define allows the code to be easily 
//reused for circuits with any number of leds.
#define NUMBER_OF_LEDS (sizeof(leds)/sizeof(int))

//declare a two dimensional array of 
//boolean values.  Each line is one element, 
//each HIGH or LOW constant is defined 
//in the Arduino library as a boolean
//value.  Using booleans is more efficient
//than using ints as they occupy less memory
//space in the Arduino board memory.

//Look at the pattern. Each line describes the state 
//of all five leds as we cycle through the loop
boolean larson[][NUMBER_OF_LEDS] = {
{ HIGH, LOW, LOW, LOW, LOW},
{ LOW, HIGH, LOW, LOW, LOW},
{ LOW, LOW, HIGH, LOW, LOW},
{ LOW, LOW, LOW, HIGH, LOW},
{ LOW, LOW, LOW, LOW, HIGH},
{ LOW, LOW, LOW, HIGH, LOW},
{ LOW, LOW, HIGH, LOW, LOW},
{ LOW, HIGH, LOW, LOW, LOW},
};

//you can try different patterns for different blink 
//effects with minimal code changes.  Try this one
//by uncommenting.
/*
boolean larson[][NUMBER_OF_LEDS] = {
{ HIGH, LOW, LOW, LOW, HIGH},
{ LOW, HIGH, LOW, HIGH, LOW},
{ LOW, LOW, HIGH, LOW, LOW},
{ LOW, HIGH, LOW, HIGH, LOW}
};

boolean you_won[][NUMBER_OF_LEDS] = {
{ HIGH, HIGH, HIGH, HIGH, HIGH},
{ LOW, LOW, LOW, LOW, LOW}
};

boolean larson[][NUMBER_OF_LEDS] = {
{ HIGH, LOW, LOW, LOW, LOW},
{ LOW, HIGH, LOW, LOW, LOW},
{ LOW, LOW, HIGH, LOW, LOW},
{ LOW, LOW, LOW, HIGH, LOW},
{ LOW, LOW, LOW, LOW, HIGH}
};
*/

//define FRAMES gives us the number of "frames"
//in the code.  If we change the above larson arrays,
//nothing else has to change in this #define or the 
//code that follows
#define FRAMES (sizeof(larson)/(sizeof(larson[0])))

void setup() {
//attach Interrupt
attachInterrupt(buttonInterrupt, Rise, RISING);

//configure all the pins for output
for (int led=0; led<NUMBER_OF_LEDS; led++) {
  pinMode(leds[led], OUTPUT);
  }
//to indicate you won!
  pinMode(13, OUTPUT);
}

void loop(){//start loop
  //nested for loop
  //for each FRAME
  for (int frame=0; frame<FRAMES; frame++) {//start for FRAMES
    //turn on/off each pin with no delay
    for (int led=0; led<NUMBER_OF_LEDS; led++) {//start for NUMBER_OF_LEDS
      digitalWrite(leds[led], larson[frame][led]);
    }//end for NUMBER_OF_LEDs
    //check if we are in the right frame to "catch"
    if ((frame == 2)||(frame == 6))
    {
        //check if the interrupt was triggered
        if(triggered){
          //yes, we won! blink onboard led 10 times
          for (int i=0; i<10; i++) {
            digitalWrite(13, HIGH);
            delay(50);
            digitalWrite(13, LOW);
            delay(50);
          }
          //better set triggered to false so we 
          //don't jump back in
          triggered = false;
        }
    }
    delay(100);//change this for a slower rate of scan
  }//end for FRAMES
 }//end loop


//Interrupt Service Routines
//Rise catches the state when the button is pressed
void Rise()
{
  long currentTime = millis();
  long difference = currentTime - lastDebounceTime;

  if (difference > debounceDelay)
  {
    lastDebounceTime = currentTime;
    if (buttonState == LOW)
    {
      buttonState = HIGH;
      ///We're in Rise, so change the interrupt to 
      //catch when we are falling
      attachInterrupt(buttonInterrupt, Fall, FALLING);
    }
    triggered = true;
  }
}

//Interrupt Service Routines
//Fall catches the state when the button is released
void Fall()
{
  long currentTime = millis();
  long difference = currentTime - lastDebounceTime;

  if (difference > debounceDelay)
  {
    lastDebounceTime = currentTime;
    if (buttonState == HIGH)
    {
      buttonState = LOW;
      ///We're in Fall, so change the interrupt to 
      //catch when we are rising
      attachInterrupt(buttonInterrupt, Rise, RISING);
    }
    triggered = false;
  }
}

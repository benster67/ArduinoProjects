#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>
#include <Keypad.h>

#define I2C_ADDR    0x27
#define BACKLIGHT_PIN  3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

#define TRIGGER_PIN  9
#define ECHO_PIN     8
#define MAX_DISTANCE 1000

#define DHT11_PIN 10

LiquidCrystal_I2C  lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

dht DHT;

int celcius = 0;
int farenheit = 0;
int humidity = 0;

const int photocellPin = A1;

int photocellReading = 0;

const int GREEN = 33;
const int BLUE = 35;
const int RED = 31;

const int delayTime = 2;

int redVal = 0;
int blueVal = 0;
int greenVal = 0;

const int speakerPin = 49; //Put Switch on Speaker

const int Pi = 3.14159265358979;

long num1; 
long num2;
double total;
char operation;
char button;

const byte ROWS = 4;
const byte COLS = 4;

char buttons[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};
byte rowPins[ROWS] = {A2, A3, A4, A5};
byte colPins[COLS] = {2, 3, 4, 5};
Keypad buttonMatrix = Keypad( makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

void setup() {
 pinMode(GREEN, OUTPUT);
 pinMode(BLUE, OUTPUT);
 pinMode(RED, OUTPUT);

 pinMode(speakerPin, OUTPUT);

 pinMode(photocellPin, INPUT);

 Serial.begin(9600);
 lcd.begin (20, 4);
 lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
 lcd.setBacklight(HIGH);
 lcd.home();
 test();
}

void test() {
showBootInfo();
}
void loop(){}
void checkForButton() {
      // Loops are convenient for reading key press from keypad 
    while(1) // First loop. Here we read keypad and compose our first number. It does so untill we press operation button and break's out of loop or 'C' and it starts from beginning of this loop
    {

        
        button = buttonMatrix.getKey(); // Button read
        if (button=='C') // If user wants to resset while he is writing first number
        {
          buttonPressed();
          num1=0;
          num2=0;
          total=0;
          operation=0;
          lcd.clear();
        }
        
        if (button >='0' && button <='9') // If user pressed numeric value, 1 character at a time.
        {
          buttonPressed();
          num1 = num1*10 + (button -'0'); // Our numeric values are 0-9 witch means they are in first decade, when we multiply with 10 we basicaly add zero after number,
          // than we add a new number entered to that zero spot. As for (button -'0') this is simple ASCII table "trick" 0...9 in ASCII table are 48 ... 57,
          // so by subtracting '0' from any of them we get their value in decade system ex. char '5' = 53 in decade numeric system minus 48 for zero char gives us value of actual 5,
          // if our previous number was ex. 25 we get 250 by multiplying it with 10 and then we add 5 and we get 255 witch gets printed on LCD.
          lcd.setCursor(0,0); // Select first row on lcd
          lcd.print(num1); // Print current number1
        }
        if (num1 !=0 && (button=='-' || button=='+' || button=='*' || button=='/')) // If user is done inputing numbers
        {
          buttonPressed();
          operation = button; // operation remembers what mathematical operation user wants on numbers
          lcd.setCursor(0,1); // set cursor to row 2
          lcd.print(operation); // print our operator
          break;
        }

    }
    
    while(1) // Second while loop, it loops untill user has pressed '=' or 'C'. so it either prints total or ressets program
    {
        if (button =='C'){
          buttonPressed();
          break;
          } // This covers case where user pressed operator and still wants to reset
        button = buttonMatrix.getKey();
        if (button=='C') // Making sure user wants to reset at anytime
        {
          buttonPressed();
          num1=0;
          num2=0;
          total=0;
          operation=0;
          lcd.clear();
          break;
        }
        if (button >='0' && button <='9') // Getting chars from keypad for number 2
        {
          buttonPressed();
          num2 = num2*10 + (button -'0');
          lcd.setCursor(1,1);
          lcd.print(num2);
        }
        if (button == '=' && num2 !=0)// If button pressed was '=' its the end of the road. Calls calculate() subroutine does calculation and print our results
        {
          buttonPressed();
          calculate();
                   
          break;  
        }
    }
    while(1) 
    {
      // After all is done this loop waits for 'C' key to be pressed so it can reset program and start over.
      if (button =='C'){break;} // This line is side effect of previous loop since if user pressed 'C' it breaks out of previous loop and continues here.So we need to break this one aswell or user would need to press 'C' 2 times
      button = buttonMatrix.getKey();
      if (button =='C') 
        {
          buttonPressed();
           lcd.clear();
           lcd.setCursor(0,0);
           num1=0;
           num2=0;
           total=0;
           operation=0;
           break;
        }
    }
}
void calculate() // Simple switch case to pick what operation to do, based on button pressed by user.
{
  switch(operation)
    {
      case '+': // Addition
          buttonPressed();
          total = num1+num2;
          break;
      
      case '-': // Subtraction 
      buttonPressed();
          total = num1-num2;
          break;
      
      case '/': 
      buttonPressed();// Division. Could add error for division by zero, or change line in second loop where it waits for '=' char to if (button == '=' && num2 != 0) this will halt program untill num2 is not zero and then continue 
          total = (float)num1/(float)num2;
          break;
      
      case '*': 
        buttonPressed();// Multiplication
          total = num1*num2;
          break;
      //SQUARE ROOT AND EXPONENT    
          
    }
    // Based on case selected print our total and 
    lcd.setCursor(0,1);
    lcd.print('=');
    lcd.setCursor(1,1);
    showResult();
    
} 

void buttonPressed() {
  setLEDBlue();
  delay(50);
  turnLEDOff();
  playButtonTone();
}

void playButtonTone() {
  tone(speakerPin, 600, 50); //FIND BETTER VALUES
}

void showResult() {
  setLEDGreen();
  lcd.print(total);
  delay(250);
  turnLEDOff();
  
}
void turnLEDOff() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}
void setLEDBlue() {
  turnLEDOff();
  digitalWrite(GREEN, HIGH); //RED AND GREEN MAKE BLUE
  digitalWrite(RED, HIGH);
}
void setLEDGreen() {
  turnLEDOff();
  digitalWrite(BLUE, HIGH); //RED AND BLUE MAKE GREEN
  digitalWrite(RED, HIGH);
}
void setLEDRed() {
  turnLEDOff();
  digitalWrite(GREEN, HIGH);//GREEN AND BLUE MAKE RED
  digitalWrite(BLUE, HIGH);
}
void setLEDRGB() {

  int redVal = 255;
  int blueVal = 0;
  int greenVal = 0;
  for ( int i = 0 ; i < 255 ; i += 1 ) {
    greenVal += 1;
    redVal -= 1;
    analogWrite( GREEN, 255 - greenVal );
    analogWrite( RED, 255 - redVal );

    delay( delayTime );
  }

  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for ( int i = 0 ; i < 255 ; i += 1 ) {
    blueVal += 1;
    greenVal -= 1;
    analogWrite( BLUE, 255 - blueVal );
    analogWrite( GREEN, 255 - greenVal );

    delay( delayTime );
  }

  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for ( int i = 0 ; i < 255 ; i += 1 ) {
    redVal += 1;
    blueVal -= 1;
    analogWrite( RED, 255 - redVal );
    analogWrite( BLUE, 255 - blueVal );

    delay( delayTime );
  }
}
void showBootInfo() {
  setLEDRGB();
  lcd.home();
  lcd.print("Ben's Tech Garage");
  lcd.setCursor(0,1);
  lcd.print("Multi-Tool");
  lcd.setCursor(0,2);
  lcd.print("Version 1.0");
  lcd.setCursor(0,3);
  lcd.print("BETA 2016");
  delay(2000);
  lcd.clear();
  turnLEDOff();
  askStartFunc();
}
void askStartFunc() {
  setLEDGreen();
  lcd.clear();
  lcd.home();
  lcd.print("Choose Function");
  lcd.setCursor(0,1);
  lcd.print("1: Calculate");
  lcd.setCursor(0,2);
  lcd.print("2: Ping 4: Lux");
  lcd.setCursor(0,3);
  lcd.print("3: ENV");
  lcd.setCursor(8,3);
  lcd.print("5: Timer");

  button = buttonMatrix.getKey();
  switch(button) {
    case '1':
    Serial.println("button 1 pressed");
      checkForButton();
      turnLEDOff();
      break;
    case '2':
     Serial.println("button 2 pressed");
      checkPing();
      turnLEDOff();
      break;
    case '3':
     Serial.println("button 3 pressed");
      checkEnvironment();
      turnLEDOff();
      break;
    case '4':
     Serial.println("button 4 pressed");
      checkLux();
      turnLEDOff();
      break;
  }
}
long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
void checkPing() {


  long duration = pulseIn(ECHO_PIN, HIGH);
  long inches = microsecondsToInches(duration);
  long cm = microsecondsToCentimeters(duration);

  if (inches >> 1500 && cm >> 3500)
  {
    lcd.print("TOO FAR/CLOSE");
  }

  if (inches == 0 || cm == 0) {}

  if (inches == 0 && cm == 0) {}

  else {
    Serial.println(inches);
    lcd.print(inches);
    lcd.print("in");
    lcd.setCursor(0, 1);
    lcd.print(cm);
    lcd.print("cm");
    lcd.print("       ");
    delay(100);
  }

}
void checkEnvironment() {
  int chk = DHT.read11(DHT11_PIN);
  celcius = DHT.temperature;
  farenheit = (celcius * 1.800000) + 32;
  humidity =  DHT.humidity;
  printEnviromentStatus();
}

void printEnviromentStatus() {
  lcd.print("Temp = ");
  lcd.print(farenheit);
  lcd.print(" Deg F ");
  lcd.print(celcius);
  lcd.println(" Deg C ");
  lcd.print("Humidity = ");
  lcd.print(humidity);
  lcd.println("%");
  //delay(1000);
}
void checkLux() {
  photocellReading = analogRead(photocellPin); //CHANGE TO LCD PRINT
  Serial.print("Lux: ");
  Serial.println(photocellReading);
  if (photocellReading < 10) {
    Serial.println(" - Dark");
  } else if (photocellReading < 200) {
    Serial.println(" - Dim");
  } else if (photocellReading < 500) {
    Serial.println(" - Light");
  } else if (photocellReading < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }
  delay(1000);
}


















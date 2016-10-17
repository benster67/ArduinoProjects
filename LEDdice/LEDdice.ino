int topLeft = 13;
int leftMiddle = 12;
int bottomLeft = 11;
int topRight = 10;
int rightMiddle = 9;
int bottomRight = 8;
int middle = 7;
int buttonPin = 6;
int buttonState = 0;

void setup() {
  pinMode(topLeft, OUTPUT);//doesnt work
  pinMode(leftMiddle, OUTPUT);
  pinMode(rightMiddle, OUTPUT);
  pinMode(middle, OUTPUT);//doesnt work
  pinMode(topRight, OUTPUT);//doesnt work
  pinMode(rightMiddle, OUTPUT);
  pinMode(bottomRight, OUTPUT);//doesnt work
  pinMode(bottomLeft, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
 buttonState = digitalRead(buttonPin);
 if (buttonState == HIGH) {
  for (int x = 0; x < 5; x++) {
  int randNumber = random(1, 7);
  Serial.println(randNumber);
  delay(200);
  if (randNumber == 1) {
    digitalWrite(middle, HIGH);
    delay(200);
  }
  else if (randNumber == 2) {
    digitalWrite(bottomLeft, HIGH);
    digitalWrite(topRight, HIGH);
    delay(200);
  }

  else if (randNumber == 3) {
    digitalWrite(middle, HIGH);
    digitalWrite(bottomLeft, HIGH);
    digitalWrite(topRight, HIGH);
    delay(200);
  }

  else if (randNumber == 4) {
    digitalWrite(topLeft, HIGH);
    digitalWrite(bottomLeft, HIGH);
    digitalWrite(topRight, HIGH);
    digitalWrite(bottomRight, HIGH);
    delay(200);
  }

  else if (randNumber == 5) {
    digitalWrite(middle, HIGH);
    digitalWrite(bottomLeft, HIGH);
    digitalWrite(bottomRight, HIGH);
    digitalWrite(topLeft, HIGH);
    digitalWrite(topRight, HIGH);
    delay(200);
  }
  else if (randNumber == 6) {
    digitalWrite(leftMiddle, HIGH);
    digitalWrite(bottomLeft, HIGH);
    digitalWrite(topLeft, HIGH);
    digitalWrite(rightMiddle, HIGH);
    digitalWrite(bottomRight, HIGH);
    digitalWrite(topRight, HIGH);
    delay(200);
  }
    if(x==4) {
      delay(2000); //Let the last value shows for 2 seconds
    }
    
    digitalWrite(middle, LOW);
    digitalWrite(leftMiddle, LOW);
    digitalWrite(bottomLeft, LOW);
    digitalWrite(topLeft, LOW);
    digitalWrite(rightMiddle, LOW);
    digitalWrite(bottomRight, LOW);
    digitalWrite(topRight, LOW);
    }
  }
}

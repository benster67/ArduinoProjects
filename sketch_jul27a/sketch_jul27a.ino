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
  // put your setup code here, to run once:
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
 digitalWrite(bottomLeft, HIGH);

}

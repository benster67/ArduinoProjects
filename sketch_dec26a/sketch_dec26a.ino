int out_pin = 12;
int in_pin = 7;

void setup() {
  pinMode(out_pin, OUTPUT);
  pinMode(in_pin, INPUT);
}

void loop() {
  if (digitalRead(in_pin) == LOW) {
    digitalWrite(out_pin, HIGH);
  } else {
    digitalWrite(out_pin, LOW);
  }
  
  delay(500);
}

void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);

}

void loop() {
  if(digitalRead(9)==HIGH){
    tone(8, 9000,2);
  }

}

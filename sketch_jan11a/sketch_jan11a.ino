void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}
 
void loop()
{ //set pin 11-13 high so as to light all the layers
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
 
  digitalWrite(6,HIGH);//set the middle column ON throughout
 
 //light the other columns on and off in a sequence
 for(int i=2; i<11;i++)
  {
    if (i==6)
    {
    }
    else
    {
      digitalWrite(i,HIGH);
      delay(100);
      digitalWrite(i,LOW);
    }
  }
}

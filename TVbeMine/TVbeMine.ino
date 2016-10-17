#include <IRLib.h>

int RECV_PIN = 11;
IRsend My_Sender;

IRrecv My_Receiver(RECV_PIN);
IRdecode My_Decoder;

void setup()
{

  pinMode(2, OUTPUT);
  Serial.begin(9600);
  My_Receiver.enableIRIn(); // Start the receiver

}

void loop() {
  if (My_Receiver.GetResults(&My_Decoder)) {
    //Restart the receiver so it can be capturing another code
    //while we are working on decoding this one.
    Serial.println(My_Decoder.value);
    My_Decoder.decode();
    int ValueInDictionary = channelNumber(My_Decoder.value);

    Serial.println(ValueInDictionary);
  }
  My_Receiver.resume();
  My_Receiver.enableIRIn();
}



int channelNumber(int ValueInDictionary) {
  int numPressed;
  switch (ValueInDictionary) {
    case 4413:
      numPressed = 1;
      break;
    case 4381:
      numPressed = 2;
      break;
    case -23871:
      numPressed = 3;
      break;

    case -28403:
      numPressed = 4;
      break;

    case 20789:
      numPressed = 5;
      break;

    case 20757:
      numPressed = 6;
      break;

    case -11995:
      numPressed = 7;
      break;

    case -12027:
      numPressed = 8;
      break;

    case 12601:
      numPressed = 9;
      break;
    case 12569:
      numPressed = 0;
      break;
  }

  return numPressed;


}


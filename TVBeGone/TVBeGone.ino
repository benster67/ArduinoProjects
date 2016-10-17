/* Example program for from IRLib – an Arduino library for infrared encoding and decoding
   Version 1.3   January 2014
   Copyright 2014 by Chris Young http://cyborg5.com
   Based on original example sketch for IRremote library
   Version 0.11 September, 2009
   Copyright 2009 Ken Shirriff
   http://www.righto.com/
*/
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

    My_Decoder.decode();
    int value = My_Decoder.value;
    delay(1000);
    Serial.println(value);
    delay(1000);
    if (value == -32641) {
      delay(10000);
      My_Sender.send(NEC, 0x1CE3807F, 32);
    }
    My_Receiver.resume();
    My_Receiver.enableIRIn();
  }

}


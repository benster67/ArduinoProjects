#include <NewPing.h>
  int ping = 0;
  int oldPing = 0;
 
  NewPing sonar(4,3,50);
void setup() {

Serial.begin(9600);
}

void loop() {
  
ping = sonar.ping_in();

if (ping == 0) {
 
}
else if(oldPing == ping) {
    
}
 else {
  Serial.println(ping);
 }
 oldPing = ping;
}





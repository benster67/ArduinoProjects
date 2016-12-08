#define GREEN 11
#define BLUE 10
#define RED 12
#define delayTime 2

int redVal;
int blueVal;
int greenVal;

void setup() {

  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  //digitalWrite(GREEN, HIGH);//RED AND GREEN MAKE BLUE
  digitalWrite(BLUE, HIGH);//RED AND BLUE MAKE GREEN
  digitalWrite(RED, HIGH);
}


void bootRGB() {
 
  int redVal = 255;
  int blueVal = 0;
  int greenVal = 0;
  for( int i = 0 ; i < 255 ; i += 1 ){
    greenVal += 1;
    redVal -= 1;
    analogWrite( GREEN, 255 - greenVal );
    analogWrite( RED, 255 - redVal );

    delay( delayTime );
  }
 
  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for( int i = 0 ; i < 255 ; i += 1 ){
    blueVal += 1;
    greenVal -= 1;
    analogWrite( BLUE, 255 - blueVal );
    analogWrite( GREEN, 255 - greenVal );

    delay( delayTime );
  }
 
  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for( int i = 0 ; i < 255 ; i += 1 ){
    redVal += 1;
    blueVal -= 1;
    analogWrite( RED, 255 - redVal );
    analogWrite( BLUE, 255 - blueVal );

    delay( delayTime );
  }
}

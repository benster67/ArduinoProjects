int redPin = 12;
int greenPin = 11;
int bluePin = 10;
int RGBdelay = 100;
//uncomment this line if using a Common Anode LED
#define COMMON_ANODE
void setup()
{
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
}
void loop()
{
setColor(255, 0, 0); // red
delay(RGBdelay);
setColor(0, 255, 0); // green
delay(RGBdelay);
setColor(0, 0, 255); // blue
delay(RGBdelay);
setColor(255, 255, 0); // yellow
delay(RGBdelay);
setColor(80, 0, 80); // purple
delay(RGBdelay);
setColor(0, 255, 255); // aqua
delay(RGBdelay);
}
void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
red = 255 - red;
green = 255 - green;
blue = 255 - blue;
#endif
analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);
}


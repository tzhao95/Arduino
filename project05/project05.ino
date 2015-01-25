#include <Servo.h>

Servo mood;
int const potPin = A0;
int pot;
int angle;

void setup() {
  mood.attach(6);
  Serial.begin(9600);
}

void loop() {
  pot = analogRead(potPin);
  Serial.print("pot: ");
  Serial.print(pot);
  
  //map(number to scale, min value of input, max input, min out, max out)
  angle = map(pot, 0, 1023, 0 , 179);
  Serial.print(" , angle: ");
  Serial.println(angle);
  
  mood.write(angle);
  delay(15);
}


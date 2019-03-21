#include <Servo.h>
Servo meuServo;

void setup(){
  Serial.begin(9600);
  meuServo.attach(4);
}

void loop(){
  int val = analogRead(0);
  int x = map(val,0,1023,0,179);
  Serial.print(val);
  Serial.println(" - ");
  Serial.println(x);
  meuServo.write(x);
  delay(10);    
 }

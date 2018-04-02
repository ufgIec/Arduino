const int R = 9;
const int G = 10;
const int B = 11;

int vRed = 255;int vGreen = 0;int vBlue = 0;

void setup(){
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  analogWrite(R, vRed);
  analogWrite(G, vGreen);  analogWrite(B, vBlue);}





void loop(){
  for (vGreen = 0 ; vGreen < 255 ; vGreen = vGreen+10){
     analogWrite(G, vGreen);
     delay(50);
  }
 
for (vRed = 0 ; vRed < 255 ; vRed = vRed+10){
     analogWrite(R, vRed);
     delay(50);
  }

 for (vBlue = 0 ; vBlue < 255 ; vBlue = vBlue+10){
     analogWrite(B, vBlue);
     delay(50);
  }
}


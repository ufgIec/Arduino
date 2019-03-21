void setup(){
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop(){
  int x = Serial.available();
  Serial.println(x);
  if(x>0){
    int dado = Serial.read();
    if(dado == '1')digitalWrite(7,HIGH);
    if(dado == '2')digitalWrite(6,HIGH);
    if(dado == '3')digitalWrite(5,HIGH);
    if(dado == 'a')digitalWrite(7,LOW);
    if(dado == 's')digitalWrite(6,LOW);
    if(dado == 'd')digitalWrite(5,LOW);
    delay(500);
  }
}
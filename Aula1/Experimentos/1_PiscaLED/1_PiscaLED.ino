void setup(){
  pinMode(13,OUTPUT);
}

void loop(){
  digitalWrite(13,HIGH); 	//HIGH = 1 : ligar led
    delay(500);
  digitalWrite(13,LOW); 	//LOW = 0 : desligar led
    delay(500);
}
	
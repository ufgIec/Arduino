const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
const int LED[] = {2,3,4,5,6,7,8,9,10,11};

void setup(){
  analogReference(INTERNAL);
   for(int x = 0; x < 10; x++){
     pinMode(LED[x], OUTPUT);
    }

    Serial.begin(9600);
 }
 
void loop(){
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817204301;
 
  Serial.println(temperatura);
  
  if(temperatura > 30.15){
    digitalWrite(LED[0], HIGH);
  }
  else{
    digitalWrite(LED[0], LOW);
  }
  if(temperatura > 30.20){
    digitalWrite(LED[1], HIGH);
  }
  else{
    digitalWrite(LED[1], LOW);
  }
  if(temperatura > 30.25){
    digitalWrite(LED[2], HIGH);
  }
  else{
    digitalWrite(LED[2], LOW);
  }
  if(temperatura > 30.30){
    digitalWrite(LED[3], HIGH);
  }
  else{
    digitalWrite(LED[3], LOW);
  }
  if(temperatura > 30.35){
    digitalWrite(LED[4], HIGH);
  }
  else{
    digitalWrite(LED[4], LOW);
  }
  if(temperatura > 30.40){
    digitalWrite(LED[5], HIGH);
  }
  else{
    digitalWrite(LED[5], LOW);
  }
  if(temperatura > 30.45){
    digitalWrite(LED[6], HIGH);
  }
  else{
    digitalWrite(LED[6], LOW);
  }
  if(temperatura > 30.50){
    digitalWrite(LED[7], HIGH);
  }
  else{
    digitalWrite(LED[7], LOW);
  }
  if(temperatura > 30.55){
    digitalWrite(LED[8], HIGH);
  }
  else{
    digitalWrite(LED[8], LOW);
  }
  if(temperatura > 30.60){
    digitalWrite(LED[9], HIGH);
  }
  else{
    digitalWrite(LED[9], LOW);
  }

  delay(1000);
}
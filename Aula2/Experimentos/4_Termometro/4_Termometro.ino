const int lm = 0;
float temperatura = 0;
int analogLido = 0;

void setup(){
  Serial.begin(9600);
  analogReference(INTERNAL);
}

void loop(){
  analogLido = analogRead(lm);
  temperatura = analogLido*0.1075268817204301;
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println(" *C");
  delay(1000);
 }

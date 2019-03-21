//Incluindo biblioteca Ultrasonic.h
#include "Ultrasonic.h"
 
//criando objeto ultrasonic e definindo as portas digitais 
//do Trigger - 7 - e Echo - 6
Ultrasonic ultrasonic(7,6);
 
 
long microsec = 0;
float distanciaCM = 0;
 
void setup() {
  Serial.begin(9600); //Inicializando o serial monitor

}
 
void loop() {  
  //Lendo o sensor
  microsec = ultrasonic.timing(); 
 
  //Convertendo a dist�ncia em CM
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); 
 
 
  Serial.print(distanciaCM);
  Serial.println(" cm");
  delay(1000);
}
 

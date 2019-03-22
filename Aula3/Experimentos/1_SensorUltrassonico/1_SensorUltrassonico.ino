/*
   Experimento 3.1 - SensorUltrasonico

   Mede a distancia entre o sensor e o objeto em sua frente e imprime na porta serial.
*/

//Incluindo biblioteca Ultrasonic.h
#include "Ultrasonic.h"

//Criando objeto ultrasonic e definindo as portas digitais: Trigger == 7 e Echo == 6
Ultrasonic ultrasonic(7, 6);

// Inicializa variaveis
long microsec = 0;
float distanciaCM = 0;

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicia a comunicação serial utilizando a velocidade de 9600bps.
  Serial.begin(9600);
}

// A função loop roda repetidamente
void loop() {
  // ultrasonic.timing() retorna o tempo em microsegundos que a onda sonora leva para atingit o objeto e retornal ao sensor.
  microsec = ultrasonic.timing();

  // ultrasonic.convert() recebe o tempo em microsegundos e retorna um valor correspondente em cm.
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);


  Serial.print(distanciaCM); //Imprime a distancia em cm na porta serial
  Serial.println(" cm");
  delay(1000); // Espera um segundo.
}

/*
   Experimento 2.1 - ServoMotor

   Utiliza o sinal gerado por um potênciometro numa entrada analogica para controlar um servo
   motor.
*/

#include <Servo.h> // Importa a biblioteca para controle do servo.
Servo meuServo; // Instancia um objeto do tipo Servo chamado meuServo.

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicia a comunicação serial utilizando a velocidade de 9600bps.
  Serial.begin(9600);
  meuServo.attach(4); // Define o pino digital conectado ao servo motor meuServo.
}

// A função loop roda repetidamente
void loop() {
  int val = analogRead(0); // Salva i valor da entrada analogica na variavel val.
  int x = map(val, 0, 1023, 0, 179); // converte o valor na entrada analogica (0-1023) para um valor entre 0 e 179.
   // Imprime na porta serial os valores de val e x no formato "val - x".
  Serial.print(val);
  Serial.println(" - ");
  Serial.println(x);
  meuServo.write(x); // Manda o servo para a posição x.
  delay(10); // Espera 10 milisegundos.
}

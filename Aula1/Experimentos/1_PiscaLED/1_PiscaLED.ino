/*
   Experimento 1.1 - PiscaLed

   Liga um LED por um segundo, depois desliga por um segundo, repetidamente.

   HIGH e LOW são níveis de tensão, no caso do arduino HIGH e LOW correspondem a
   5V e 0V respectivamente mas existem outros dispositivos com niveis diferentes
   de tensão.
   
   Saiba mais:
   http://www.arduino.cc/en/Tutorial/Blink (em inglês)
   https://www.embarcados.com.br/niveis-e-limites-de-tensoes-digitais/
*/

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicializa o pino digital 13 como uma saida.
  pinMode(13, OUTPUT);
}

// A função loop roda repetidamente
void loop() {
  digitalWrite(13, HIGH); 	// Liga o LED
  delay(1000);              // Espera um segundo
  digitalWrite(13, LOW); 	  // Desliga o LED
  delay(1000);              // Espera um segundo
}

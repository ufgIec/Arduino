/*
   Experimento 1.5 - SensorLDR

   Utiliza um resistor dependente de luz (LDR*) para medir a intensidade luminosa do ambiente
   e enviar o valor lido na entrada analógica para a porta serial.

   LDR "é um resistor cuja resistência varia conforme a intensidade da luz (iluminamento) que incide sobre ele."
   fonte: https://pt.wikipedia.org/wiki/LDR

   As entradas anaogicas do arduino lêen um sinal de tenão de 0 a 5V e convertem para um
   valor inteiro entre 0 e 1023. No circuito utilizado a tensão que chega na entrada analogica
   varia em função a resistencia do LDR, trata-se de um circuito divisor de tensão.

   Saiba mais:
   https://www.arduino.cc/en/tutorial/AnalogInput (em inglês)
   https://pt.wikipedia.org/wiki/Divisor_de_tens%C3%A3o
*/

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicia a comunicação serial utilizando a velocidade de 9600bps.
  Serial.begin(9600);
}

// A função loop roda repetidamente
void loop() {
  // A função alanogRead(x) lê o valor a entrada analógica x.
  int luz = analogRead(0); // Salva o valor lido em uma variavel do tipo inteiro.
  // A função Serial.println() imprime dados na porta serial como texto ASCII.
  Serial.println(luz);
  delay(500); // Espera meio segundo
}

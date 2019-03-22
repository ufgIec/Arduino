/*
   Experimento 2.3 - SensorLM35]

   Imprime na porta serial o valor gerado pelo sensor LM35 na porta analogica.

   Saiba mais:
   http://www.ti.com/lit/ds/symlink/lm35.pdf
*/

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicia a comunicação serial utilizando a velocidade de 9600bps.
  Serial.begin(9600);
}

// A função loop roda repetidamente
void loop() {
  int temp = analogRead(0); // Salva o valor lido da entrada analogica na variavel temp.
  Serial.println(temp); // Imprime o valor de temp na porta serial.
  delay(1000); // Espera um segundo.
}

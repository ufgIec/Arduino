/*
   Experimento 2.4 - Termometro

   Lê o valor gerado na entrada nalogica por um LM35, converte para graus celsius e imprime
   na porta serial.

   Saiba mais:
   http://www.ti.com/lit/ds/symlink/lm35.pdf
   https://www.arduino.cc/reference/en/language/functions/analog-io/analogreference/ (em inglês)
*/

// Declara variaveis utilizadas no codigo.
const int lm = 0; // Numero da entrada conectada no sensor.
float temperatura = 0;
int analogLido = 0;

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicia a comunicação serial utilizando a velocidade de 9600bps.
  Serial.begin(9600);
  analogReference(INTERNAL); // Configura a tenão de referencia da entrada analogica.
}

// A função loop roda repetidamente
void loop() {
  analogLido = analogRead(lm); // Salva o valor lido da entrada analogica na variavel analogLido.
  temperatura = analogLido * 0.1075268817204301; // Multiplica o valor lido por uma constante de conversão.
  // Imprime a temperatura lida no formato "Temperatura = xxx *C"
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println(" *C");
  delay(1000); // Espera um segundo.
}

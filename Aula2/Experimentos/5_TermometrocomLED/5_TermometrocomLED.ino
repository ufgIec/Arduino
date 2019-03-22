/*
   Experimento 2.5 - TermometroComLed

   Lê a temperatura utilizando um LM35, imprime o valor lido na porta serial e indida a
   variação do mesmo em uma barra de LEDs.

   Saiba mais:
   http://www.ti.com/lit/ds/symlink/lm35.pdf
*/

// Declara variaveis utilizadas no codigo.
const int LM35 = 0; // Numero da entrada conectada no sensor.
float temperatura = 0;
int analogLido = 0;
const int LED[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // Vetor contendo as saidas digitais dos LEDs.

void setup() {
  analogReference(INTERNAL);  // Configura a tenão de referencia da entrada analogica.
  // Inicializa os pinos digitais conectados aos LEDs como saidas.
  for (int x = 0; x < 10; x++) {
    pinMode(LED[x], OUTPUT);
  }
  // Inicia a comunicação serial utilizando a velocidade de 9600bps.
  Serial.begin(9600);
}

void loop() {
  analogLido = analogRead(LM35); // Salva o valor lido da entrada analogica na variavel analogLido.
  temperatura = analogLido * 0.1075268817204301; // Multiplica o valor lido por uma constante de conversão.

  Serial.println(temperatura); // Imprime a temperatura em celsius na porta serial.

  
  if (temperatura > 30.15) { // Liga LED 0 se a temperatua for superior a 30.15ºC.
    digitalWrite(LED[0], HIGH);
  }
  else {
    digitalWrite(LED[0], LOW);
  }
  if (temperatura > 30.20) { // Liga LED 1 se a temperatua for superior a 30.20ºC.
    digitalWrite(LED[1], HIGH);
  }
  else {
    digitalWrite(LED[1], LOW);
  }
  if (temperatura > 30.25) { // Liga LED 2 se a temperatua for superior a 30.25ºC.
    digitalWrite(LED[2], HIGH);
  }
  else {
    digitalWrite(LED[2], LOW);
  }
  if (temperatura > 30.30) { // Liga LED 3 se a temperatua for superior a 30.30ºC.
    digitalWrite(LED[3], HIGH);
  }
  else {
    digitalWrite(LED[3], LOW);
  }
  if (temperatura > 30.35) { // Liga LED 4 se a temperatua for superior a 30.35ºC.
    digitalWrite(LED[4], HIGH);
  }
  else {
    digitalWrite(LED[4], LOW);
  }
  if (temperatura > 30.40) { // Liga LED 5 se a temperatua for superior a 30.40C.
    digitalWrite(LED[5], HIGH);
  }
  else {
    digitalWrite(LED[5], LOW);
  }
  if (temperatura > 30.45) { // Liga LED 6 se a temperatua for superior a 30.45ºC.
    digitalWrite(LED[6], HIGH);
  }
  else {
    digitalWrite(LED[6], LOW);
  }
  if (temperatura > 30.50) { // Liga LED 7 se a temperatua for superior a 30.50ºC.
    digitalWrite(LED[7], HIGH);
  }
  else {
    digitalWrite(LED[7], LOW);
  }
  if (temperatura > 30.55) { // Liga LED 8 se a temperatua for superior a 30.55ºC.
    digitalWrite(LED[8], HIGH);
  }
  else {
    digitalWrite(LED[8], LOW);
  }
  if (temperatura > 30.60) { // Liga LED 0 se a temperatua for superior a 30.15ºC.
    digitalWrite(LED[9], HIGH);
  }
  else {
    digitalWrite(LED[9], LOW);
  }

  delay(1000); // Espera um segundo.
}

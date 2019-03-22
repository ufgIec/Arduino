/*
   Experimento 1.3 - PiscaLEDBotao

   Mantem um LED ligado enquanto o botão estiver pessionado e imprime na porta serial o estado
   do LED. Utilize o monitor serial da ide oficial (Ctrl+Shift+M) para leitura dos dados.

   Neste circuito utilizamos um resistor de pull-down, caso usassemos um resistor de pull-up a lógica de HIGH == botão pressionado
   e LOW == botão solto seria invertida.

   Saiba mais: 
   https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/ (em inglês)
   https://pt.wikipedia.org/wiki/Resistor_pull-up
*/

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicia a comunicação serial utilizando a velocidade de 9600bps.
  Serial.begin(9600);
  // Inicializa o pino digital 2 como uma entrada.
  pinMode(2, INPUT);
  // Inicializa o pino digital 13 como uma saida.
  pinMode(13, OUTPUT);
}

// A função loop roda repetidamente
void loop() {
  // digitalRead(pino) lê o valor de um pino digital, o valor depende do nivel de tensão no mesmo. HIGH == 1 e LOW == 0.
  int sensorValue = digitalRead(2); // Salva o valor lido numa variável do tipo inteiro.
  // A função Serial.println() imprime dados na porta serial como texto ASCII.
  Serial.println(sensorValue);
  if (sensorValue == 1) // Se a entrada estiver em nivel alto (HIGH) o botão está pressionado
    digitalWrite(13, HIGH); // Liga o led
  else // Senão (sensorValue != 1) o botão está solto
    digitalWrite(13, LOW); // Desliga o led
  delay(500); // Espera meio segundo
}

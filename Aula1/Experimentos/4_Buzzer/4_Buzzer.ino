/*
   Experimento 1.4 - Buzzer

   Mantem o buzzer apitando enquanto o botão for pressionado.
*/

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicia a comunicação serial utilizando a velocidade de 9600bps.
  Serial.begin(9600);
  // Inicializa o pino digitai 2 como uma entrada.
  pinMode(2, INPUT);
  // Inicializa o pino digitai 13 como uma saida.
  pinMode(13, OUTPUT);
}

// A função loop roda repetidamente
void loop() {
  // digitalRead(pino) lê o valor de um pino digital, o valor depende do nivel de tensão no mesmo. HIGH == 1 e LOW == 0.
  int sensorValue = digitalRead(2); // Salva o valor lido numa variável do tipo inteiro.
  // A função Serial.println() imprime dados na porta serial como texto ASCII.
  Serial.println(sensorValue); 
  if (sensorValue == 1) // Se a entrada estiver em nivel alto (HIGH) o botão está pressionado
    digitalWrite(13, HIGH); // Liga o buzzer
  else // Senão o botão está solto
    digitalWrite(13, LOW); // Desliga o buzzer
  delay(500); // Espera meio segundo
}

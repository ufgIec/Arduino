
/*
   Experimento 3.3 - ModuloRele]

   Acionamento de uma lampada usando uma porta digital e um modulo rele
*/

const int rele = 7 ; // Pino conectado do modulo rele.

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicializa o pino digital 7 como uma entrada.
  pinMode(rele, OUTPUT);
}

// A função loop roda repetidamente
void loop() {
  digitalWrite(rele, HIGH); // Aciona rele.
  delay(2000); // Espera 2 segundos.
  digitalWrite(rele, LOW); // Desaciona rele.
  delay(2000); // Espera 2 segundos.
}

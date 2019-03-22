/*
   Experimento 1.6 - LEDRGB

   Controla um LED RGB ligando as cores alternadamente.

   Um LED RGB cotem três LEDs nas cores vermelho, verde e azul no mesmo encapsulamento,
   possibilitando assim a geração de novas cores controlando a intensidade de cada LED.
*/

// Declara variaveis constantes para facilitar a leitura do codigo
const int R = 9; // Pino conectado ao LED vermelho
const int G = 10; // Pino conectado ao LED verde
const int B = 11; // Pino conectado ao LED azul

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicializa os pinos digitais de 9 a 11 como saidas.
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

// A função loop roda repetidamente
void loop() {
  // Liga o LED vermelho e desliga os demais.
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
  delay(500); // Espera meio segundo.

  // Liga o LED verde e desliga os demais.
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(B, LOW);
  delay(500); // Espera meio segundo.

  // Liga o LED azul e desliga os demais.
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, HIGH);
  delay(500); // Espera meio segundo.
}

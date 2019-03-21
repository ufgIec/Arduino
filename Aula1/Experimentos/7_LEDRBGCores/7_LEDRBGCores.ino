/*
   Experimento 7 - LEDRGBCores

   Controla um LED RGB utilizando PWM para alterar a intensidade de cada LED para gerar novas cores.

   Um LED RGB cotem três LEDs nas cores vermelho, verde e azul no mesmo encapsulamento,
   possibilitando assim a geração de novas cores controlando a intensidade de cada LED.

   Saiba mais:
   https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/ (em inglês)
   https://www.citisystems.com.br/pwm/
*/

// Declara variaveis constantes para facilitar a leitura do codigo
const int R = 9; // Pino conectado ao LED vermelho
const int G = 10; // Pino conectado ao LED verde
const int B = 11; // Pino conectado ao LED azul
// Variaveis que irão guardar valores PWM referentes a intensidade de cada cor. 0 == desligado (0V), 255 == intensidade máxima(5V).
int vRed = 255;
int vGreen = 0;
int vBlue = 0;

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicializa os pinos digitais de 9 a 11 como saidas.
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  // Escreve os valores PWM nas saidas dos LEDs
  analogWrite(R, vRed); // vRed == 255, Liga LED vermelha na intensidade máxima.
  analogWrite(G, vGreen); // vGreen == 0, Deslida o LED verde.
  analogWrite(B, vBlue); // vBlue == 0, Desliga o LED azul.
}


// A função loop roda repetidamente
void loop() {
  // Laço que se repete enquanto vGreen for menor que 255, somando 10 ao valor de vGreen a cada repetição.
  for (vGreen = 0 ; vGreen < 255 ; vGreen += 10) {
    analogWrite(G, vGreen); // Escreve o valor de vGreen na saida G
    delay(50); // Espera 50 milisegundos
  }
  // Laço que se repete enquanto vRed for menor que 255, somando 10 ao valor de vRed a cada repetição.
  for (vRed = 0 ; vRed < 255 ; vRed += 10) {
    analogWrite(R, vRed); // Escreve o valor de vGreen na saida R
    delay(50); // Espera 50 milisegundos
  }
  // Laço que se repete enquanto vBlue for menor que 255, somando 10 ao valor de vBlue a cada repetição.
  for (vBlue = 0 ; vBlue < 255 ; vBlue += 10) {
    analogWrite(B, vBlue); // Escreve o valor de vBlue na saida B
    delay(50); // Espera 50 milisegundos
  }
}

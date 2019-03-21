/*
   Experimento 2 - PiscaLEDviaPC

   Controla 3 LEDs utilizando a porta serial para receber os comandos para ligar e desligar. Envie os comandos
   pelo monitor serial da ide oficial (Ctrl+Shift+M).
   
   Saiba mais: 
   https://www.arduino.cc/reference/pt/language/functions/communication/serial/
*/

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicia a comunicação serial utilizando a velocidade de 9600bps.
  Serial.begin(9600);
  // Inicializa os pinos digitais de 5 a 7 como saidas.
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

// A função loop roda repetidamente
void loop() {
  // A função Serial.available() retorna a quantidade de caracteres disponíveis para leitura da porta serial.
  int x = Serial.available(); // Inicializa uma variavel do tipo inteiro recebendo o retorno da função Serial.available().
  // A função Serial.print() imprime dados na porta serial como texto ASCII.
  Serial.print(x); // Imprime na porta serial a quantidade de dados recebidos.
  // A função Serial.println() é como a print() mas envia uma quebra de linha no final dos dados.
  Serial.println(" Caracteres recebidos!");
  // Se x > 0 existem dados disponíveis para leitura da porta serial.
  if (x > 0) {
    //A função Serial.read() lê e retorna o proximo caractere disponivel na porta serial.
    int dado = Serial.read(); // Salva o valor do caractere recebido numa variável do tipo inteiro.
    if (dado == '1')digitalWrite(7, HIGH); // Se o caractere recebido for '1' desliga a saida 7.
    if (dado == '2')digitalWrite(6, HIGH); // Se o caractere recebido for '2' desliga a saida 6.
    if (dado == '3')digitalWrite(5, HIGH); // Se o caractere recebido for '3' desliga a saida 5.
    if (dado == 'a')digitalWrite(7, LOW); // Se o caractere recebido for 'a' desliga a saida 7.
    if (dado == 's')digitalWrite(6, LOW); // Se o caractere recebido for 's' desliga a saida 6.
    if (dado == 'd')digitalWrite(5, LOW); // Se o caractere recebido for 'd' desliga a saida 5.
    delay(500); // Espera meio segundo.
  }
}

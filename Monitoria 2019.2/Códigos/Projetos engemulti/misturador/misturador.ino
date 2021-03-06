//Projeto Maquina separadora de M&M's
//Por: Eng. Mauricio Gavina
 
#include <Servo.h> // Biblioteca para os servo motores
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3,POSITIVE);
#define S0 2 //definição dos pinos do sensor de cor
#define S1 3
#define S2 4
#define S3 5
 
#define sensorOut 6
 
Servo topServo; // declaração de cada servo como objeto
Servo bottomServo;
 
int frequency = 0; //variável auxiliar para ser usada na função readColor()
int color = 0; //variável usada na função readColor() para guardar a cor 
 
byte flag = 0; //A variável flag nos ajuda a separar nosso programa em estados
 
void setup() {
  pinMode(S0, OUTPUT); //definição dos pinos do sensor de cor como saída
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT); //definição do pino do sensor de cor como entrada
  // configura a frequência para 20% 
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
   lcd.begin (16,2);
   
  topServo.attach(7); //definição do servo superior no pino 7 do arduino
  bottomServo.attach(8);//servo inferior no pino 8 
   
  Serial.begin(9600); //inicia a comunicação serial
}
 
void loop() {
    
  
//Esse é o estado em que a máquina está em operação contínua
  topServo.write(130);//Posição inicial do servo; Deve estar alinhado com o furo do alimentador
  delay(1000);//usamos o delay para dar tempo do servo se mover até a posição final
  topServo.write(80);// Posição intermediária, deve estar alinhado com o sensor de cor
  flag=1;//envia a máquina para o segundo estado

 
if(flag == 1){//Nesse estado a máquina lê o sensor e mostra os dados no monitor serial
  readColor();//A função é responsável pela leitura do sensor e por enviar ao terceiro estado
}             //somente quando uma cor for detectada.
 
if(flag == 2){ //Nesse estado o servo de baixo se move conforme a cor detectada anteriormente
    switch (color) {
    case 1:
    bottomServo.write(20);
    break;
    case 2:
    bottomServo.write(45);
    break;
    case 3:
    bottomServo.write(70);
    break;
    case 4:
    bottomServo.write(95);
    break;
    case 5:
    bottomServo.write(120);
    break;
  }
  delay(1000);//os delays foram incluidos para dar tempo ao servo se mover 
  topServo.write(50);// Posição final, deve estar alinhada com o furo do distribuidor
  delay(1000);
  flag = 4; //enviamos a máquina para funcionamento contínuo, o quarto estado.
}
if(Serial.read()=='r' || Serial.read()=='R'){ //Caso a letra r seja enviada a máquina é 
  flag=0;                                     //resetada e retorna ao estado 1.
}
 
}
 
void readColor() {
  // configura os filtros vermelhos para serem lidos
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // lê a frequencia da saída
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency; // armazena o resultado na variável correspondente ao vermelho
  // Os valores são mostrados no serial monitor
  Serial.print("R= ");//escreve o nome 
  Serial.print(frequency);//escreve a frequencia
  Serial.print("  ");
  delay(50);
  // Configura os filtros verdes para serem lidos
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Lê a frequência de saída
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Os valores são mostrados no serial monitor
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);
  // Configura os filtros azuis para serem lidos
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
   
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
   
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(150);
  lcd.setBacklight(HIGH);
  lcd.clear();
lcd.setCursor(2,0);
lcd.print("MOSTRE A COR");
lcd.setCursor(3,1);
lcd.print("AO SENSOR");
  if(R>25 && R<45 && G>70 && G<135 && B>50 && B<100 ){
    lcd.clear();
    lcd.setCursor(3,1);
   lcd.print("VERMELHO!");
    color = 1; //Para ser usado pelo servo de baixo em seu posicionamento
    flag = 2; // Para enviar a máquina ao terceiro estado
    Serial.println(" Rosa ");//Escreve no monitor serial a cor detectada
  }
  if(R>70 && R<110 && G>90 && G<120 && B>65 && B<90 ){
    lcd.clear();
    lcd.setCursor(3,1);
   lcd.print("AZUL!");
    color = 3; //Para ser usado pelo servo de baixo em seu posicionamento
    flag = 2; // Para enviar a máquina ao terceiro estado
    Serial.println(" AZUL! ");//Escreve no monitor serial a cor detectada
  }
    if(R>80 && R<120 && G>60 && G<90 && B>60 && B<90 ){
    lcd.clear();
    lcd.setCursor(3,1);
   lcd.print("VERDE!");
    color = 5; //Para ser usado pelo servo de baixo em seu posicionamento
    flag = 2; // Para enviar a máquina ao terceiro estado
    Serial.println(" VERDE! ");//Escreve no monitor serial a cor detectada
  }
  if(R>80 && R<120 && G>60 && G<90 && B>60 && B<90 ){
    lcd.clear();
    lcd.setCursor(3,1);
   lcd.print("VERDE!");
    color = 5; //Para ser usado pelo servo de baixo em seu posicionamento
    flag = 2; // Para enviar a máquina ao terceiro estado
    Serial.println(" VERDE! ");//Escreve no monitor serial a cor detectada
  }
  else Serial.println("No Match");
}

//Programa: Monitoracao de planta usando Arduino
//Autor: FILIPEFLOP
 
#define pino_sinal_analogico A0
#define rele 13
#define led1 6
#define led2 7
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int valor_analogico;
 
void setup()
{
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  pinMode(rele, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
    lcd.begin(16, 2);
}
 
void loop()
{
  //Le o valor do pino A0 do sensor
  valor_analogico = analogRead(pino_sinal_analogico);
 
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica: ");
  Serial.print(valor_analogico);
 
  //Solo umido, acende o led verde
  if (valor_analogico > 0 && valor_analogico < 400)
  {
    Serial.println(" Status: Solo umido");
    digitalWrite(rele, LOW);
    digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
          lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("SOLO UMIDO!");
delay(4000);
  }
 
  //Solo com umidade moderada, acende led amarelo
  if (valor_analogico > 400 && valor_analogico < 800)
  {
    Serial.println(" Status: Umidade moderada");
    digitalWrite(rele, LOW);
    digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
          lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("SOLO OK!");
  delay(4000);
    
  }
 
  //Solo seco, acende led vermelho
  if (valor_analogico > 800 && valor_analogico < 1024)
  {
    Serial.println(" Status: Solo seco");
    digitalWrite(rele, HIGH);
    digitalWrite(led1,HIGH);
    delay(500);
    digitalWrite(led1,LOW);
    digitalWrite(led2, HIGH);
      lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("SOLO SECO!");
  lcd.setCursor(3, 1);
  lcd.print("REGANDO.....");
  delay(4000);

  }
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(1, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("REGADOR AUTOM.");
  lcd.setCursor(0, 1);
  lcd.print(" UFG - ENG. COMP.");
  delay(3000);
}
 

//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
}
 
void loop()
{
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(1, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("TU E LINDA,");
  lcd.setCursor(3, 1);
  lcd.print(" SABIA?");
  //Limpa a tela
   delay(4000);
     lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(1, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("OBRIGADO POR");
  lcd.setCursor(3, 1);
  lcd.print(" TUDO!");
     delay(4000);
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(1, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("FELIZ 5 MESES");
  lcd.setCursor(3, 1);
  lcd.print(" TE AMO!");
  delay(5000);
}

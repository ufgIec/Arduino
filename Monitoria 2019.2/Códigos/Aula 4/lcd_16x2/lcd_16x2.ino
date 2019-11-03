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
  lcd.print("UFG");
  lcd.setCursor(3, 1);
  lcd.print("IEC");
  lcd.clear();
}

/*
   Experimento 3.2 - MedidorDistancia

   Calcula a distancia de um objeto usando o sensor ultrasonico e mostra o resultado em um display lcd.

   Esse codigo utiliza a biblioteca Ultrasonic.h disponivel em https://github.com/filipeflop/Ultrasonic
*/

#include <LiquidCrystal.h>
#include <Ultrasonic.h>

//Cria um objeto do tipo LiquidCrystal e determina os pinos ligados ao LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//Cria um objeto do tipo Ultrasonic e determina os pinos ligados ao sensor ultrasonico
Ultrasonic ultrasonic(7, 6);

//Declara variaveis usadas no codigo
long microsec = 0;
float distanciaCM = 0;

// A função setup roda apenas uma vez, quando o botão reset é pressionado ou quando a placa é ligada.
void setup() {
  // Inicia a comunicação serial utilizando a velocidade de 9600bps.
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
}

// A função loop roda repetidamente
void loop() {
  // ultrasonic.timing() retorna o tempo em microsegundos que a onda sonora leva para atingit o objeto e retornal ao sensor.
  microsec = ultrasonic.timing();

  // ultrasonic.convert() recebe o tempo em microsegundos e retorna um valor correspondente em cm.
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);

  // imprime resultados no lcd e na saida serial
  lcd.setCursor(0,0);
  lcd.print("Cent.: ");
  lcd.print("        ");
  lcd.setCursor(7,0);
  lcd.print(distanciaCM);

  Serial.print("Cent.: ");
  Serial.print(distanciaCM);

}

//Programa: Monitoracao de planta usando Arduino
//Autor: FILIPEFLOP
 
#define pino_sinal_analogico A0
#define rele 13
#define led1 6
#define led2 7
 
int valor_analogico;
 
void setup()
{
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  pinMode(rele, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
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
    digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
  }
 
  //Solo com umidade moderada, acende led amarelo
  if (valor_analogico > 400 && valor_analogico < 800)
  {
    Serial.println(" Status: Umidade moderada");
    digitalWrite(rele, LOW);
    digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
    
  }
 
  //Solo seco, acende led vermelho
  if (valor_analogico > 800 && valor_analogico < 1024)
  {
    Serial.println(" Status: Solo seco");
    digitalWrite(rele, HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led2, HIGH);

  }
  delay(3000);
}
 

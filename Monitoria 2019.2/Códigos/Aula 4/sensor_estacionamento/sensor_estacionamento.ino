#include <Ultrasonic.h>   //Carrega a biblioteca Ultrasonic  
#include <NewTone.h>    //Carrega a biblioteca Newtone  
   
//Dados do buzzer  
#define tempo 500   
int frequencia = 2000;   
int Pinofalante = 2;   
    
int atraso = 1000;  //Tempo em milisegundos para o delay 
   
//Define o pino do Arduino a ser utilizado com o pino Trigger do sensor  
#define PINO_TRIGGER 13   
//Define o pino do Arduino a ser utilizado com o pino Echo do sensor  
#define PINO_ECHO   10   
   
//Inicializa o sensor ultrasonico  
Ultrasonic ultrasonic(PINO_TRIGGER, PINO_ECHO);   
   
void setup()  
{  
  pinMode(Pinofalante,OUTPUT); //Pino do buzzer definido como saída   
  Serial.begin(9600); //Inicializa a comunicação serial  
}  
   
void loop()  
{  
  float cmMsec, inMsec; //Declara duas variáveis para serem utilizadas com o sensor
    
  //Le os dados do sensor, com o tempo de retorno do sinal  
  long microsec = ultrasonic.timing();   
   
  //Calcula a distancia em centimetros  
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);   
    
  //Ajusta o atraso de acordo com a distancia  
  if (cmMsec > 80)   //Se a distância for maior que 80cm, delay de 2 segundos
  {  
    atraso = 2000;  
  }  
  else if (cmMsec >50 && cmMsec<80)   //Se a distância for maior que 50cm e menor que 80cm, delay de 1,5 segundos
  {  
    atraso = 1500;  
  }  
  else if (cmMsec >30 && cmMsec<50)  //Se a distância for maior que 30cm e menor que 50cm, delay de 1,2 segundos
  {  
    atraso = 1200;  
  }  
  else if (cmMsec > 10 && cmMsec < 30)  //Se a distância for maior que 30cm e menor que 10cm, delay de 0,7 segundos
  {  
    atraso = 700;  
  }  
  else if (cmMsec < 10)   //Se a distância for menor que 10cm, delay de 0,3 segundos
  {  
    atraso = 300;  
  }  
     
  //Apresenta os dados, em centimetros, na Serial  
  Serial.print("Cent: ");  
  Serial.print(cmMsec);  
  Serial.print(" atraso : ");  
  Serial.println(atraso);  
  //Emite o bip  
  NewTone(Pinofalante, frequencia, tempo);   
   
  delay(atraso);  
} 

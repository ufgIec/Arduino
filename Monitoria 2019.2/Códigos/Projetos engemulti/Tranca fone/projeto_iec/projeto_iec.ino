//       =========================================================================================
//       == TRABALHO DE IEC - 1° SEM - ENGENHARIA DE COMPUTAÇAO - UNIVERSIDADE FEDERAL DE GOIAS ==
//       ==                               PROJETO |||TRANCA FONE|||                             ==
//       ==                   ESCRITO POR ALUNO RAONI DOS REIS MIRANDA BARROS                   ==
//       =========================================================================================



//--------------INCLUSAO DAS BIBLIOTECAS--------------------------------------------------------------------------------------

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Servo.h>

//--------------DECLARAÇAO DO LCD--------------------------------------------------------------------------------------------

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);


//--------------DECLARACAO DO SERVO MOTOR----------------------------------------------------------------------------------------------

Servo trinca; 


//--------------DECLARAÇAO DE VARIAVEIS:------------------------------------------------------------------------------------------------

//----------------------SERVO-----------------------------------------------------------------------------------------------------------
int servo = 11, aberto = 0, fechado = 90;
//-----------------------LCD------------------------------------------------------------------------------------------------------------
int contraste = 70,  ledtela = 8, estadoled = 1;
//-----------------------LED------------------------------------------------------------------------------------------------------------
int ledvermelho = 12, ledverde = 13;
//--------------------VIBRACALL---------------------------------------------------------------------------------------------------------
int estadovibracall = 0, vibracall = 9;
//-----------------------SOM------------------------------------------------------------------------------------------------------------
int som = 10, estadosom = 0;
//----------------------BOTOES----------------------------------------------------------------------------------------------------------
int pagina = 0, posicaocursor = 1, cima = 0, baixo = 2, ok = 1, trocamenu = 0;
//-----------------CONTROLE DE TEMPO----------------------------------------------------------------------------------------------------
int tempologo = 2000, tempobotao = 300, tempointervalomanual, horas = 0 ,minutos = 0,  tempodeintervalologo = 1000, intervalomanual = 5;
long intervalopomodoro = 10000, deltat = 0 ,tempomanual, tempopomodoro = 10000;                  // TEMPO CORRETO DO POMODORO =  1500000
//--------------------AUXILIARES--------------------------------------------------------------------------------------------------------
int z=0, i=0,j=0;   
//------------RESUMO DOS PINOS NO ARDUINO:--------------------------------------------------------------------------------------------------------
//PINOS: 0 - cima
//PINOS: 1 - ok
//PINOS: 2 - baixo
//PINOS: 3 - LCD
//PINOS: 4 - LCD
//PINOS: 5 - LCD
//PINOS: 6 - LCD
//PINOS: 7 - LCD
//PINOS: 8 - ledtela
//PINOS: 9 - vibracall
//PINOS:10 - som
//PINOS:11 - servo
//PINOS:12 - ledvermelho
//PINOS:13 - ledverde

// ****************************************EH NECESSARIO AJUSTAR TODOS OS TEMPOS PARA O PROJETO FINAL!!!******************************************************

//--------------DECLARACAO DAS IMAGENS UFG E EMC----------------------------------------------------------------------------------------

/*PARA CRIAR O CODIGO DESSAS IMAGENS EH NECESSARIO VERIFICAR AS INSTRUCOES NO SITE
https://lastminuteengineers.com/nokia-5110-lcd-arduino-tutorial/ ONDE SE ENSINA COMO 
USAR CORRETAMENTE O LCD DA NOKIA, E TAMBEM FAZER AS CONVERSOES DE IMAGEM PARA BMP 
84X48 E APOS PARA O CODIGO HEXADECIMAL COMO APRSENTADO ABAIXO. A CONVERSAO DA IMAGEM
EH FEITA NO SITE http://javl.github.io/image2cpp/ . BASICAMENTE, UTILIZOU-SE O GIMP
PARA REDIMENSIONAR QUALQUER IMAGEM PARA O TAMANHO 84X48 (MEDIDA NECESSARIA DEVIDO AO 
TAMANHO DO LCD DA NOKIA), INDEXAR A MIAGEM PARA 1 BIT POR PIXEL E EXPORTAR NO FORMATO 
BMP. APOS ISSO, ACESSA-SE O ULTIMO  SITE MENCIONADO PARA PROCEDER A CONVERSAO. EH 
IMPORTANTE SEGUIR OS PARAMETROS DE CONVERSAO EXPLICADOS NO PRIMEIRO SITE.*/

// IMAGEM EXADECIMAL LOGO 'ufg', 84x48px
const unsigned char ufg [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x61, 0xff, 0xe0, 0xf0, 0x0f, 0x0f, 0xff, 0x00, 0xff, 0xc0, 0x00, 0xf9, 0xff, 0xe0, 0xf0, 0x0f, 
  0x0f, 0xff, 0x03, 0xff, 0xc0, 0x01, 0xf9, 0xff, 0xe0, 0xf0, 0x0f, 0x0f, 0xff, 0x07, 0xff, 0xc0, 
  0x01, 0xf9, 0xff, 0xe0, 0xf0, 0x0f, 0x0f, 0x80, 0x0f, 0xe0, 0xc0, 0x01, 0xf9, 0xff, 0xe0, 0xf0, 
  0x0f, 0x0f, 0x00, 0x0f, 0x80, 0x00, 0x01, 0xf8, 0x7f, 0x80, 0xf0, 0x0f, 0x0f, 0x00, 0x1f, 0x00, 
  0x00, 0x01, 0xf8, 0x3f, 0x00, 0xf0, 0x0f, 0x0f, 0x00, 0x1e, 0x00, 0x00, 0x04, 0x60, 0x0c, 0x80, 
  0xf0, 0x0f, 0x0f, 0x00, 0x1e, 0x00, 0x00, 0x0f, 0x00, 0x01, 0xe0, 0xf0, 0x0f, 0x0f, 0xfe, 0x3e, 
  0x00, 0x00, 0x3f, 0x80, 0x07, 0xf0, 0xf0, 0x0f, 0x0f, 0xfe, 0x3e, 0x0f, 0xe0, 0x7f, 0xc0, 0x07, 
  0xf0, 0xf0, 0x0f, 0x0f, 0xfe, 0x3e, 0x0f, 0xe0, 0x7f, 0xc0, 0x07, 0xf0, 0xf0, 0x0f, 0x0f, 0xfe, 
  0x3e, 0x0f, 0xe0, 0x7f, 0xc0, 0x07, 0xf0, 0xf8, 0x0f, 0x0f, 0x00, 0x3e, 0x01, 0xe0, 0x7f, 0xc0, 
  0x03, 0xf0, 0xf8, 0x0f, 0x0f, 0x00, 0x1e, 0x01, 0xe0, 0x7f, 0xc0, 0x01, 0xe0, 0x78, 0x1f, 0x0f, 
  0x00, 0x1f, 0x01, 0xe0, 0x3f, 0x80, 0x08, 0x80, 0x78, 0x1e, 0x0f, 0x00, 0x1f, 0x81, 0xe0, 0x0e, 
  0x00, 0x1e, 0x00, 0x7c, 0x3e, 0x0f, 0x00, 0x0f, 0xe1, 0xe0, 0x00, 0x1c, 0x7f, 0x00, 0x3f, 0xfc, 
  0x0f, 0x00, 0x07, 0xff, 0xe0, 0x00, 0x3e, 0xff, 0x80, 0x3f, 0xfc, 0x0f, 0x00, 0x03, 0xff, 0xe0, 
  0x00, 0x3e, 0xff, 0x80, 0x0f, 0xf0, 0x0f, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x3e, 0x7f, 0x80, 0x03, 
  0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
//IMAGEM EXADECIMAL LOGO 'emc', 84x48px
const unsigned char emc [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
  0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x03, 0xfe, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 
  0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x38, 0x00, 0x00, 0xff, 
  0x70, 0x00, 0x00, 0x00, 0x3e, 0x01, 0xff, 0xff, 0xf8, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0xf0, 
  0x0f, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x03, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xe0, 
  0x7f, 0xff, 0xe0, 0x00, 0x0f, 0x81, 0xff, 0x3f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0x00, 0x1e, 
  0x0f, 0xff, 0x3f, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf0, 0x00, 0x7c, 0x1f, 0xfe, 0x1f, 0xff, 0xff, 
  0xfc, 0xff, 0xff, 0xf0, 0x00, 0xf8, 0x7f, 0xfe, 0x1f, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xe0, 0x01, 
  0xf0, 0xff, 0xfc, 0xcf, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xc0, 0x01, 0xe1, 0xff, 0xf8, 0xc7, 0x80, 
  0xff, 0xfe, 0x3f, 0xff, 0x00, 0x03, 0xe3, 0xff, 0xf9, 0xe0, 0x0f, 0xff, 0xfc, 0x0f, 0xfc, 0x00, 
  0x1f, 0xf3, 0xfc, 0xf3, 0xe0, 0xff, 0xff, 0xf8, 0x0f, 0xf0, 0x00, 0x3f, 0xfb, 0xff, 0x63, 0xff, 
  0xff, 0xff, 0xf0, 0x1f, 0xe0, 0x00, 0x7f, 0xfb, 0xff, 0x87, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0xc0, 
  0x00, 0x7f, 0xf9, 0xff, 0xcf, 0xff, 0xff, 0xff, 0x80, 0x7f, 0x80, 0x00, 0x7f, 0xf1, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0xff, 0x00, 0x00, 0x3f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x01, 0xfc, 
  0x00, 0x00, 0x01, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xf8, 0x00, 0x00, 0x00, 0xf0, 0x0f, 
  0xff, 0xff, 0xff, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x3c, 0x00, 0xff, 0xff, 0xe0, 0x00, 0x7f, 
  0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x07, 0xf0, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x07, 
  0x80, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xfe, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x1f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xf8, 0xff, 
  0xc0, 0x00, 0xff, 0xc3, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xf8, 0xff, 0xe0, 0x01, 0xff, 0xc7, 0xff, 
  0xff, 0xf0, 0x7c, 0x00, 0x00, 0xf9, 0xf0, 0x03, 0xe7, 0xc7, 0xc0, 0x01, 0xe0, 0x7c, 0x00, 0x00, 
  0xf8, 0xf8, 0x07, 0xc7, 0xc7, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0xf0, 0xf8, 0x7c, 0x0f, 0x87, 0xc7, 
  0xc0, 0x00, 0x00, 0x7f, 0xff, 0xf0, 0xf8, 0x3e, 0x1f, 0x07, 0xc7, 0xc0, 0x00, 0x00, 0x7c, 0x00, 
  0x00, 0xf8, 0x1f, 0x3e, 0x07, 0xc7, 0xc0, 0x00, 0x00, 0x7c, 0x00, 0x00, 0xf8, 0x0f, 0xfc, 0x07, 
  0xc7, 0xc0, 0x00, 0x00, 0x7c, 0x00, 0x00, 0xf8, 0x07, 0xf8, 0x07, 0xc7, 0xc0, 0x01, 0xf0, 0x7f, 
  0xff, 0xf8, 0xf8, 0x03, 0xf0, 0x07, 0xc7, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0xf8, 0xf8, 0x01, 0xe0, 
  0x07, 0x83, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
//--------------INICIO DO SETUP------------------------------------------------------------------------------

void setup()   {
  
  pinMode(baixo, INPUT_PULLUP); //
  pinMode(ok, INPUT_PULLUP);    // DEFININDO OS BOTOES NAS PORTAS 0,1 E 2.
  pinMode(cima, INPUT_PULLUP);  //
  pinMode(ledtela, OUTPUT);         //ACIONA O LED DA TELA
  pinMode(vibracall, OUTPUT);   //ACIONA O VIBRACALL
  pinMode(som, OUTPUT);
  pinMode(ledvermelho, OUTPUT);
  pinMode(ledverde, OUTPUT);
  
  digitalWrite(ledtela,LOW);        //LIGA O LED DO LCD AO INICIAR O SISTEMA
  digitalWrite(ledvermelho,LOW);    //LIGA O LED VERMELHO AO INICIAR O SISTEMA
  digitalWrite(ledverde,LOW);       //LIGA O LED VERDE AO INICIAR O SISTEMA
  
  trinca.attach(servo);         //LIGA O SERVO AO PINO 11
  trinca.write(aberto);//POSICIONA A TRANCA NA POSICAO ABERTA: 0 GRAU
  // ACIONA O VIBRACALL POR 2s <=======================================================*******POR FAZER*******============================================


  
  Serial.begin(9600);

  //Inicia o Display
  display.begin();

  // limpa o buffer.
  display.clearDisplay();

  // ajusta o contraste para o valor inicial de 60.
  display.setContrast(60);

  //--------------APRESENTAÇOES------------------------------------------------------------------------------

  //APRESENTAÇAO DO "LOGO DA UFG"
  display.drawBitmap(0, 0,  ufg, 84, 48, BLACK);
  display.display();
  delay(tempologo);
  display.clearDisplay();//FIM DO LOGO UFG

  display.display();//INTERVALO SEM NENHUMA IMAGEM
  delay(tempodeintervalologo);

  //APRESENTAÇAO DO "LOGO DA EMC"
  display.drawBitmap(0, 0,  emc, 84, 48, BLACK);
  display.display();
  delay(tempologo);
  display.clearDisplay();
  display.display();
  delay(tempodeintervalologo);//FIM DO LOGO EMC
  
  //APRESENTAÇAO DA PRIMEIRA PARTE DO "TRANCA FONE"
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,8);
  display.println("    TRANCA    ");
  display.display();
  delay(500);
  display.setCursor(0,16);
  display.println("     FONE     ");
  display.display();
  delay(500);
  
  for(z=0;z<=2;z++){
  display.clearDisplay();
  display.setCursor(0,8);
  display.println("    TRANCA    ");
  display.display();
  display.setCursor(0,16);
  display.println("     FONE     ");
  display.display();
  delay(500);
  display.clearDisplay();
  display.setCursor(0,8);
  display.println(" |||TRANCA||| ");
  display.display();
  display.setCursor(0,16);
  display.println(" ||| FONE ||| ");
  display.display();
  delay(500);
  }
  delay(tempodeintervalologo);//INTERVALO ANTES DA FRASE DE EFEITO

  //APRESENTAÇAO DA FRASE DE EFEITO
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(9,32);
  display.println("De um tempo");
  display.setCursor(9,40);
  display.println("a si mesmo!");
  display.display();
  delay(2*tempologo);
  display.clearDisplay();//FIM DAS APRESENTAÇOES
  
  digitalWrite(ledvermelho,HIGH);    //LIGA O LED VERMELHO SE DESLIGA E SOMENTE O VERDE PERMANECE ACESO, DEMONSTRANDO QUE A PORTA ESTA ABERTA
}
  

//------------------FIM DO SETUP E INICIO DO LOOP------------------------------------------------------------------------------


void loop() {
//==================================================================================================================  
//--------------------------------------------MENU INICIAL CASE 0---------------------------------------------------
//==================================================================================================================

//AS PAGINAS SERAO TROCADAS DE ACORDO COM O VALOR ATRIBUIO A VARIAVEL 'pagina'
// A VARIAVEL 'pagina' INICIA-SE EM 0 NA SUA DECLARACAO. O CASE 0 EH O MENU INICIAL, OS MENUS SUBSEQUENTES SERAO 1,2,3,4...
  
  if(estadoled==0){                //VERIFICA O VALOR DA VARIAVEL 'estadoled' E LIGA OU DESLIGA O LED DO DISPLAY
    digitalWrite(ledtela,HIGH);
  }
  else{
    digitalWrite(ledtela,LOW);
  }
  switch (pagina){
  
  case 0:
  trocamenu = 0;
  i=0;//VARIAVEL AUXILIAR PARA PERMITIR APRESENTAR SOMENTE UMA VEZ O TEXTO INICIAL NO MENU POMODORO
 
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println(" MENU INICIAL");
  display.drawFastHLine(0,10,83,BLACK);    //DESENHAR UMA LINHA DA COLINA ZERO NA LINHA 10 ATE A COLUNA 83 PERCORRENDO TODO MONITOR
  
//---------------------AQUI INICIA-SE A DOIDERA!!!!!------------------------------------------------------------------------------
  if(posicaocursor==1){
    display.setCursor(0, 16); 
    display.setTextColor(WHITE,BLACK);
    display.println("1- POMODORO   ");}
  else{
     display.setCursor(0, 16); 
     display.setTextColor(BLACK,WHITE);
     display.println("1- POMODORO   ");}
  
  if(posicaocursor==2){
     display.setCursor(0, 24); 
     display.setTextColor(WHITE,BLACK);
     display.println("2- MODO MANUAL");}
  else{
     display.setCursor(0, 24); 
     display.setTextColor(BLACK,WHITE);
     display.println("2- MODO MANUAL");}   
  
  if(posicaocursor==3){
     display.setCursor(0, 32); 
     display.setTextColor(WHITE,BLACK);
     display.println("3- CONFIG     ");}
  else{
     display.setCursor(0, 32); 
     display.setTextColor(BLACK,WHITE);
     display.println("3- CONFIG     ");}
  
  display.display(); //APOS A DEFINICAO DE ONDE ESTA O CURSOR NA SOLUCAO DOS IF/ELSE, SERA IMPRESSO O RESTANTE DESSE MENU ANTERIOR.
  
  if(digitalRead(cima) == LOW){  // CASO O BOTAO 'cima' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI AUMENTAR EM UMA UNIDADE
      posicaocursor++;
      if(posicaocursor > 3){
        posicaocursor=1;}
      delay(tempobotao);}               //ESTE INTERVALO EH IMPORTANTE PARA NAO HAVER DOIS ACIONAMENTOS CONSECUTIVOS INDESEJADOS DEVIDO A TREPIDACAO NO BOTAO
      
  if(digitalRead(baixo) == LOW){ // CASO O BOTAO 'baixo' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI DIMINUIR EM UMA UNIDADE
      posicaocursor--;
      if(posicaocursor < 1){
        posicaocursor = 3;}
      delay(tempobotao);}
      
  if(digitalRead(ok) == LOW){
    trocamenu = 1;
    delay(tempobotao);
  }
  //O PROGRAMA VAI VERIFICAR SE O BOTAO OK FOI PRESSINADO E QUAL O VALOR DA VARIAVEL 'posicaocursor', ASSIM VAI DEFINIR O VALOR DE PAGINA PARA A TROCA DO SWITCH CASE.
  
  if(trocamenu==1 && posicaocursor==1){
    pagina = 1;    // VAI PARA A PAGINA DO POMODORO.
    trocamenu = 0;
  }
  
  else if(trocamenu==1 && posicaocursor==2){
    pagina = 2; // VAI PARA A PAGINA DE AJUSTE MANUAL.
    trocamenu =0;
    posicaocursor = 1;

  }
  
  else if(trocamenu==1 && posicaocursor==3){
    pagina = 3; // VAI PARA A PAGINA DE CONFIGURAÇOES
    trocamenu = 0;
    posicaocursor = 1;

  }
  else{
    pagina = 0; // PERMANECE NO MENU INICIAL
  }
  delay(10);
  display.clearDisplay();
  
  
  break;
  
//==================================================================================================================  
//--------------------------------------------MENU POMODORO - CASE 1------------------------------------------------
//==================================================================================================================

  case 1:                                       //VALOR 1 PARA A VARIAVEL 'pagina'
  trocamenu = 0;

  
  while(i<1){                                   // LAÇO WHILE PARA ESSA MENSAGEM APRESENTAR-SE SOMENTE UMA VEZ QUANDO O MENU FOR ABERTO,
  trocamenu=0;                                  //i INICIA-SE EM 0, QUANDO i RECEBER VALOR 1, ESSA MENSAGEM NAO SERA MAIS APRESENTADA.
  posicaocursor = 1;                            //'trocamenu' E 'posicacursor' INICIAM-SE ENTRO DO LAÇO WHILE COMO VALOR INICIAL 0 E 1, 
  display.setTextSize(1);                       //E ESTAO AQUI DENTRO PARA O VALOR NAO SER ATUALIZADO A CADA RENOVAÇAO DO LOOP
  display.setTextColor(BLACK);                   
  display.setCursor(0,0);
  display.println("   POMODORO   ");
  display.drawFastHLine(0,10,83,BLACK);
  display.setCursor(0,16);
  display.println("  Insira seu\n  celular na\n caixa e feche\n   a tampa.");
  display.display();
  delay(tempologo);
  i++;}
  display.clearDisplay();                //FIM DA MENSAGEM INICIAL DO MENU POMODORO, PASSA-SE AGORA PARA AS OPÇOES NO MENU POMODORO.

  
  display.setTextSize(1);                //CABEÇALHO DO MENU POMODORO
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("   POMODORO   ");
  display.drawFastHLine(0,10,83,BLACK);
  
  if(posicaocursor==1){                  //CURSOR NA POSIÇAO 1.
    display.setCursor(0, 16); 
    display.setTextColor(WHITE,BLACK);
    display.println("1- TRANCAR     ");}
  else{
     display.setCursor(0, 16); 
     display.setTextColor(BLACK,WHITE);
     display.println("1- TRANCAR    ");}
  
  if(posicaocursor==2){                  //CURSOR NA POSIÇAO 2.
     display.setCursor(0, 24); 
     display.setTextColor(WHITE,BLACK);
     display.println("2- VOLTAR     ");}
  else{
     display.setCursor(0, 24); 
     display.setTextColor(BLACK,WHITE);
     display.println("2- VOLTAR     ");}
  
  display.display();                    //APOS AVERIGUACAO DOS IF/ELSE APRESENTA-SE O MENU NO DISPLAY
  
   if(digitalRead(cima) == LOW){        // CASO O BOTAO 'cima' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI AUMENTAR EM UMA UNIDADE
      posicaocursor++;
      if(posicaocursor > 2){
        posicaocursor=1;}
      delay(tempobotao);}
      
  if(digitalRead(baixo) == LOW){        // CASO O BOTAO 'baixo' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI DIMINUIR EM UMA UNIDADE.
      posicaocursor--;
      if(posicaocursor < 1){
        posicaocursor = 2;}
      delay(tempobotao);}
      
  if(digitalRead(ok) == LOW){          // CASO O BOTAO 'ok' SEJA ACIONADO, O VALOR DE 'trocamenu'  RECEBE 1.
    trocamenu = 1;
    delay(tempobotao);
  }
  
  if(trocamenu==1 && posicaocursor==1){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("     PORTA\n   TRANCADA!");
    display.display();
    trinca.write(fechado);               // ACIONAMENTO DO SERVO PARA FECHAR
    digitalWrite(ledverde,HIGH);         //LED VERDE DESLIGADO
    digitalWrite(ledvermelho,LOW);       //LED VERMELHO TRANCADO
    delay(tempopomodoro);                   //PERMANECE COM A PORTA TRANCADA POR 25 MINUTOS.
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("     TEMPO\n   ESGOTADO!");
    display.display();
    for(i=0;i<2;i++){                      //ACIONA O VIBRACALL 2X 3X E PISCA O LED VERMELHO 2X 3X
    for(z=0;z<=3;z++){
      analogWrite(vibracall,255);
      digitalWrite(ledvermelho,LOW);    //LIGA O LED VERMELHO
      delay(400);
      analogWrite(vibracall,0);
      digitalWrite(ledvermelho,HIGH);    //DESLIGA LIGA O LED VERMELHO
      delay(150);
    }
    }
    digitalWrite(ledvermelho,LOW);    //LIGA O LED VERMELHO

    delay(3000);
    display.clearDisplay();
    
    pagina = 4; // SUBPAGINA DO MENU POMODORO ONDE SERA QUESTIONADO AO USUARIO SE ELE DESEJA MAIS UMA CICLO DE POMODORO ANTES DE ABRIR A CAIXA
    trocamenu = 0;
  }
  
  else if(trocamenu==1 && posicaocursor==2){
    pagina = 0; // VAI PARA A PAGINA INICIAL.
    trocamenu = 0;
    posicaocursor = 1;
  }
  else{
    pagina = 1; // PERMANECE NO MENU POMODORO
  }
  delay(10);
  display.clearDisplay();
  
  break;
  
//==================================================================================================================  
//--------------------------------------------SUB MENU A POMODORO - CASE 4------------------------------------------
//==================================================================================================================
  
  case 4:
  display.setTextSize(1);                //CABEÇALHO DO MENU POMODORO
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("  NOVO CICLO?");
  display.drawFastHLine(0,10,83,BLACK);
  
  if(posicaocursor==1){                  //CURSOR NA POSIÇAO 1.
    display.setCursor(0, 16); 
    display.setTextColor(WHITE,BLACK);
    display.println("1- SIM         ");
  }
  else{
     display.setCursor(0, 16); 
     display.setTextColor(BLACK,WHITE);
     display.println("1- SIM        ");
   }
  if(posicaocursor==2){                  //CURSOR NA POSIÇAO 2.
     display.setCursor(0, 24); 
     display.setTextColor(WHITE,BLACK);
     display.println("2- NAO        ");
   }
  else{
     display.setCursor(0, 24); 
     display.setTextColor(BLACK,WHITE);
     display.println("2- NAO        ");
   }
  
  display.display();
  
   if(digitalRead(cima) == LOW){  // CASO O BOTAO 'cima' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI AUMENTAR EM UMA UNIDADE
      posicaocursor++;
      if(posicaocursor > 2){
        posicaocursor=1;}
      delay(tempobotao);
    }
      
  if(digitalRead(baixo) == LOW){ // CASO O BOTAO 'baixo' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI DIMINUIR EM UMA UNIDADE.
      posicaocursor--;
      if(posicaocursor < 1){
        posicaocursor = 2;}
      delay(tempobotao);
    }
      
  if(digitalRead(ok) == LOW){  // CASO O BOTAO 'ok' SEJA ACIONADO, O VALOR DE 'trocamenu'  RECEBE 1.
    trocamenu = 1;
    delay(tempobotao);
   }
  
  if(trocamenu==1 && posicaocursor==1){   //NESTA OPCAO O USUARIO DECIDIU POR MAIS UM CICLO E SERA ENCAMINHADO PARA A CONDICAO 
    display.clearDisplay();
    display.setTextSize(1);               //DE ANTES DE COLOCAR O CELULAR NA CAIXA DO MENU POMODORO APOS E MINUTOS DE INTERVALO
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("   LIBERANDO\n  A PORTA...");
    display.display();
    delay(2000);
    
    trinca.write(aberto);                  //ACIONAMENTO O SERVO-MOTOR PARA ABRIR
    digitalWrite(ledvermelho,HIGH);        //DESLIGA LIGA O LED VERMELHO
    digitalWrite(ledverde,LOW);            //LIGA O LED VERDE E DESLIGA O VERMELHO, DEMONSTRANDO QUE A PORTA ESTA ABERTA 
    display.clearDisplay();
    
    display.setTextSize(1);               //DE ANTES DE COLOCAR O CELULAR NA CAIXA DO MENU POMODORO APOS E MINUTOS DE INTERVALO
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("     PORTA\n   LIBERADA!");
    display.display();
    delay(3000);
    display.clearDisplay();
    pagina = 5;
    trocamenu = 0;
    posicaocursor = 1;
  }
    else if(trocamenu == 1 && posicaocursor == 2){
    display.clearDisplay();
    display.setTextSize(1);               //DE ANTES DE COLOCAR O CELULAR NA CAIXA DO MENU POMODORO APOS E MINUTOS DE INTERVALO
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("   LIBERANDO\n  A PORTA...");
    display.display();
    delay(2000);
    trinca.write(aberto);                  //ACIONAMENTO O SERVO-MOTOR PARA ABRIR
    display.clearDisplay();
    display.setTextSize(1);               //DE ANTES DE COLOCAR O CELULAR NA CAIXA DO MENU POMODORO APOS E MINUTOS DE INTERVALO
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("     PORTA\n   LIBERADA!");
    display.display();
    delay(3000);
    display.clearDisplay();
       pagina = 0;
       posicaocursor = 1;
       trocamenu = 0;
    }
    else{
      pagina = 4;
    }  
  delay(10);
  display.clearDisplay();
  break;
 
//NESSE PONTO INICIA-SE UM LACO WHILE COM A FUNCAO MILIS() PARA CONTAR 5 MINUTOS E O USUARIO PODER CANCELAR OU ANTECIPAR O CICLO ANTES DE FINALIZAR OS 5 MINUTOS 

//==================================================================================================================  
//--------------------------------------------SUB MENU B POMODORO - CASE 5------------------------------------------
//==================================================================================================================
    
    case 5: 
    
    deltat = 0;
    while(deltat < intervalopomodoro && trocamenu==0){   //ENQUANTO O TEMPO INICIAL FOR MENOR QUE O TEMPO INICIAL MAIS 5 MINUTOS, FAÇA:
        display.setTextSize(1);                //CABEÇALHO DE NOVO CICLO
        display.setTextColor(BLACK);
        display.setCursor(0,0);
        display.println("  NOVO CICLO");
        display.drawFastHLine(0,10,83,BLACK);
  
        if(posicaocursor==1){                  //CURSOR NA POSIÇAO 1.
            display.setCursor(0, 16); 
            display.setTextColor(WHITE,BLACK);
            display.println("1- ANTECIPAR  ");}
        else{
            display.setCursor(0, 16); 
            display.setTextColor(BLACK,WHITE);
            display.println("1- ANTECIPAR  ");}
  
        if(posicaocursor==2){                  //CURSOR NA POSIÇAO 2.
            display.setCursor(0, 24); 
            display.setTextColor(WHITE,BLACK);
            display.println("2- CANCELAR   ");}
        else{
            display.setCursor(0, 24); 
            display.setTextColor(BLACK,WHITE);
            display.println("2- CANCELAR   ");}
        
  
    display.display();
  
    if(digitalRead(cima) == LOW){  // CASO O BOTAO 'cima' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI AUMENTAR EM UMA UNIDADE
        posicaocursor++;
        if(posicaocursor > 2){
            posicaocursor=1;}
        delay(tempobotao);
     }
      
    if(digitalRead(baixo) == LOW){ // CASO O BOTAO 'baixo' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI DIMINUIR EM UMA UNIDADE.
        posicaocursor--;
        if(posicaocursor < 1){
            posicaocursor = 2;}
        delay(tempobotao);
     }
      
    if(digitalRead(ok) == LOW){  // CASO O BOTAO 'ok' SEJA ACIONADO, O VALOR DE 'trocamenu'  RECEBE 1.
        trocamenu = 1;
        delay(tempobotao);
    }
  
    if(trocamenu==1 && posicaocursor==1){
        pagina = 1; // RETORNA AO MENU POMODORO
        i=0;        // PERMITE A MENSAGEM DE COLOCAR O CELULAR DENTRO DA CAIXA SEJA APRESENTADA
    }
  
  else if(trocamenu==1 && posicaocursor==2){
    pagina = 0; // VAI PARA A PAGINA DE colocque seu celular novamente na
    posicaocursor = 1;

  }
  else{
    pagina = 5; // PERMANECE NO MENU INICIAL
  }
  
  deltat = deltat + 500;
  display.clearDisplay();
  delay(500);
  }
  display.setTextSize(1);                //INFORMA QUE O TEMPO FOI FINALIZADO E RETORNARA AO MENU INICIAL
  display.setTextColor(BLACK);
  display.setCursor(0,16);
  display.println("     TEMPO\n  DE DESCANSO\n   ESGOTADO");
  display.display();
  for(i=0;i<2;i++){                      //ACIONA O VIBRACALL 2X 3X E PISCA O LED VERMELHO 2X 3X
    for(z=0;z<=3;z++){
      analogWrite(vibracall,255);
      digitalWrite(ledvermelho,LOW);    //LIGA O LED VERMELHO SE DESLIGA E SOMENTE O VERDE PERMANECE ACESO, DEMONSTRANDO QUE A PORTA ESTA ABERTA
      delay(400);
      analogWrite(vibracall,0);
      digitalWrite(ledvermelho,HIGH);    //LIGA O LED VERMELHO SE DESLIGA E SOMENTE O VERDE PERMANECE ACESO, DEMONSTRANDO QUE A PORTA ESTA ABERTA
      delay(150);
    }
    }
  delay(3000);
  pagina = 1;
  trocamenu = 0;
  posicaocursor = 1;
  delay(10);
  display.clearDisplay();
break;

//==================================================================================================================  
//--------------------------------------------MENU CONFIGURACOES - CASE 3------------------------------------------
//==================================================================================================================
  
  case 3:
  trocamenu=0;
  display.setTextSize(1);                //CABEÇALHO DO MENU POMODORO
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println(" CONFIGURACOES");
  display.drawFastHLine(0,10,83,BLACK);
  
  if(posicaocursor==1 && estadoled == 0){                  //CURSOR NA POSIÇAO 1.
    display.setCursor(0, 16); 
    display.setTextColor(WHITE,BLACK);
    display.println("1- LED DESLIGA");
  }
  else if(posicaocursor==1 && estadoled ==1){
     display.setCursor(0, 16); 
     display.setTextColor(WHITE,BLACK);
     display.println("1- LED LIGADO ");
   }
   else{
     if(estadoled == 0){
     display.setCursor(0, 16); 
     display.setTextColor(BLACK,WHITE);
     display.println("1- LED DESLIGA");}
     else{
       display.setCursor(0, 16); 
     display.setTextColor(BLACK,WHITE);
     display.println("1- LED LIGADO ");}
   }
   if(posicaocursor==2 && estadosom == 0){                  //CURSOR NA POSIÇAO 1.
    display.setCursor(0, 24); 
    display.setTextColor(WHITE,BLACK);
    display.println("2- SOM DESLIGA");
  }
  else if(posicaocursor==2 && estadosom ==1){
     display.setCursor(0, 24); 
     display.setTextColor(WHITE,BLACK);
     display.println("2- SOM LIGADO ");
   }
   else{
     if(estadosom == 0){
     display.setCursor(0, 24); 
     display.setTextColor(BLACK,WHITE);
     display.println("2- SOM DESLIGA");}
     else{
       display.setCursor(0, 24); 
     display.setTextColor(BLACK,WHITE);
     display.println("2- SOM LIGADO ");}
   }
   
   if(posicaocursor==3 && estadovibracall == 0){                  //CURSOR NA POSIÇAO 1.
    display.setCursor(0, 32); 
    display.setTextColor(WHITE,BLACK);
    display.println("3- TREME DESLI");
  }
  else if(posicaocursor==3 && estadovibracall ==1){
     display.setCursor(0, 32); 
     display.setTextColor(WHITE,BLACK);
     display.println("3- TREME LIGA ");
   }
   else{
     if(estadovibracall == 0){
     display.setCursor(0, 32); 
     display.setTextColor(BLACK,WHITE);
     display.println("3- TREME DESLI");}
     else{
       display.setCursor(0, 32); 
     display.setTextColor(BLACK,WHITE);
     display.println("3- TREME LIGA ");}
   }
   
    if(posicaocursor == 4){                  //CURSOR NA POSIÇAO 3.
    display.setCursor(0, 40); 
    display.setTextColor(WHITE,BLACK);
    display.println("4- VOLTAR     ");
  }
  else{
     display.setCursor(0, 40); 
     display.setTextColor(BLACK,WHITE);
     display.println("4- VOLTAR     ");
  }
  display.display();

  
  
   if(digitalRead(cima) == LOW){  // CASO O BOTAO 'cima' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI AUMENTAR EM UMA UNIDADE
      posicaocursor++;
      if(posicaocursor > 4){
        posicaocursor=1;}
      delay(tempobotao);
    }
      
  if(digitalRead(baixo) == LOW){ // CASO O BOTAO 'baixo' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI DIMINUIR EM UMA UNIDADE.
      posicaocursor--;
      if(posicaocursor < 1){
        posicaocursor = 4;}
      delay(tempobotao);
    }
      
  if(digitalRead(ok) == LOW){  // CASO O BOTAO 'ok' SEJA ACIONADO, O VALOR DE 'trocamenu'  RECEBE 1.
    trocamenu = 1;
    delay(tempobotao);
   }
  
  
  if(trocamenu==1 && posicaocursor==1){   //NESTA OPCAO O USUARIO DECIDIU POR MAIS UM CICLO E SERA ENCAMINHADO PARA A CONDICAO 
    estadovibracall++;
    if(estadovibracall == 1){        
      analogWrite(vibracall,255); //ACIONA O VIBRACALL 1X
      delay(500);
      analogWrite(vibracall,0);
      delay(100);  
    }
    if(estadoled>1){
    estadoled=0;
  }
  }
  else if(trocamenu == 1 && posicaocursor == 2){
     estadosom++;
    if(estadosom>1){
    estadosom=0;
  }
  }
    else if(trocamenu == 1 && posicaocursor == 3){
     estadovibracall++;
    if(estadovibracall>1){
    estadovibracall=0;
  }
  }
    else if(trocamenu == 1 && posicaocursor == 4){
      pagina = 0;
      trocamenu = 0;
      posicaocursor = 1;
      display.clearDisplay();
    }
    else{
      pagina = 3;
    }  
  delay(10);
  display.clearDisplay();
  break;
  
//==================================================================================================================  
//--------------------------------------------MENU AJUSTE MANUAL - CASE 2------------------------------------------
//==================================================================================================================
  
  case 2:
  trocamenu=0;
  display.setTextSize(1);                //CABEÇALHO DO MENU POMODORO
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println(" MODO MANUAL");
  display.drawFastHLine(0,10,83,BLACK);
  
  if(posicaocursor==1){                  //CURSOR NA POSIÇAO 1.
    display.setCursor(0, 16); 
    display.setTextColor(WHITE,BLACK);
    display.print("1- HORAS:   ");
    display.println(horas);
  }
  else{                  //CURSOR NA POSIÇAO 1.
    display.setCursor(0, 16); 
    display.setTextColor(BLACK,WHITE);
    display.print("1- HORAS:   ");
    display.println(horas);
  }
  if(posicaocursor==2){
     display.setCursor(0, 24-j); 
     display.setTextColor(WHITE,BLACK);
     display.print("2- MINUTOS: ");
     display.println(minutos);
   }
   else{
     display.setCursor(0, 24-j); 
     display.setTextColor(BLACK,WHITE);
     display.print("2- MINUTOS: ");
     display.println(minutos);
   }
   if(posicaocursor==3){                  //CURSOR NA POSIÇAO 1.
    display.setCursor(0, 32-j); 
    display.setTextColor(WHITE,BLACK);
    display.print("3- INTERVAL:");
    display.println(intervalomanual);
  }
  else{                  //CURSOR NA POSIÇAO 1.
    display.setCursor(0, 32-j); 
    display.setTextColor(BLACK,WHITE);
    display.print("3- INTERVAL:");
    display.println(intervalomanual);
  }
   if(posicaocursor==4){
     display.setCursor(0, 40-j); 
     display.setTextColor(WHITE,BLACK);
     display.println("4- CONFIRMAR  ");
   }
   else{
     display.setCursor(0, 40-j); 
     display.setTextColor(BLACK,WHITE);
     display.println("4- CONFIRMAR  ");
   }
   if(posicaocursor==5){
     j=8;
     display.setCursor(0, 48-j); 
     display.setTextColor(WHITE,BLACK);
     display.println("5- VOLTAR     ");
  }
  else{
    j=0;
     display.setCursor(0, 48-j); 
     display.setTextColor(BLACK,WHITE);
     display.println("5- VOLTAR     ");
  }
  display.display();

  
  
   if(digitalRead(cima) == LOW){  // CASO O BOTAO 'cima' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI AUMENTAR EM UMA UNIDADE
      posicaocursor++;
      if(posicaocursor > 5){
        posicaocursor=1;}
      delay(tempobotao);
    }
      
  if(digitalRead(baixo) == LOW){ // CASO O BOTAO 'baixo' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI DIMINUIR EM UMA UNIDADE.
      posicaocursor--;
      if(posicaocursor < 1){
        posicaocursor = 5;}
      delay(tempobotao);
    }
      
  if(digitalRead(ok) == LOW){  // CASO O BOTAO 'ok' SEJA ACIONADO, O VALOR DE 'trocamenu'  RECEBE 1.
    trocamenu = 1;
    delay(tempobotao);
   }
  
  
  if(trocamenu==1 && posicaocursor==1){   //ACRESCENTA 1 HORA A CADA APERTO NO BOTAO
    horas++;
    if(horas>24){
    horas=0;
    } 
  }
   else if(trocamenu == 1 && posicaocursor == 2){ //ACRESCENTA 1 MINUTO A CADA APERTO NO BOTAO
     minutos++;
    if(minutos>60){
    minutos=0;
  }
   }
  else if(trocamenu == 1 && posicaocursor == 3){ //ACRESCENTA 1 MINUTO A CADA APERTO NO BOTAO
     intervalomanual++;
     tempointervalomanual = intervalomanual*60000;
    if(intervalomanual>30){
    intervalomanual=5;
  }
  }
    else if(trocamenu == 1 && posicaocursor == 4){ //OPCAO TRANCAR NO MODO MANUAL, VAI PARA PAGINA 6
      pagina = 6;
      trocamenu = 0;
      posicaocursor = 1;
      tempomanual = horas*3600000 + minutos*5000; //<=========================CORRIGIR MINUTOS======================================================================
      display.clearDisplay();
    }
    else if(trocamenu == 1 && posicaocursor == 5){ //OPCAO VOLTAR PARA MENU INICIAL
      pagina = 0;
      trocamenu = 0;
      posicaocursor = 1;
      display.clearDisplay();
    }
    else{
      pagina = 2;
    }
   
  delay(10);
  display.clearDisplay();
  break;
  
//==================================================================================================================  
//--------------------------------------------MENU MODO MANUAL - CASE 6---------------------------------------------
//==================================================================================================================

  case 6:                                       //VALOR 1 PARA A VARIAVEL 'pagina'
  trocamenu = 0;

  
  while(i<1){                                   // LAÇO WHILE PARA ESSA MENSAGEM APRESENTAR-SE SOMENTE UMA VEZ QUANDO O MENU FOR ABERTO,                            //'trocamenu' E 'posicacursor' INICIAM-SE ENTRO DO LAÇO WHILE COMO VALOR INICIAL 0 E 1, 
  display.setTextSize(1);                       //E ESTAO AQUI DENTRO PARA O VALOR NAO SER ATUALIZADO A CADA RENOVAÇAO DO LOOP
  display.setTextColor(BLACK);                   
  display.setCursor(0,0);
  display.println("  MODO MANUAL ");
  display.drawFastHLine(0,10,83,BLACK);
  display.setCursor(0,16);
  display.println("  Insira seu\n  celular na\n caixa e feche\n   a tampa.");
  display.display();
  delay(tempologo);
  i++;}
  display.clearDisplay();                //FIM DA MENSAGEM INICIAL DO MENU POMODORO, PASSA-SE AGORA PARA AS OPÇOES NO MENU POMODORO.

  
  display.setTextSize(1);                //CABEÇALHO DO MENU POMODORO
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("  MODO MANUAL");
  display.drawFastHLine(0,10,83,BLACK);
  
  if(posicaocursor==1){                  //CURSOR NA POSIÇAO 1.
    display.setCursor(0, 16); 
    display.setTextColor(WHITE,BLACK);
    display.println("1 - TRANCAR    ");}
  else{
     display.setCursor(0, 16); 
     display.setTextColor(BLACK,WHITE);
     display.println("1 - TRANCAR   ");}
  
  if(posicaocursor==2){                  //CURSOR NA POSIÇAO 2.
     display.setCursor(0, 24); 
     display.setTextColor(WHITE,BLACK);
     display.println("2 - VOLTAR    ");}
  else{
     display.setCursor(0, 24); 
     display.setTextColor(BLACK,WHITE);
     display.println("2 - VOLTAR    ");}
  
  display.display();                    //APOS AVERIGUACAO DOS IF/ELSE APRESENTA-SE O MENU NO DISPLAY
  
   if(digitalRead(cima) == LOW){        // CASO O BOTAO 'cima' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI AUMENTAR EM UMA UNIDADE
      posicaocursor++;
      if(posicaocursor > 2){
        posicaocursor=1;}
      delay(tempobotao);}
      
  if(digitalRead(baixo) == LOW){        // CASO O BOTAO 'baixo' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI DIMINUIR EM UMA UNIDADE.
      posicaocursor--;
      if(posicaocursor < 1){
        posicaocursor = 2;}
      delay(tempobotao);}
      
  if(digitalRead(ok) == LOW){          // CASO O BOTAO 'ok' SEJA ACIONADO, O VALOR DE 'trocamenu'  RECEBE 1.
    trocamenu = 1;
    delay(tempobotao);
  }
  
  if(trocamenu==1 && posicaocursor==1){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("     PORTA\n   TRANCADA!");
    display.display();
    trinca.write(fechado);               // ACIONAMENTO DO SERVO PARA FECHAR
    digitalWrite(ledverde,HIGH);         //LED VERDE DESLIGADO
    digitalWrite(ledvermelho,LOW);       //LED VERMELHO TRANCADO
    delay(tempomanual); //PERMANECE COM A PORTA TRANCADA POR 25 MINUTOS.
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("     TEMPO\n   ESGOTADO!");
    display.display();
    for(i=0;i<2;i++){                      //ACIONA O VIBRACALL 2X 3X E PISCA O LED VERMELHO 2X 3X
    for(z=0;z<=3;z++){
      analogWrite(vibracall,255);
      digitalWrite(ledvermelho,LOW);    
      delay(400);
      analogWrite(vibracall,0);
      digitalWrite(ledvermelho,HIGH);    
      delay(150);
    }
    }
    
    delay(3000);
    display.clearDisplay();
    
    pagina = 7; // SUBPAGINA DO MENU MODO MANUAL ONDE SERA QUESTIONADO AO USUARIO SE ELE DESEJA MAIS UMA CICLO DE POMODORO ANTES DE ABRIR A CAIXA
    trocamenu = 0;
    posicaocursor = 1;
  }
  
  else if(trocamenu==1 && posicaocursor==2){
    pagina = 2; // VAI PARA A PAGINA 2 - AJUSTE MANUAL.
    trocamenu = 0;
    posicaocursor = 1;
  }
  else{
    pagina = 6; // PERMANECE NO MENU POMODORO
  }
  delay(10);
  display.clearDisplay();
  
  break;
  
//=====================================================================================================================  
//--------------------------------------------SUB MENU A MODO MANUAL - CASE 7------------------------------------------
//=====================================================================================================================
  
  case 7:
  trocamenu=0;
  display.setTextSize(1);                //CABEÇALHO DO MENU POMODORO
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("  NOVO CICLO?");
  display.drawFastHLine(0,10,83,BLACK);
  
  if(posicaocursor==1){                  //CURSOR NA POSIÇAO 1.
    display.setCursor(0, 16); 
    display.setTextColor(WHITE,BLACK);
    display.println("1 - SIM        ");
  }
  else{
     display.setCursor(0, 16); 
     display.setTextColor(BLACK,WHITE);
     display.println("1 - SIM       ");
   }
  if(posicaocursor==2){                  //CURSOR NA POSIÇAO 2.
     display.setCursor(0, 24); 
     display.setTextColor(WHITE,BLACK);
     display.println("2 - NAO       ");
   }
  else{
     display.setCursor(0, 24); 
     display.setTextColor(BLACK,WHITE);
     display.println("2 - NAO       ");
   }
  
  display.display();
  
   if(digitalRead(cima) == LOW){  // CASO O BOTAO 'cima' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI AUMENTAR EM UMA UNIDADE
      posicaocursor++;
      if(posicaocursor > 2){
        posicaocursor=1;}
      delay(tempobotao);
    }
      
  if(digitalRead(baixo) == LOW){ // CASO O BOTAO 'baixo' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI DIMINUIR EM UMA UNIDADE.
      posicaocursor--;
      if(posicaocursor < 1){
        posicaocursor = 2;}
      delay(tempobotao);
    }
      
  if(digitalRead(ok) == LOW){  // CASO O BOTAO 'ok' SEJA ACIONADO, O VALOR DE 'trocamenu'  RECEBE 1.
    trocamenu = 1;
    delay(tempobotao);
   }
  
  if(trocamenu==1 && posicaocursor==1){   //NESTA OPCAO O USUARIO DECIDIU POR MAIS UM CICLO E SERA ENCAMINHADO PARA A CONDICAO 
    display.clearDisplay();
    display.setTextSize(1);               //DE ANTES DE COLOCAR O CELULAR NA CAIXA DO MENU POMODORO APOS E MINUTOS DE INTERVALO
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("   LIBERANDO\n  A PORTA...");
    display.display();
    delay(2000);
    
    trinca.write(aberto);                  //ACIONAMENTO O SERVO-MOTOR PARA ABRIR
    digitalWrite(ledvermelho,HIGH);        //DESLIGA LIGA O LED VERMELHO
    digitalWrite(ledverde,LOW);            //LIGA O LED VERDE E DESLIGA O VERMELHO, DEMONSTRANDO QUE A PORTA ESTA ABERTA 
    display.clearDisplay();
    
    display.setTextSize(1);                //DE ANTES DE COLOCAR O CELULAR NA CAIXA DO MENU POMODORO APOS E MINUTOS DE INTERVALO
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("     PORTA\n   LIBERADA!");
    display.display();
    delay(3000);
    display.clearDisplay();
    pagina = 8;
    trocamenu = 0;
    posicaocursor = 1;
  }
    else if(trocamenu == 1 && posicaocursor == 2){
    display.clearDisplay();
    display.setTextSize(1);               //DE ANTES DE COLOCAR O CELULAR NA CAIXA DO MENU POMODORO APOS E MINUTOS DE INTERVALO
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("   LIBERANDO\n  A PORTA...");
    display.display();
    delay(2000);
    trinca.write(aberto);                  //ACIONAMENTO O SERVO-MOTOR PARA ABRIR
    digitalWrite(ledvermelho,HIGH);        //DESLIGA LIGA O LED VERMELHO
    digitalWrite(ledverde,LOW);            //LIGA O LED VERDE E DESLIGA O VERMELHO, DEMONSTRANDO QUE A PORTA ESTA ABERTA 
  
    display.clearDisplay();
    display.setTextSize(1);               //DE ANTES DE COLOCAR O CELULAR NA CAIXA DO MENU POMODORO APOS E MINUTOS DE INTERVALO
    display.setTextColor(BLACK);
    display.setCursor(0,16);
    display.println("     PORTA\n   LIBERADA!");
    display.display();
    delay(3000);
    display.clearDisplay();
       pagina = 0;
       posicaocursor = 1;
       trocamenu = 0;
    }
    else{
      pagina = 7;
    }  
  delay(10);
  display.clearDisplay();
  break;
 
//==================================================================================================================  
//--------------------------------------------SUB MENU B MODO MANUAL - CASE 8----------------------------------------
//==================================================================================================================
    
    case 8: 
    deltat = 0;
    while(deltat < tempointervalomanual && trocamenu==0){   //ENQUANTO O TEMPO INICIAL FOR MENOR QUE O TEMPO INICIAL MAIS 5 MINUTOS, FAÇA:
        display.setTextSize(1);                //CABEÇALHO DE NOVO CICLO
        display.setTextColor(BLACK);
        display.setCursor(0,0);
        display.println("  NOVO CICLO");
        display.drawFastHLine(0,10,83,BLACK);
  
        if(posicaocursor==1){                  //CURSOR NA POSIÇAO 1.
            display.setCursor(0, 16); 
            display.setTextColor(WHITE,BLACK);
            display.println("1 - ANTECIPAR ");}
        else{
            display.setCursor(0, 16); 
            display.setTextColor(BLACK,WHITE);
            display.println("1 - ANTECIPAR");}
  
        if(posicaocursor==2){                  //CURSOR NA POSIÇAO 2.
            display.setCursor(0, 24); 
            display.setTextColor(WHITE,BLACK);
            display.println("2 - CANCELAR ");}
        else{
            display.setCursor(0, 24); 
            display.setTextColor(BLACK,WHITE);
            display.println("2 - CANCELAR  ");}
        
  
    display.display();
  
    if(digitalRead(cima) == LOW){  // CASO O BOTAO 'cima' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI AUMENTAR EM UMA UNIDADE
        posicaocursor++;
        if(posicaocursor > 2){
            posicaocursor=1;}
        delay(tempobotao);
     }
      
    if(digitalRead(baixo) == LOW){ // CASO O BOTAO 'baixo' SEJA ACIONADO, O VALOR DE POSICAO CURSOR VAI DIMINUIR EM UMA UNIDADE.
        posicaocursor--;
        if(posicaocursor < 1){
            posicaocursor = 2;}
        delay(tempobotao);
     }
      
    if(digitalRead(ok) == LOW){  // CASO O BOTAO 'ok' SEJA ACIONADO, O VALOR DE 'trocamenu'  RECEBE 1.
        trocamenu = 1;
        delay(tempobotao);
    }
  
    if(trocamenu==1 && posicaocursor==1){
        pagina = 6; // RETORNA AO MENU POMODORO
        i=0;        // PERMITE A MENSAGEM DE COLOCAR O CELULAR DENTRO DA CAIXA SEJA APRESENTADA
        posicaocursor = 1;
    }
  
  else if(trocamenu==1 && posicaocursor==2){
    pagina = 0; // VAI PARA A PAGINA DE colocque seu celular novamente na
    posicaocursor = 1;

   }
  //else{
    //pagina = 8; // PERMANECE NO MENU INICIAL
 // }
  deltat = deltat + 500;
  display.clearDisplay();
  delay(500);
  }
  display.setTextSize(1);                //INFORMA QUE O TEMPO FOI FINALIZADO E RETORNARA AO MENU INICIAL
  display.setTextColor(BLACK);
  display.setCursor(0,16);
  display.println("     TEMPO\n  DE DESCANSO\n   ESGOTADO");
  display.display();
  for(i=0;i<2;i++){                      //ACIONA O VIBRACALL 2X 3X 
    for(z=0;z<=3;z++){
      analogWrite(vibracall,255);
      delay(400);
      analogWrite(vibracall,0);
      delay(150);
    }
    }
  delay(3000);
  pagina = 6;
  trocamenu = 0;
  delay(10);
  display.clearDisplay();
break; 

 }//CHAVE DO SWITCH CASE
 }//CHAVE DO LOOP

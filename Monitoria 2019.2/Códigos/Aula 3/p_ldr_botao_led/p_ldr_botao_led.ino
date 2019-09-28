
const int ledPin = 2; //led no pino 2
const int Botao = 12; //botao no pino 12
int estadoBotao; //Variavel para ler o status do pushbutton
int ldrPin = A0; //LDR no pino analígico 8
int ldrValor = 0; //Valor lido do LDR 



void setup(){
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT); //Pino do led será saída
    pinMode(Botao, INPUT); //Pino com botão será entrada
    pinMode(ldrPin, INPUT);
}

void loop(){
   ///ler o valor do LDR
 ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
 
 //se o valor lido for maior que 500, liga o led
 if (ldrValor>= 800){  
    
    Serial.print(ldrValor);
    Serial.print("Ta de dia");
    estadoBotao = digitalRead(Botao); //le o estado do botão - HIGH OU LOW

    if (estadoBotao == HIGH){ //Se botão estiver pressionado (HIGH)
        digitalWrite(ledPin, HIGH); // acende o led do pino 2.
    }
    else{ //se não estiver pressionado (LOW)
        digitalWrite(ledPin, LOW); //deixa o led do pino 2 apagado
    }
}
   else if (ldrValor<= 800){  
        Serial.print(ldrValor);
        Serial.print("Ta de noite");
        digitalWrite(ledPin, HIGH); // acende o led do pino 2.
    }

    }

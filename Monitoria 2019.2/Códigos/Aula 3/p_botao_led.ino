
const int ledPin = 2; //led no pino 2
const int Botao = 12; //botao no pino 12
int estadoBotao; //Variavel para ler o status do pushbutton

void setup(){
    pinMode(ledPin, OUTPUT); //Pino do led será saída
    pinMode(Botao, INPUT); //Pino com botão será entrada
}

void loop(){
    estadoBotao = digitalRead(Botao); //le o estado do botão - HIGH OU LOW

    if (estadoBotao == HIGH){ //Se botão estiver pressionado (HIGH)
        digitalWrite(ledPin, HIGH); // acende o led do pino 2.
    }
    else{ //se não estiver pressionado (LOW)
        digitalWrite(ledPin, LOW); //deixa o led do pino 2 apagado
    }
} 

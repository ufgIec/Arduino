const int A = 12; // Primeiramente setamos os 7 pinos
const int B = 11;
const int C = 10;
const int D = 9;
const int E = 8;
const int F = 6;
const int G = 7;

void setup(){
  pinMode(A, OUTPUT); // seta todos as portas que est�o os leds do display como sa�da
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}
void loop(){
  digitalWrite(A, HIGH); //acende os leds que representam o n�mero 0
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  delay(1000); //aguarda 1 segundo para mostrar pr�ximo n�mero

  digitalWrite(A, LOW); //acende os leds que representam o n�mero 1
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  delay(1000); //aguarda 1 segundo para mostrar pr�ximo n�mero

  digitalWrite(A, HIGH); //acende os leds que representam o n�mero 2
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  delay(1000); //aguarda 1 segundo para mostrar pr�ximo n�mero

  digitalWrite(A, HIGH); //acende os leds que representam o n�mero 3
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  delay(1000); //aguarda 1 segundo para mostrar pr�ximo n�mero

  digitalWrite(A, LOW); //acende os leds que representam o n�mero 4
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(1000); //aguarda 1 segundo para mostrar pr�ximo n�mero

  digitalWrite(A, HIGH); //acende os leds que representam o n�mero 5
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(1000); //aguarda 1 segundo para mostrar pr�ximo n�mero
  
  digitalWrite(A, LOW); //acende os leds que representam o n�mero 6
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(1000); //aguarda 1 segundo para mostrar pr�ximo n�mero
  
  digitalWrite(A, HIGH); //acende os leds que representam o n�mero 7
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  delay(1000); //aguarda 1 segundo para mostrar pr�ximo n�mero
  
  digitalWrite(A, HIGH); //acende os leds que representam o n�mero 8
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  
  delay(1000); //aguarda 1 segundo para mostrar pr�ximo n�mero
  digitalWrite(A, HIGH); //acende os leds que representam o n�mero 9
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(1000); //aguarda 1 segundo para mostrar pr�ximo n�mero
}

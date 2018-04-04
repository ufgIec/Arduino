int ledPin = 13;                // LED conectado ao pino digital 13
int ledPin1 = 12;  
void setup()
{
  pinMode(ledPin, OUTPUT);  
  pinMode(ledPin1, OUTPUT); // configura pino digital como saída
}

void loop()
{
  digitalWrite(ledPin, HIGH);   // liga o LED
  delay(1000);                  // temporiza 1 segundo
  digitalWrite(ledPin, LOW);    // desliga o LED
  delay(1000);                  // aguarda mais um segundo

  digitalWrite(ledPin1, HIGH);   // liga o LED
  delay(1000);                  // temporiza 1 segundo
  digitalWrite(ledPin1, LOW);    // desliga o LED
  delay(1000); 
}

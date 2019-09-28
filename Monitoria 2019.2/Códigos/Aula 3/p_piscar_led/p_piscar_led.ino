void setup() 
{
  // Configura o pino d13 como saída 
  pinMode(2, OUTPUT);
}

void loop() 
{
  // Configura o pino 13 como HIGH
  digitalWrite(2, HIGH);
  // Espera 1000 ms (1 segundo)
  delay(1000);             
  // Configura o pino 13 como LOW
  digitalWrite(2, LOW);   
  // Espera 1000 ms (1 segundo)
  delay(1000);            
}

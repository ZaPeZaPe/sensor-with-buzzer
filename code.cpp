int distance_tr = 0; // Inicializando uma variavel para distancia
int cm = 0; // Inicializando uma variavel para centimetros

void setup()
{
  	pinMode(A0, OUTPUT); // Ligando a saída analógica
  	Serial.begin(9600); // Iniciando na porta 9600
}

long readsensor(int pin_trigger, int pin_echo)
{
  pinMode(pin_trigger, OUTPUT);
  digitalWrite(pin_trigger, LOW); // Limpeza de sinal do trigger
  
  delayMicroseconds(2);
  
  digitalWrite(pin_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trigger, LOW);
  
  pinMode(pin_echo, INPUT);
  
  return pulseIn(pin_echo, HIGH); // Enviando pulso
}

void sensor() {
  distance_tr = 1500; // Definindo distância minima
  cm = 0.1723*readsensor(11,10); // Calculando a distância do pulso e convertendo em centímetros
  
  if(cm < 500)
  {
    buzz(1); // Frequência muda de acordo com a distância captada
  } else if (cm < 1000) {
    buzz(5); // Frequência muda de acordo com a distância captada
  } else if (cm < 1500) {
    buzz(10); // Frequência muda de acordo com a distância captada
  }
}

void buzz(int f)
{
  digitalWrite(A0, 1);
  delay(f); // Frequência
  digitalWrite(A0, 0);
}

void loop ()
{
    sensor(); 	
}

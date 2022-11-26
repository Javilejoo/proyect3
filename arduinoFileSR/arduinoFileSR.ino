int echoPin = 8;
int trigPin = 9;
int buzzerPin = 5;
long time = 0;
float distance = 0.0;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  group();
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  getDistance();
}

void getDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  time = pulseIn(echoPin,HIGH);
  distance = (time/2)/29;
  delay(100);
  Serial.print("La distancia es: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print("\n");
  delay(10);
    ////////////////
   if (distance >= 16 && distance <= 22) //Si la distancia es menor de 
   {
    tone( buzzerPin, 3000, distance); //tone(pin, frequency, duration)
    delay(distance);
    }
  else if (distance >= 11 && distance <= 15)
  {
    tone(buzzerPin, 3000, distance);
    delay(distance);
  }
  else if (distance >= 5 && distance <= 10)
  {
    tone( buzzerPin, 3000, distance);
    delay(distance);
  }
    else if (distance <= 4)
  {
    tone( buzzerPin, 3000, distance);
    delay(distance);
  }
}


void group(){
  Serial.print("Grupo:\n");
  Serial.print("Javier Prado - 21486\n");
  Serial.print("Angel Perez - 21298\n");
  Serial.print("Bryan Espana - 21550\n");
  Serial.print("Programa para calcular el tiempo que viaja un sonido y la distancia que recorre\n");
  Serial.print("Distancia\n");
}
  


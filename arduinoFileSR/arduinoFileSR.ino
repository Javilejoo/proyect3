int echoPin = 8; // Echo Pin
int trigPin = 9; // Trigger Pin
int buzzerPin = 5; // Buzzer Pin
float time = 0; // Time
float distance = 0.0; //Distance

void setup() {
  Serial.begin(9600);// Start Serial Communication
  pinMode(trigPin, OUTPUT);//seteamos trigger pin como output
  pinMode(echoPin, INPUT);//seteamos echo pin como input
  pinMode(buzzerPin, OUTPUT);//seteamos buzzer pin como output
  group();//llamamos a la funcion group
  delay(3000);//esperamos 3 segundos
}

void loop() {
  //codigo que se ejecuta continuamente
  getDistance();
}

//funcion para obtener la distancia
void getDistance(){
  digitalWrite(trigPin, LOW);//seteamos trigger pin en LOW
  delayMicroseconds(5);//esperamos 5 microsegundos
  digitalWrite(trigPin,HIGH);//seteamos trigger pin en HIGH
  delayMicroseconds(10);//esperamos 10 microsegundos
  digitalWrite(trigPin,LOW);//seteamos trigger pin en LOW

  time = pulseIn(echoPin,HIGH);//obtenemos el tiempo en microsegundos
  distance = (time*0.0343/2);//convertimos el tiempo en distancia
  delay(100);//esperamos 100 milisegundos

  //imprimimos en el monitor serial la distancia
  Serial.print("La distancia es: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print("\n");
  delay(10);
    ////////////////
   if (distance >= 16 && distance <= 22) //Si la distancia es menor de 
   {
    tone( buzzerPin, 300, distance); //tone(pin, frequency, duration)
    delay(distance);
    }
  else if (distance >= 11 && distance <= 15)
  {
    tone(buzzerPin, 300, distance);
    delay(distance);
  }
  else if (distance >= 5 && distance <= 10)
  {
    tone( buzzerPin, 300, distance);
    delay(distance);
  }
    else if (distance <= 4)
  {
    tone( buzzerPin, 300, distance);
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
  


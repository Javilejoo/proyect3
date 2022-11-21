int echoPin = 8;
int trigPin = 9;
long time = 0;
long distance = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  group();
  delay(5000);
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
  delay(500);
  Serial.print("La distancia es: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print("\n");
  delay(200);
}

void group(){
  Serial.print("Grupo:\n");
  Serial.print("Javier Prado - 21486\n");
  Serial.print("Angel Perez - 21298\n");
  Serial.print("Bryan Espana - 21550\n");
  Serial.print("Programa para calcular el tiempo que viaja un sonido y la distancia que recorre\n");
  Serial.print("Distancia\n");
}
  


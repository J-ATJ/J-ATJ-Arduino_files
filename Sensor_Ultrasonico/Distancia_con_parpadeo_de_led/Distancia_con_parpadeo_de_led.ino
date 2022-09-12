const int trig = 8;
const int echo = 7;
int tiempo;
int distancia;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo / 58; 
  Serial.println(distancia);
  delay(100);
  if (distancia <= 30 && distancia >= 0) {
    digitalWrite(13, HIGH);
    delay(distancia * 10);
    digitalWrite(13, LOW);
  }
}

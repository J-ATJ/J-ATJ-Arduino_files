const int led = 13;
const int ldr = 0;
int vol;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Practica 4 a");
  delay(4000);
}

void loop() {
  // put your main code here, to run repeatedly:
  vol = analogRead(ldr);
  Serial.print("Ent: ");
  Serial.print(vol);
  Serial.print(" , ");
  Serial.print("Volts: ");
  Serial.print((vol * 5) / 1023);
  Serial.print(" , ");
  Serial.print("Bin: ");
  Serial.print(vol, BIN);
  Serial.print(" , ");
  Serial.print("HEX: ");
  Serial.println(vol, HEX);


  delay(500);
}

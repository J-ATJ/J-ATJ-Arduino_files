
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 6, 7, 8, 9); //pines que utilizaremos del arduino para conectar al lcd
const int boton = 10;
const int vel = 11;
const int pot = 0;
const int in1 = 12;
const int in2 = 13;
int velocidad;

boolean estado = HIGH;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); //tipo de pantalla lcd 16x2
  pinMode(boton, INPUT);
  pinMode(vel, OUTPUT);
  lcd.print("PRACTICA 2");// imprime el texto
  delay(4000);
  lcd.setCursor(0, 1);
  lcd.print("OPRIME BOTON");// imprime el texto
  while (digitalRead(boton) == HIGH); //mientras el botón se encuentre en alto no avanza de esta línea
  pinMode(in1, OUTPUT);
  digitalWrite(in1, HIGH);
  pinMode(in2, OUTPUT);
  digitalWrite(in2, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  velocidad = analogRead(pot) / 4; // es necesario dividir entre 4 para que 0-1023 = 0-255
  analogWrite(vel, velocidad) ;
  lcd.print("Vel= ");
  lcd.print((velocidad * 100) / 255); //Se imprime la velocidad en porcentaje 255=100% y 0=0%
  lcd.print(" %");
  delay(300); //tiempo que tarda en actualizarse el sistema ( cada 0.3 Seg )
}


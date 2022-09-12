#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //pines que utilizaremos del arduino para conectar al lcd
int boton = 8;
int led = 13;
boolean estado = HIGH;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); //tipo de pantalla lcd 16x2
  pinMode(boton, INPUT);
  pinMode(led, OUTPUT);
  // lcd.print(" ");// imprime el texto

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(boton) != estado) {
    estado = digitalRead(boton);
    imprimir();
  }

}

void imprimir() {
  lcd.clear();
  if (digitalRead(boton) == LOW) {
    digitalWrite(led, HIGH);
    lcd.print("Oprimido");
  }
  else {
    digitalWrite(led, LOW);
    lcd.print("Libre");
  }
}


#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 6, 7, 8, 9); //pines que utilizaremos del arduino para conectar al lcd
volatile int state1 = HIGH;
volatile int state2 = LOW;
int inter1 = 2;
int inter2 = 3;
int cont = 0;
int i = 0;
String Min;
String Sec;
int band = 1;
void setup() {
  // put your setup code here, to run once:

  pinMode(13, OUTPUT);
  lcd.begin(16, 2); //tipo de pantalla lcd 16x2
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Practica 3");
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("  OPRIME BOTON");
  attachInterrupt(digitalPinToInterrupt(inter1), inicioparo, RISING);
  attachInterrupt(digitalPinToInterrupt(inter2), reinicio, RISING);
  Min = "min ";
  Sec = "sec";


}

void loop() {
  // put your main code here, to run repeatedly:

  for (i = 0; i <= 9; i++)
  {
    lcd.clear();
    if (band != 1) {
      i = i - 1;
    }

    lcd.setCursor(3, 0);
    lcd.print(cont + String(Min) + i + String(Sec)); //
    lcd.setCursor(2, 1);
    // lcd.print(band);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);


  }
  cont = cont + 1;
}
void inicioparo() {
  band = ~band;
}
void reinicio() {
  band = 1;
  i = 0;
  cont = 0;
}



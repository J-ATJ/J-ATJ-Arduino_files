#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //pines que utilizaremos del arduino para conectar al lcd
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); //tipo de pantalla lcd 16x2
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0); //columna cero linea uno
  lcd.print("Piensa, actua");// imprime el texto
  delay(4000);
  lcd.setCursor(0, 1); //columna cero linea uno

  lcd.print("      avanza");

  delay(4000);
  lcd.clear();
  delay(2000);
}

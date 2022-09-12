#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //pines que utilizaremos del arduino para conectar al lcd
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
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
/* sda=pin a4
    scl=a5
    vcc=5v


*/

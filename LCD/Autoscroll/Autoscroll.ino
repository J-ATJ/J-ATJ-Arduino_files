#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //pines que utilizaremos del arduino para conectar al lcd
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); //tipo de pantalla lcd 16x2
  lcd.clear();
  lcd.setCursor(1, 0); //columna cero linea uno
  lcd.print("   JAAZIEL ES");// imprime el texto
  lcd.setCursor(1, 1); //columna cero linea uno
  lcd.print(" ******");  // cada 15 lugares aparece un espacio en blanco

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(15, 1); //columna 16 linea uno
  lcd.autoscroll();
  lcd.print(" "); //
  delay(450);
}

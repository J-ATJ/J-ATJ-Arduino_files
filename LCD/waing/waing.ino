#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9
#define SS_PIN          10
byte leer[4];
int led = 7;
MFRC522 RFID(SS_PIN, RST_PIN);

LiquidCrystal_I2C lcd(0x27, 16, 2); //pines que utilizaremos del arduino para conectar al lcd
void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  RFID.PCD_Init();

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1, 0);
  int c = 15;
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(15, 0); //columna cero linea uno
  lcd.print("waiting");// imprime el texto
  lcd.autoscroll();
  delay(500);
  lcd.print(" ");

  //lcd.print("waiting");// imprime el texto
  if (  RFID.PICC_IsNewCardPresent()) {
    lcd.clear();
    lcd.setCursor(2, 0);
    digitalWrite(led, HIGH);
    ciclo();
  }


}


void ciclo() {
  lcd.print("asdqede");

  if ( !RFID.PICC_ReadCardSerial())
    return;
  lcd.clear();
  for (byte i = 0; i < RFID.uid.size; i++) {

    if (RFID.uid.uidByte[i] < 0x10) {
      lcd.print(" 0");
    }
    else {
      lcd.print(" ");
    }
    lcd.print(RFID.uid.uidByte[i], HEX);

    //    leer[i]=RFID.uid.uidByte[i];
    delay (4000);
    lcd.clear();
  }

  digitalWrite(led, LOW);
}

/* sda=pin a4
    scl=a5
    vcc=5v


*/

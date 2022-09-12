#include <SPI.h>
#include<MFRC522.h>
#define RST_PIN         9        
#define SS_PIN          10       
#include <LiquidCrystal_I2C.h>

const int LEDverde = 7;
const int LEDrojo = 6;

MFRC522 RFIDJorge(SS_PIN, RST_PIN);  // Creamos Nuestro RFID 
LiquidCrystal_I2C lcd(0x27,16,2); //iniciar lcd con i2c direccion 0x27, 

// declaramos los usuarios o claves identificadas
byte ent[4];
byte Tarjeta[4]={0x29, 0x86, 0x64, 0x23}; //0x00 porque son hexadecimales
byte Llavero[4]={0xFC, 0x23, 0xC2, 0x48};  // 0x49 identificado , si usamos --> 0x48 = usuario no identificado

void setup() {
  // put your setup code here, to run once: 
  SPI.begin();             //Inicializamos SPI
  RFIDJorge.PCD_Init();
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(LEDverde,OUTPUT);
  pinMode(LEDrojo,OUTPUT);
  
        digitalWrite(LEDverde,HIGH);
        digitalWrite(LEDrojo,HIGH);
        delay(1000);
        digitalWrite(LEDverde,LOW);
        digitalWrite(LEDrojo,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(3,0);
  lcd.print("Acerca tu ");
  lcd.setCursor(0,1);
  lcd.print(" identificacion");
  lcd.setCursor(0,0);
  
  if ( ! RFIDJorge.PICC_IsNewCardPresent()) 
  return;

  if ( ! RFIDJorge.PICC_ReadCardSerial()) 
  return;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Tu clave:");
  lcd.setCursor(0,1);

  for(byte i=0; i<RFIDJorge.uid.size; i++){
  
    if (RFIDJorge.uid.uidByte[i]<0x10){
       lcd.print(" 0");
      }
      else{
          lcd.print(" ");
        }
   
      
    lcd.print(RFIDJorge.uid.uidByte[i],HEX);
    ent[i]=RFIDJorge.uid.uidByte[i];  
    }
    
    delay(4000);
    lcd.clear();
    lcd.setCursor(0,0);
    
    if(verificarT(ent,Tarjeta)){
    lcd.print("   Bienvenido");
    lcd.setCursor(3,1);
    lcd.print(" Tarjeta");
    digitalWrite(LEDverde,HIGH);
    delay(2000);
    digitalWrite(LEDverde,LOW);
    }
    
    else if(verificarL(ent,Llavero)){
      lcd.print("   Bienvenido");
      lcd.setCursor(3,1);
      lcd.print(" Llavero");
      digitalWrite(LEDverde,HIGH);
      delay(2000);
      digitalWrite(LEDverde,LOW);
    }
    else {
             lcd.setCursor(1,0);
             lcd.print(" Usuario no ");
             lcd.setCursor(2,1);
             lcd.print("Registrado "); 
             lcd.clear();
             lcd.print("NO hay acceso :(");
             digitalWrite(LEDrojo,HIGH);
             delay(2000);
             digitalWrite(LEDrojo,LOW);
            
    }
    
    RFIDJorge.PICC_HaltA();
    delay(1000);
    lcd.clear();
  }

  boolean verificarT(byte ent[],byte Tarjeta[])
  {
    for (byte i=0;i<RFIDJorge.uid.size;i++){
    if (ent[i] != Tarjeta[i])
    return(false);
    }
    return (true);
    }
  
  boolean verificarL(byte ent[],byte Llavero[])
  {
    for (byte i=0;i<RFIDJorge.uid.size;i++){
    if (ent[i] != Llavero[i])
    return(false);
    }
    return (true);
    }

  /* RFID 3.3v
   *  
   *  Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 * 
 * Para i2C 
 * sda=pin a4
 * scl= pin a5
 *  vcc=5v
 */


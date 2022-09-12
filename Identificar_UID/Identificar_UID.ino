
#include <SPI.h>
#include<MFRC522.h>
#define RST_PIN         9        
#define SS_PIN          10        

MFRC522 RFIDJorge(SS_PIN, RST_PIN);  // Creamos Nuestro RFID con el nombre RFIDJorge

// declaramos los usuarios o claves identificadas
byte ent[4];
byte Tarjeta[4]={0x29, 0x86, 0x64, 0x23}; //0x00 porque son hexadecimales
byte Llavero[4]={0xFC, 0x23, 0xC2, 0x49};  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       //Inicializamos la conexión Serial
  SPI.begin();             //Inicializamos SPI
  RFIDJorge.PCD_Init();
  Serial.println("Acerca tu identificación");
  Serial.println("Para tener acceso debes estar registrado");
  Serial.println(" ");
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( ! RFIDJorge.PICC_IsNewCardPresent()) 
    return;


  if ( ! RFIDJorge.PICC_ReadCardSerial()) 
    return;

  Serial.print("Clave identificada:");

  for(byte i=0; i<RFIDJorge.uid.size; i++){
    
    if (RFIDJorge.uid.uidByte[i]<0x10){
      Serial.print(" 0");
      }
      else{
        Serial.print(" ");
        }
      
     Serial.print(RFIDJorge.uid.uidByte[i],HEX);
     ent[i]=RFIDJorge.uid.uidByte[i];  
    }
    delay(1000);
    if(verificarT(ent,Tarjeta))
    Serial.println("  Se permite acceso a Tarjeta ");
    else if(verificarL(ent,Llavero))
    Serial.println("  Se permite acceso a Llavero ");
    else
    Serial.println("  Usuario no Registrado");

    Serial.println();
    RFIDJorge.PICC_HaltA();
    delay(3000);
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

  /* Typical pin layout used:
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
 */


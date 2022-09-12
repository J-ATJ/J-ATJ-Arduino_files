#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

// 
// i2c_scanner
//
// Version 1
// Este programa (código que aparece) se pueden encontrar en muchos sitios.
// Por ejemplo, en el foro Arduino.cc.
// El autor original no se conoce.
// Version 2, Juni 2012, Using Arduino 1.0.1
// Adaptado para ser lo más simple posible por usuario Krodal Arduino.cc
// Version 3, Feb 26 2013 by louarnold
// Version 4, March 3, 2013, Using Arduino 1.0.3
// by Arduino.cc user Krodal.
// Version 5, March 28, 2013
// Como la versión 4, pero las exploraciones de direcciones ahora a 127. 
//
// Este boceto prueba las direcciones estándar de 7 bits. 
// Los dispositivos con dirección de bits más alta 
// no pueden ser vistas correctamente.
 
#include "Wire.h" ; si no aparece la librería es por motivos del soft "< "
 
void setup()
{
Wire.begin();
 
Serial.begin(9600);
Serial.println("\nI2C Scanner");
}
 
void loop()
{
byte error, address;
int nDevices;
 
Serial.println("Scanning...");
 
nDevices = 0;
for(address = 1; address < 127; address++ ) 
{
// El i2c_scanner utiliza el valor devuelto o el 
// Write.endTransmisstion para ver si un 
// dispositivo reconoció la dirección.
Wire.beginTransmission(address);
error = Wire.endTransmission();
 
if (error == 0)
{
Serial.print("Dispositivo I2C en dirección 0x");
if (address<16) 
Serial.print("0");
Serial.print(address,HEX);
Serial.println(" !");
 
nDevices++;
}
else if (error==4) 
{
Serial.print("Error desconocido en dirección 0x");
if (address<16) 
Serial.print("0");
Serial.println(address,HEX);
} 
}
if (nDevices == 0)
Serial.println("Dispositivo I2C No hallado.\n");
else
Serial.println("hecho\n");
 
delay(5000);   // espera 5 segundos para otro scan
}

//Copie y pegue este código compile y súbalo a su Arduino. Ahora, abra la ventana del monitor serie, para ver los m

#include<SoftwareSerial.h>
SoftwareSerial vSerial(8,9); //8=rx de ard y 9=tx de ard 
const int key=7; //desconectar 5v del módulo y conectar key los primeros 5 seg para entrar en modo config
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Activo");
  vSerial.begin(38400);
  pinMode(key,OUTPUT);
  digitalWrite(key,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(vSerial.available()){
    char lect=vSerial.read();
    Serial.write(lect);
    }
  if (Serial.available()){
     char lect=Serial.read();
    vSerial.write(lect);
    }
}
//AT+BIND? DIRECCION MAC
//AT+ROLE? ESCLAVO=0 , MAESTRO=1
//AT+PSWD? CONTRASEÑA
//AT+UART? VELOCIDAD 
//AT+NAME? NOMBRE DEL DISPOSITIVO


#include <Servo.h>

Servo pluma;
int senhal=1;

int pulso_minimo = 1000;
int pulso_maximo = 2000;

void setup() {
  // put your setup code here, to run once:
  pluma.attach(senhal, pulso_minimo, pulso_maximo); // señal del servo en el pin 9 (senhal)
  
}

void loop() {
  // put your main code here, to run repeatedly:

pluma.write(0);
delay(3000);
pluma.write(100);
delay(3000);
}

const int led = 3; // a la salida del pin 3 (pwm) del arduino pondremos un led, por eso se declaran como constantes
const int pot = 0; // Potenciometro conectado en el pin cero analogico, no hace falta declarar los pines analogicos como entrada
int brillo;  // declaramos como variables int el brillo, que vendria siendo la variación de voltaje en los leds


void setup() {
  // put your setup code here, to run once:
  pinMode (led, OUTPUT); // declaramos led (pin 3) como salida digital

}

void loop() {
  // put your main code here, to run repeatedly:

  brillo = analogRead(pot) / 4; // analogRead lee entre 0-1023 equivalente a 5v, lo dividimos entre 4 para convertirlo a 0-255
  analogWrite(led, brillo) ; // maneja valores entre 0-255 equivalente a 5v

}

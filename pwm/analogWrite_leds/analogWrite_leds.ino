
const int led1 = 3; // a la salida del pin 3 (pwm) del arduino pondremos un led, por eso se declaran como constantes ya que nunca dejan de estar en esos pines
const int led2 = 5; // a la salida del pin 5 (pwm) del arduino pondremos otro led
int brillo1;  // declaramos como variables int el brillo, que vendria siendo la variación de voltaje en los leds
int brillo2;  // lo mismo para el segundo led

void setup() {
  // put your setup code here, to run once:
  pinMode (led1, OUTPUT); // declaramos led1 (pin 3) como salida
  pinMode (led2, OUTPUT); // declaramos led2 (pin 5) como salida

}

void loop() {
  // put your main code here, to run repeatedly:

  //este ciclo for inicia el voltaje (brillo1) en cero y sube hasta 255 que es el voltaje máximo
  for (brillo1 = 0; brillo1 <= 255; brillo1++) {

    analogWrite(led1, brillo1);  // analogWrite se encarga de enviar la información de salida (brillo1), en este caso de 0 a 255 en led1
    delay(1);                      // la velocidad que tarda en hacer el ciclo
  }

  //este ciclo for inicia el voltaje (brillo1) en 255 y lo baja hasta 0 que es el voltaje mínimo
  for (brillo1 = 255; brillo1 > 0; brillo1--) {

    analogWrite(led1, brillo1);
    delay(1);
  }



  // Los siguientes ciclos for tienen la misma función que los anteriores pero para sus respectivas variables: (led2 y brillo2)
  for (brillo2 = 0; brillo2 <= 255; brillo2++) {

    analogWrite(led2, brillo2);
    delay(1);
  }
  for (brillo2 = 255; brillo2 >= 0; brillo2--) {

    analogWrite(led2, brillo2);
    delay(1);
  }

}

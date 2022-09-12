const int ledrojo=3; //indica que el la constante int ledrojo es igual a 3 y asi para las demas respectivamente
const int ledverde=5;
const int ledazul=6;
const int potrojo=0;
const int potverde=1;
const int potazul=2;
int rojo; //indica que rojo es una variable de tipo int
int verde;
int azul;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  //inicializa el monitor serial
  pinMode(ledrojo,OUTPUT);  //indica que el pin (ledrojo=3) es una salida
  pinMode(ledverde,OUTPUT);
  pinMode(ledazul,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /* analogRead tiene 10 bits, por lo que su valor maximo es 1023,
  ya que vamos a utilizar este valor para dar una salida pwm y pwm solo acepta valores entre 0-255, es necesario dividir la lectura analogica entre 4 */
  rojo=analogRead(potrojo)/4;   //indica que la variable rojo va a ser igual a la lectura analogica, o sea entrada del pin (potrojo=0) entre 4
  verde=analogRead(potverde)/4;
  azul=analogRead(potazul)/4;
  /* Como este codigo esta programado para un led RGB anodo comun (vcc comun), se debe usar el complemento de las variables y 255,
  por esa razon hacemos una resta de 255 menos x , es como sacar el negativo. Si el led fuera catodo comun (gnd comun) no seria necesario sacar el negativo */
  analogWrite(ledrojo,255-rojo);  //permite hacer una salida pwm en el pin (ledrojo=3) de 255 menos la variable rojo
  analogWrite(ledverde,255-verde);
  analogWrite(ledazul,255-azul);

  Serial.print("Rojo: "); //muestra en el monitor serial la palabra "rojo: " como es texto se pone entre comillas
  Serial.print(rojo);     // muestra en el monitor serial la variable rojo
  Serial.print(" , ");
  Serial.print("Verde: ");
  Serial.print(verde);
  Serial.print(" , ");
  Serial.print("Azul: ");
  Serial.println(azul);     //finalmente utilizamos un println para dar un salto de linea al final de todo
}



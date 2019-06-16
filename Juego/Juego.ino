//lopdam
//Codigo para controlar el sist. que mueve los servos cuando se detecta un disparo
#include <IRremote.h>
#include <Servo.h>

//Declaramos los servos
Servo servo1;
Servo servo2;
Servo servo3;

//Declaramos los pines para los servos
int pinServ1 = 9;
int pinServ2 = 10;
int pinServ3 = 11;

//Declaramos los pines para el receptor ir
int RECV_PIN1 = 3;
int RECV_PIN2 = 5;
int RECV_PIN3 = 6;

//Declaramos una variable en formato hex que es 0

unsigned long codigo = 0x000;

//Declaramos los "objs" IR
IRrecv irrecv1(RECV_PIN1);
IRrecv irrecv2(RECV_PIN2);
IRrecv irrecv3(RECV_PIN3);

//Declaramos las variables donde se van a guardar los datos recividos
decode_results results1;
decode_results results2;
decode_results results3;

//Declaramos el tiempo de esperea entre cada secuencia
int tiempo = 100;
//Declaramos los paso que se mueve el servo por cada secuencia
int pasos = 5;

void setup()
{
  //Inicializamos todo
  Serial.begin(9600);
  IRS();
  Servos();

}

void loop() {
  //Enviamos a correr el programa
  IR1();
  IR2();
  IR3();
  delay(10);//Lo detenmos un momento para que no se sature
}

//Esta funcion va a servir para que cuando se reciva un dato si este es diferente de 0 cosa que va ser cierta
//cuando apuntemos con el laser ya que el laser envia 0XA90 y aveces se toman lecturas erroneas pero todas diferentes de 0X00
//Y lo unico que se toma en cuenta es que se apunte con el laser, no el dato recivido
void IR1() {
  //Verificamos si se receive un dato
  if (irrecv1.decode(&results1)) {
    //Imprimimos el dato
    Serial.println(results1.value, HEX);
    //Si el dato es diferente de 0X00, activamos el Servo
    if (results1.value != codigo) {
      Servo1();
    }
    irrecv1.resume(); // Receive the next value
  }
}

void IR2() {
  //Verificamos si se receive un dato
  if (irrecv2.decode(&results2)) {
    //Imprimimos el dato
    Serial.println(results2.value, HEX);
    //Si el dato es diferente de 0X00, activamos el Servo
    if (results2.value != codigo) {
      Servo2();
    }
    irrecv2.resume(); // Receive the next value
  }
}

void IR3() {
  //Verificamos si se receive un dato
  if (irrecv3.decode(&results1)) {
    //Imprimimos el dato
    Serial.println(results3.value, HEX);
    //Si el dato es diferente de 0X00, activamos el Servo
    if (results3.value != codigo) {
      Servo3();
    }
    irrecv3.resume(); // Receive the next value
  }
}


//Funcione para activar el servo
void Servo1() {
  //Activamos el servo de manera lenta, para que el movimiento no se brusco
  for (int i = 0; i <= 180; i = i + pasos) {
    //Insertamos los grados en el servo
    servo1.write(i);
    delay(tiempo);//Esperamos un tiempo entre cada set
  }
}

//Funcione para activar el servo
void Servo2() {
  //Activamos el servo de manera lenta, para que el movimiento no se brusco
  for (int i = 0; i <= 180; i = i + pasos) {
    //Insertamos los grados en el servo
    servo2.write(i);
    delay(tiempo);//Esperamos un tiempo entre cada set
  }
}

//Funcione para activar el servo
void Servo3() {
  //Activamos el servo de manera lenta, para que el movimiento no se brusco
  for (int i = 0; i <= 180; i = i + pasos) {
    //Insertamos los grados en el servo
    servo3.write(i);
    delay(tiempo);//Esperamos un tiempo entre cada set
  }
}

//Inicializar los IRs
void IRS() {
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  // Start the receivers
  irrecv1.enableIRIn();
  irrecv2.enableIRIn();
  irrecv3.enableIRIn();
  Serial.println("Enabled IRin");

}

//Inicializar los Servos
void Servos() {
  //Inici los servos con su pin corresponidente
  servo1.attach(pinServ1);
  servo2.attach(pinServ2);
  servo3.attach(pinServ3);
}


#include <IRremote.h>

IRsend irsend;//Declaramos un "obj" IRsend

#define laser 3//Color morado y cable blanco con azul
#define btn 2 //color amarillo y cable balnco con naranja
//El btn funciona con logica negativa 1 logico sin presionar y 0 logico presionando

int lectura = 1;//Variable para la lectura del btn

int antes = 1; //el estado antes del btn, para que no se pueda tener presionando el btn

void setup() {
  //Inicializamos el modo de los pines
  pinMode(laser, OUTPUT);
  pinMode(btn, INPUT);

}
void loop() {
  lectura = digitalRead(btn);
  Laser();


}

void Laser() {

  /*int khz = 38; // 38kHz carrier frequency for the NEC protocol
    unsigned int irSignal[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 39416, 9000, 2210, 560}; //AnalysIR Batch Export (IRremote) - RAW
  */
  //Cuando se presion a el switch se abre
  if (lectura == LOW && antes == 1) {


    //irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz);
    irsend.sendSony(0xa90, 12);//enviamos un valor cualquiera
    delay(10);
    irsend.sendSony(0xa90, 12);
    delay(750);
    antes = 0;
  }
  else if (lectura == HIGH && antes == 0) {
    antes = 1;
  }
}

#include <Wire.h>//se llama la libreria Wire que nos ayudara a comunicarnos con el dispositivos de I2C
#include <LiquidCrystal_I2C.h>//se instala la libreria LiquidCrystal_I2C para trabajar con el i2c del lcd junto con el MÃ³dulo serial I2C
#include <Servo.h>//se instala esta libreria para el servo motor

#define lcdAddress 0x27  //se indica la direcciÃ³n que toma el modulo i2c
#define filas 2//se indica que numero de filas que tiene el lcd que son dos para despues utilizarlo
#define columnas 16//se indica el numero de columnas que tiene el lcd que son 16 
LiquidCrystal_I2C pantallalcd(lcdAddress, columnas, filas);//se llama la libreria LiquidCrystal_I2C se le indica el nombre de pantallalcd se le indica la direcciÃ³n del lcd,la variable columnas y filas

//INDICANDO LOS PINES A QUE VA CADA UNO
const int pul = 2;  
const int buzzer =6;
const int pot = A1;
const int pot_1 = A2;
const int pot_2 = A3;

//variables para leeer elpot
int valor_pot;
int valor_pot1;
int valor_pot2;

//para los pulsadores
const int pulsador = 7;
const int pulsador1 = 8;
const int pulsador2 = 9;
const int pulsador3 = 10;
int lee;
int lee1;
int lee2;
int lee3;



//para los servos 
Servo dota;//SE CREA LA VARIABLE PARA EL SERVO MOTOR
Servo jota;//SE CREA OTRA  VARIABLE PARA EL SERVO MOTOR
Servo css;//SE CREA OTRA  VARIABLE PARA EL SERVO MOTOR

#define b_salida() pinMode(buzzer,OUTPUT)//se cambia el pin mode por b_salida
#define encender() tone(buzzer,1000)//se utiliza para reemplazar el tone del bjz
#define apagar() noTone(buzzer)//se utiliza paara remplazar el noTone del buz


void setup() {
 pantallalcd.init();//se indica que la pantallalcd que en eso se iniciara
 pantallalcd.backlight();//se indica que la pantallalcd para su iluminaciÃ³n
 b_salida();//SE DEJA INDICADO
 dota.attach(3);//el pin que esta el servo
 jota.attach(4);//el pin que esta el servo
 css.attach(5);//el pin que esta el servo
 attachInterrupt(digitalPinToInterrupt(2), traviss, FALLING);//SE UTILIZA PARA INTERUPCIÓN
}
void loop() {
   pantallalcd.setCursor(0,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
   pantallalcd.print("BRAZO MECANICO");//que se imprima lo siguiente 
   pantallalcd.setCursor(0,1);//que posición 
   pantallalcd.print("1:");
   pantallalcd.print(valor_pot);
   pantallalcd.print(" 2:");
   pantallalcd.print(valor_pot1);
   pantallalcd.print(" 3:");
   pantallalcd.print(valor_pot2);
   //solo se incializan las funciones en el void loop
   scoott();
   drake();
   messi();
   cristiano();
   neymar();
   maldini();
   petit();
}


void traviss(){//se utiliza para la interrupción
   //grados del servo
   dota.write(0);
   jota.write(0);
   css.write(0);
    encender();//encienda el buz
    delay(1000);
    apagar();//apague el buz
}


void scoott(){//se utiliza para hacer que el potenciometro haga lo mismo que el servo
  valor_pot = analogRead(pot);
  valor_pot = map(valor_pot, 0, 1023, 0, 180);//es se utiliza que para que los parametros de minimo y maximo del potencimetro sean ahora el minimo y el maximo de parametros del servo
  dota.write(valor_pot);//que el servo haga el parametro establecido en map que esta igualado a la variable valor_pot
  delay(10);
}


void drake(){//se utiliza para hacer que el potenciometro haga lo mismo que el servo
  valor_pot1 = analogRead(pot_1);
  valor_pot1 = map(valor_pot1, 0, 1023, 0, 180);//es se utiliza que para que los parametros de minimo y maximo del potencimetro sean ahora el minimo y el maximo de parametros del servo
  jota.write(valor_pot1);//que el servo haga el parametro establecido en map que esta igualado a la variable valor_pot
  delay(10);
}


void messi(){//se utiliza para hacer que el potenciometro haga lo mismo que el servo
  valor_pot2 = analogRead(pot_2);
  valor_pot2 = map(valor_pot2, 0, 1023, 0, 180);//es se utiliza que para que los parametros de minimo y maximo del potencimetro sean ahora el minimo y el maximo de parametros del servo
  css.write(valor_pot2);//que el servo haga el parametro establecido en map que esta igualado a la variable valor_pot
  delay(10);
}
void cristiano(){//para el cambio de posición 
  lee = digitalRead(pulsador);
  if(lee==HIGH){//si se cumple hace lo siguiente 
    encender();//encienda el buz
    //grados del servo
   dota.write(45);
   jota.write(45);
   css.write(45);
    delay(3000);
    apagar();//apague el buz
  }
}
void neymar(){//para el cambio de posición 
  lee1 = digitalRead(pulsador1);
  if(lee1==HIGH){//si se cumple hace lo siguiente 
    encender();//encienda el buz
    //grados del servo
   dota.write(90);
   jota.write(90);
   css.write(90);
    delay(3000);
    apagar();//apague el buz
  }
}
void maldini(){//para el cambio de posición 
    lee2 = digitalRead(pulsador2);
  if(lee2==HIGH){//si se cumple hace lo siguiente 
    encender();//encienda el buz
    //grados del servo
   dota.write(135);
   jota.write(135);
   css.write(135);
    delay(3000);
    apagar();//apague el buz
  }
}
void petit(){//para el cambio de posición 
   lee3 = digitalRead(pulsador3);
  if(lee3==HIGH){//si se cumple hace lo siguiente 
   encender();//encienda el buz
   //grados del servo
   dota.write(180);
   jota.write(180);
   css.write(180);
   delay(3000);
   apagar();//apague el buz
  }
 
}
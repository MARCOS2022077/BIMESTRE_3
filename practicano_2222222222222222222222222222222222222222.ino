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
const int pot=7;
const int pot_1=8;
const int pot_2=9;
int valor_pot;
int valor_pot1;
int valor_pot2;


//para los servos 
Servo dota;//SE CREA LA VARIABLE PARA EL SERVO MOTOR
Servo jota;//SE CREA OTRA  VARIABLE PARA EL SERVO MOTOR
Servo css;//SE CREA OTRA  VARIABLE PARA EL SERVO MOTOR

#define b_salida() pinMode(buzzer,OUTPUT)


void setup() {
 pantallalcd.init();//se indica que la pantallalcd que en eso se iniciara
 pantallalcd.backlight();//se indica que la pantallalcd para su iluminaciÃ³n
 b_salida();//SE DEJA INDICADO
 dota.attach(3);
 jota.attach(4);
 css.attach(5);
 attachInterrupt(digitalPinToInterrupt(pul),traviss,CHANGE);//SE UTILIZA PARA INTERUPCIÓN
}
void loop() {
   pantallalcd.setCursor(0,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
   pantallalcd.print("BRAZO MECANICO");
}
void traviss(){
   pantallalcd.clear();//LIMPIE
   pantallalcd.setCursor(1,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
   pantallalcd.print("interrupción");//QUE IMPRIMA LO QUE SE INDICA
   delay(10);
   dota.write(0);
   delay(10);
   jota.write(0);
   delay(10);
   css.write(0);
}
void scoott(){
  valor_pot = digitalRead(pot);
  valor_pot = map(valor_pot, 0, 1023, 0, 180);
  dota.write(valor_pot);
  delay(10);
}
void drake(){
  valor_pot = digitalRead(pot);
  valor_pot = map(valor_pot, 0, 1023, 0, 180);
  dota.write(valor_pot);
  delay(10);

}

#include <Wire.h>//se llama la libreria Wire que nos ayudara a comunicarnos con el dispositivos de I2C
#include <LiquidCrystal_I2C.h>//se instala la libreria LiquidCrystal_I2C para trabajar con el i2c del lcd junto con el MÃ³dulo serial I2C



#define lcdAddress 0x27  //se indica la direcciÃ³n que toma el modulo i2c
#define filas 2//se indica que numero de filas que tiene el lcd que son dos para despues utilizarlo
#define columnas 16//se indica el numero de columnas que tiene el lcd que son 16 
LiquidCrystal_I2C pantallalcd(lcdAddress, columnas, filas);//se llama la libreria LiquidCrystal_I2C se le indica el nombre de pantallalcd se le indica la direcciÃ³n del lcd,la variable columnas y filas

//INDICANDO LOS PINES A QUE VA CADA UNO
const int pul = 2;
const int pul_1 = 3;
const int buzzer = 4;
const int trig = 5;
const int echo = 6;

//NOS AYUDARA CON LAS LEEIDAS Y ´PARA ALGUNAS OPERACIONES
float tempo;
float dis;
const float val = 58.2; 
int lee;


//PARA EL SONID PERSONALIZADO DEL BUZZER
#define Do 261
#define Re 293
#define Mi 329
#define Fa 349
#define Sol 392
#define La 440
#define Si 493
#define negra 250
#define blanca 500
#define retardo 3000
//SE DEFINEN FUNCIONES QUE REMPLAZAN A OTRAS Y SE INDICA QUE PIN VA LA BOMBA
#define bomba 7
#define salida_B() pinMode(bomba,OUTPUT)
#define apagar_B() digitalWrite(bomba,HIGH)
#define encender_B() digitalWrite(bomba,LOW)
#define b_salida() pinMode(buzzer,OUTPUT)
#define salida() pinMode(trig,OUTPUT)
#define entrada() pinMode(echo,INPUT) 
void setup() {
 pantallalcd.init();//se indica que la pantallalcd que en eso se iniciara
 pantallalcd.backlight();//se indica que la pantallalcd para su iluminaciÃ³n
 salida();//SE DEJA INDICADO
 entrada();//SE DEJA INDICADO
 salida_B();//SE DEJA INDICADO
 b_salida();//SE DEJA INDICADO
 Serial.begin(9600);//SE INICIALIZA EL MONITOR SERIAL
 attachInterrupt(digitalPinToInterrupt(pul_1),traviss,CHANGE);//SE UTILIZA PARA INTERUPCIÓN
 attachInterrupt(digitalPinToInterrupt(pul),drake,CHANGE);//SE UTILIZA PARA INTERUPCIÓN
}
void loop() {

  //TODOAS ESTA FUNCIONES NOS AYUDARAN A SABER A QUE ALTURA MIDE EL SENSOR ULTRASONICO
  digitalWrite(trig, LOW);//SE DICE QUE HAGA QUE TRIG ESTE APAGADO
  delayMicroseconds (2);//QUE SE TOME UN TIEMPO EN MICROSEGUNDOS
  digitalWrite(trig, HIGH);//SE DICE QUE HAGA QUE TRIG ESTE ENCENDIDO
  delayMicroseconds (10);//SE TOME UN TIEMPO EN MICROSEGUNDOS
  tempo = pulseIn(echo,HIGH);//LUEGO ESTE LO IGUALAMOS A UNA VARIABLE Y SE INDICA LA NUEVA FUNCIÓN DE PULSEIN QUE ECHO ESTE ENCENDIDO
  dis = (tempo) /val;//LUEGO ESTO SE REALIZA LA OPERACIÓN PARA SABER A QUE MEDIDA MIDE
  Serial.print(dis);//QUE IMPRIMA LO QUE SE INDICA
  Serial.println("cm");//QUE IMPRIMA LO QUE SE INDICA
  pantallalcd.setCursor(1,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
  pantallalcd.print("ESTADO TANQUE");//QUE IMPRIMA LO QUE SE INDICA
  scoott();
}

void traviss(){
    pantallalcd.clear();//LIMPIE
   pantallalcd.setCursor(1,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
   pantallalcd.print("VACIANDO");//QUE IMPRIMA LO QUE SE INDICA
    delay(2000);//QUE TOME UN TIEMPO
   encender_B();//QUE ENCIENDA LA BOMBA
   delay(4000);//QUE TOME UN TIEMPO
   apagar_B();//QUE APAGUE LA BOMBA
   delay(100);//QUE TOME UN TIEMPO
   pantallalcd.clear();//LIMPIE
}

void drake(){
  pantallalcd.clear();//LIMPIE
  pantallalcd.setCursor(3,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
  pantallalcd.print("HUBO UNA");//QUE IMPRIMA LO QUE SE INDICA
  pantallalcd.setCursor(2,1);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
  pantallalcd.print("INTERRUPCION");//QUE IMPRIMA LO QUE SE INDICA
  delay(2000);//QUE TOME UN TIEMPO
  pantallalcd.clear();//LIMPIE
}


void scoott(){
  if(dis<9){//SI CUMPLE LA FUNCIÓN HACE LO SIGUIENTE 
    pantallalcd.setCursor(0,1);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
  }
  if(dis<8){//SI CUMPLE LA FUNCIÓN HACE LO SIGUIENTE 
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
  }
  if(dis<7){//SI CUMPLE LA FUNCIÓN HACE LO SIGUIENTE 
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
  }
  if(dis<6){//SI CUMPLE LA FUNCIÓN HACE LO SIGUIENTE 
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
  }
  if(dis<5){//SI CUMPLE LA FUNCIÓN HACE LO SIGUIENTE 
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
  }
  if(dis<4){//SI CUMPLE LA FUNCIÓN HACE LO SIGUIENTE 
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
  }
  if(dis<3){//SI CUMPLE LA FUNCIÓN HACE LO SIGUIENTE 
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO
    pantallalcd.print("*");//QUE IMPRIMA LO QUE SE INDICA
    delay(100);//QUE TOME UN TIEMPO

    //CUANDO LLEGUE HASTA AQUÍ QUE SUENE LA CANCIÓN

   tone(buzzer, Do,negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Do, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Sol, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Sol, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, La, negra);
   delay(200);
   noTone(buzzer);
   delay(100);
   tone(buzzer, La, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Sol, blanca);
   delay(200);
   noTone(buzzer);
   delay(200);

   tone(buzzer, Fa, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Fa, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Mi, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Mi, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Re, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Re, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer,Do, blanca);
   delay(200);
   noTone(buzzer);
   delay(200);
      tone(buzzer, Do,negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Do, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Sol, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Sol, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, La, negra);
   delay(200);
   noTone(buzzer);
   delay(100);
   tone(buzzer, La, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Sol, blanca);
   delay(200);
   noTone(buzzer);
   delay(200);

   tone(buzzer, Fa, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Fa, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Mi, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Mi, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Re, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer, Re, negra);
   delay(200);
   noTone(buzzer);
   delay(200);
   tone(buzzer,Do, blanca);
   delay(200);
   noTone(buzzer);
   delay(10000);
   noTone(buzzer);

  }
}
#include <Wire.h>//se llama la libreria Wire que nos ayudara a comunicarnos con el dispositivos de I2C
#include <LiquidCrystal_I2C.h>//se instala la libreria LiquidCrystal_I2C para trabajar con el i2c del lcd junto con el MÃ³dulo serial I2C

#define lcdAddress 0x27  //se indica la direcciÃ³n que toma el modulo i2c
#define filas 2//se indica que numero de filas que tiene el lcd que son dos para despues utilizarlo
#define columnas 16//se indica el numero de columnas que tiene el lcd que son 16 
LiquidCrystal_I2C pantallalcd(lcdAddress, columnas, filas);//se llama la libreria LiquidCrystal_I2C se le indica el nombre de pantallalcd se le indica la direcciÃ³n del lcd,la variable columnas y filas

const float Factor_1 = 0.185; //Factor de Medicion para lectura de -5A a 5A
const float Factor_2 = 0.1; //Factor de Medicion para lectura de -20A a 20A
const float Factor_3 = 0.066; //Factor de Medicion para lectura de -30A a 30A
int Lectura = 0; // Lectura del pin A////7ds l0
double Corriente = 0; //Guarda el valor de la corriente leida en el sensor
float voltajeSensor = 0; //guarda los valores de 0 a 5 

const float Factor = 1.25; // Constante del Factor de Lectura
int lectura_1 = 0; //Guardar La lectura hecha por el sensor


int pul_1 = 2;//al pin que va
int pul_2 = 3;//al pin que va
int valor =0;//nos ayuda a contener algun valor
int valor_2 =0; //nos ayuda a contener algun valor


void setup() {
  Serial.begin(9600); //Inicializa la comunicacion Serial
  pantallalcd.init();//se indica que la pantallalcd que en eso se iniciara
 pantallalcd.backlight();//se indica que la pantallalcd para su iluminaciÃ³n
 pinMode(pul_1, OUTPUT);//indica el pin
 pinMode(pul_2, OUTPUT);//indica el pin
  pantallalcd.clear();//que limpie 
  pantallalcd.setCursor(0,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD 
  pantallalcd.print("   MEDICIONES  ");//que se imprima corriente:
  pantallalcd.setCursor(0,1);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD 
  pantallalcd.print("I:pul1  ");//que se imprima corriente:
  pantallalcd.print("V:pul2");//que se imprima corriente:
 attachInterrupt(digitalPinToInterrupt(pul_1),travis,CHANGE);//SE UTILIZA PARA INTERUPCIÓN
 attachInterrupt(digitalPinToInterrupt(pul_2),drake,CHANGE);//SE UTILIZA PARA INTERUPCIÓN

}

void loop() {
  if(valor == 250){//si ese igual al valor haga lo que esta adentro
    valor_2 = 0;//que el valor sea 0 ahora 
    corriente();//si ese igual al valor haga lo que esta adentro
  } 



  if(valor_2 == 150){
    valor = 0;//que el valor sea 0 ahora 
    voltaje();//si ese igual al valor haga lo que esta adentro
  }

}

void corriente(){
  Lectura = analogRead(A0); //Leer el pin analogico
  voltajeSensor = (Lectura*5.0) / 1023.0; //lectura del sensor   
  Corriente = (voltajeSensor - 2.5)/Factor_3; //Ecuación  para obtener la corriente
  pantallalcd.clear();//que limpie la pantalla lcd
  pantallalcd.setCursor(0,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD 
  pantallalcd.print("CORRIENTE: ");//que se imprima corriente:
  pantallalcd.setCursor(0,1);//que posición 
  pantallalcd.print(Corriente,3);//que imprima el valor de la corriente 
  pantallalcd.print(" A");//que imprima el valor de corriemte 
  delay(200);
}
void voltaje(){
  lectura_1 = analogRead(A1); //Para hacer la lectura del pin A0
  float voltaje =  (5*lectura_1*Factor)/1023; // Conversion de lectura analogica a valores de medicion
  pantallalcd.clear();//que limpie la pantalla lcd
  pantallalcd.setCursor(0,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD 
  pantallalcd.print("VOLTAJE: ");//que se imprima corriente:
  pantallalcd.setCursor(0,1);//que posición 
  pantallalcd.print(voltaje);//que imprima el valor de la corriente 
  pantallalcd.print("V");//que imprima el valor de corriemte 
  delay(200);
  Serial.println(voltaje);
}

void travis(){
  valor = 250;//que sea ese valor
}

void drake(){
  valor_2 = 150;//que sea ese valor
}



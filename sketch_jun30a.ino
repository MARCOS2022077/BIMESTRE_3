#include "Ticker.h"
#include <LedControl.h> //libreria para las led matricial

void impresion(void);

Ticker Interrupcion(impresion, 3000); //Cada 3 segundos, realiza una interrupcion
LedControl MATLED = LedControl(11,13,10,1);	// crea objeto


//caracter signo de interrogacion
byte caracter[8]{
0x8, 0x8, 0x8, 0x8, 0x8, 0x0, 0x1c, 0x1c
};
//caracter flama
byte caracter_1[8]{
0x1c, 0x3e, 0x7f, 0x7f, 0x3e, 0x1c, 0x8, 0x0
};
//caracter M
byte caracter_2[8]{
0x0, 0x42, 0x66, 0x5a, 0x42, 0x42, 0x42, 0x0
};
//caracter A
byte caracter_3[8]{
0x18, 0x24, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x0
};
//caracter R
byte caracter_4[8]{
0x0, 0x7c, 0x44, 0x44, 0x5c, 0x48, 0x44, 0x42
};
//caracter C
byte caracter_5[8]{
0x0, 0x3c, 0x42, 0x40, 0x40, 0x42, 0x3c, 0x0
};
//caracter O
byte caracter_6[8]{
0x0, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x0
};
//caracter S
byte caracter_7[8]{
0x3c, 0x42, 0x42, 0x40, 0x38, 0x4, 0x4, 0x78
};
//caracter 2
byte caracter_8[8]{
0x1c, 0x24, 0x4, 0x8, 0x10, 0x3e, 0x0, 0x0
};
//caracter 0
byte caracter_9[8]{
0x0, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x0
};
//caracter 7
byte caracter_10[8]{
0x3f, 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x0
};


int evalua;//nos ayudara a evaluar el valor del sensor 
int buzz=2;//indica el pin del buzzer
int sensor=A1;//indica el pin del sensor 


void setup() {
  Serial.begin(9600);    //Inicio la comunicacion serial	
  MATLED.shutdown(0,false);			// enciende la matriz
  MATLED.setIntensity(0,4);			// establece brillo
  MATLED.clearDisplay(0);	//se indica para limpiar la matriz led
  Interrupcion.start();   //Inicializa la libreria y las interrupciones por software
  pinMode(buzz, OUTPUT); //que el pin buzz se encuentra como salida
  //IMPRIMA TODO LOS CARACTERES INDICADOS 
  delay(2000);
  figura_1();//llama
  delay(500);
  figura_2();//M
  delay(500);
  figura_3();//A
  delay(500);
  figura_4();//R
  delay(500);
  figura_5();//C
  delay(500);
  figura_6();//O
  delay(500);
  figura_7();//S
  delay(500);
  figura_8();//2
  delay(500);
  figura_9();//0
  delay(500);
  figura_8();//2
  delay(500);
  figura_8();//2
  delay(500);
  figura_9();//0
  delay(500); 
  figura_10();//7
  delay(500);
  figura_10();//7
  delay(500);

}

void loop() {
  Interrupcion.update(); //Actualiza la libreria para poder mantener la interrupcion al pendiente

  evalua = analogRead(sensor);
  if(evalua <400){
    digitalWrite(buzz, HIGH);//que encienda el buzzer
    figura();//Que haga lo que esta en la funcion
    delay(1000);//tome un descanso
    MATLED.clearDisplay(0);	//se indica para limpiar la matriz led
    figura_1();
    delay(1000);//tome un descanso
    MATLED.clearDisplay(0);	//se indica para limpiar la matriz led
  }else{
    digitalWrite(buzz, LOW);//APAGAR EL BUZZ
    delay(10);
    MATLED.clearDisplay(0);	//se indica para limpiar la matriz led
  }

}



//funcion para interrogacion
void figura(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la llama
void figura_1(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_1[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la   M
void figura_2(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_2[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la A
void figura_3(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_3[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la R
void figura_4(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_4[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la C
void figura_5(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_5[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la O
void figura_6(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_6[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la S
void figura_7(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_7[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}


//funcion para la 2
void figura_8(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_8[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la 0
void figura_9(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_9[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la 7
void figura_10(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_10[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}


//par la interrupcion 
void impresion(void){
 Serial.println(evalua);//se imprima el valor del sensor
}


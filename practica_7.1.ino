#include <Wire.h>//se llama la libreria Wire que nos ayudara a comunicarnos con el dispositivos de I2C
#include <LiquidCrystal_I2C.h>//se instala la libreria LiquidCrystal_I2C para trabajar con el i2c del lcd junto con el MÃ³dulo serial I2C
#include <SPI.h>			// incluye libreria bus SPI
#include <MFRC522.h>			// incluye libreria especifica para MFRC522
#include <Servo.h>//se instala esta libreria para el servo motor

#define RST_PIN  9			// constante para referenciar pin de reset
#define SS_PIN  10			// constante para referenciar pin de slave select

#define lcdAddress 0x27  //se indica la direcciÃ³n que toma el modulo i2c
#define filas 2//se indica que numero de filas que tiene el lcd que son dos para despues utilizarlo
#define columnas 16//se indica el numero de columnas que tiene el lcd que son 16 
LiquidCrystal_I2C pantallalcd(lcdAddress, columnas, filas);//se llama la libreria LiquidCrystal_I2C se le indica el nombre de pantallalcd se le indica la direcciÃ³n del lcd,la variable columnas y filas


MFRC522 mfrc522(SS_PIN, RST_PIN);	// crea objeto mfrc522 enviando pines de slave select y reset

byte LecturaUID[4]; 				// crea array para almacenar el UID leido
byte Usuario1[4]= {0xB2, 0x54, 0x9E, 0x1C} ;    // UID de tarjeta leido en programa 1
byte Usuario2[4]= {0x13, 0xFD, 0x71, 0xA5} ;    // UID de llavero leido en programa 1

int pin_R = 2;//pin de la led
int pin_V = 3;//pin de la led
int buzzer = 4;//pin de la led
Servo dota;//SE CREA LA VARIABLE PARA EL SERVO MOTOR

void setup() {
  pantallalcd.init();//se indica que la pantallalcd que en eso se iniciara
  pantallalcd.backlight();//se indica que la pantallalcd para su iluminaciÃ³n
  Serial.begin(9600);			// inicializa comunicacion por monitor serie a 9600 bps
  SPI.begin();				// inicializa bus SPI
  mfrc522.PCD_Init();			// inicializa modulo lector
  Serial.println("Listo");		// Muestra texto Listo
  pinMode(pin_R, OUTPUT);//se indica como esta el pin
  pinMode(pin_V, OUTPUT);//se indica como esta el pin
  pinMode(buzzer, OUTPUT);//se indica como esta el pin
  dota.attach(5);//el pin que esta el servo
  dota.write(0);//que inicie en 0
}

void loop() {
  inicio();
  delay(10);
  if ( ! mfrc522.PICC_IsNewCardPresent())		// si no hay una tarjeta presente
    return;						// retorna al loop esperando por una tarjeta
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 		// si no puede obtener datos de la tarjeta
    return;						// retorna al loop esperando por otra tarjeta
    
    Serial.print("UID:");				// muestra texto UID:
    for (byte i = 0; i < mfrc522.uid.size; i++) {	// bucle recorre de a un byte por vez el UID
      if (mfrc522.uid.uidByte[i] < 0x10){		// si el byte leido es menor a 0x10
        Serial.print(" 0");				// imprime espacio en blanco y numero cero
        }
        else{						// sino
          Serial.print(" ");				// imprime un espacio en blanco
          }
          Serial.print(mfrc522.uid.uidByte[i], HEX);   	// imprime el byte del UID leido en hexadecimal
          LecturaUID[i]=mfrc522.uid.uidByte[i];   	// almacena en array el byte del UID leido      
          }
          
          Serial.print("\t");   			// imprime un espacio de tabulacion             
                    
          if(comparaUID(LecturaUID, Usuario1))		// llama a funcion comparaUID con Usuario1
            cumple();// que haga la funcion  
          else if(comparaUID(LecturaUID, Usuario2))	// llama a funcion comparaUID con Usuario2
            cumple_2();// que haga la funcion  
           else						// si retorna falso
            Ncumple(); // que haga la funcion          
                  
                  mfrc522.PICC_HaltA();  		// detiene comunicacion con tarjeta                
}

boolean comparaUID(byte lectura[],byte usuario[])	// funcion comparaUID
{
  for (byte i=0; i < mfrc522.uid.size; i++){		// bucle recorre de a un byte por vez el UID
  if(lectura[i] != usuario[i])				// si byte de UID leido es distinto a usuario
    return(false);					// retorna falso
  }
  return(true);						// si los 4 bytes coinciden retorna verdadero
}

void Ncumple(){
  Serial.println("No te conozco"); 		// muestra texto equivalente a acceso denegado  
  pantallalcd.clear();//LIMPIE
  pantallalcd.setCursor(1,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
  pantallalcd.print("No te conozco");//que imprima 
  delay(1000);
  pantallalcd.clear();//LIMPIE
  digitalWrite(pin_V, LOW);//que apague el pin
  digitalWrite(pin_R, HIGH);//que encienda el pin
  tone(buzzer, 100, 500);//que encienda el buzz
  delay(500);
  noTone(buzzer);//que apague el buzz
  delay(500);
  tone(buzzer, 100, 500);//que encienda el buzz
  delay(500);
  noTone(buzzer); //que apague el buzz
}

void cumple(){
  Serial.println("Bienvenido Usuario 1");	// si retorna verdadero muestra texto bienvenida
  pantallalcd.clear();//LIMPIE
  pantallalcd.setCursor(1,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
  pantallalcd.print("  Bienvenido");
  pantallalcd.setCursor(0,1);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
  pantallalcd.print("  usuario 1");
  delay(1000);
  pantallalcd.clear();//LIMPIE
  digitalWrite(pin_V, HIGH);//que encienda el pin
  digitalWrite(pin_R, LOW);//que apague el pin
  dota.write(90);//que gire a los grados 
  tone(buzzer, 300, 600);//que encienda el buzz
  delay(500);
  noTone(buzzer);//que apague el buzz
  delay(500);
  tone(buzzer, 400, 600);//que encienda el buzz
  delay(500);
  noTone(buzzer);//que apague el buzz
  dota.write(0);//que gire a los grados 
  digitalWrite(pin_V, LOW);//que apague el pin

}

void cumple_2(){
  Serial.println("Bienvenido Usuario 2");	// si retorna verdadero muestra texto bienvenida
  pantallalcd.clear();//LIMPIE
  pantallalcd.setCursor(1,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
  pantallalcd.print("  Bienvenido");
  pantallalcd.setCursor(0,1);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
  pantallalcd.print("  usuario 2");
  delay(1000);
  pantallalcd.clear();//LIMPIE
  digitalWrite(pin_R, LOW);//que apague el pin
  digitalWrite(pin_V, HIGH);//que encienda el pin
  dota.write(90);//que gire a los grados 
  tone(buzzer, 200, 200);//que encienda el buzz
  delay(500);
  noTone(buzzer);//que apague el buzz
  delay(200);
  tone(buzzer, 200, 200);//que encienda el buzz
  delay(500);
  noTone(buzzer);//que apague el buzz
  dota.write(0);//que gire a los grados 
  digitalWrite(pin_V, LOW);//que apague el pin
}
void inicio(){
  pantallalcd.setCursor(1,0);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
  pantallalcd.print("   Entrada");//imprima entrada
  pantallalcd.setCursor(0,1);//QUE SE PONGA EN ESA POSICIÓN DE LA LCD
  pantallalcd.print("ingrese la tarjeta");//imprima que ingrese la tarjeta 
}


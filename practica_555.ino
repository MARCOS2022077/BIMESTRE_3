#include <Wire.h> //Libreria I2C
#include <Adafruit_Sensor.h> // Libreria para Acelerometro
#include <Adafruit_ADXL345_U.h> //Libreria para Acelerometro
#include <Servo.h>//Ingreso libreria

Servo servo;//Asigno el servo
Servo servo_2;//Asigno el servo

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(); //Coloco Nombre al Acelerometro
int Eje_X = 0; //Variable para la aceleracion en eje X
int Eje_Y = 0; //Variable para la aceleracion en eje Y
int po_x;//creacion de valor de dato 1
int po_PY;//creacion de valor de dato 2

void setup(void) {
Serial.begin(9600); //Inicializo el monitor serial a 9600bps
accel.begin();// Inicializo libreria del acelerometro
servo.attach(6);//Asigno el pin del servo
servo_2.attach(8);//Asigno el pin del servo
}

void loop(void) {
sensors_event_t event; //Le coloco un nombre a las lecturas del acelerometro
accel.getEvent(&event); //los datos de las lecturas del acelerometro se pasan a la funcion que envia los datos
Eje_X = event.acceleration.x; //Asigna la lectura del acelerometro en el eje X
Eje_Y = event.acceleration.y; //Asigna la lectura del acelerometro en el eje Y

po_x = map(Eje_X, -10, 10, -90, 90);//Mapeo y resa
po_PY = map(Eje_Y, -1, 10, -90, 90);//Mapeo y resa
servo.write(po_x);//eje x
servo_2.write(po_PY);//eje x


Serial.print("X: "); Serial.print(Eje_X); Serial.print(" ");//eje x
Serial.print("Y: "); Serial.print(Eje_Y); Serial.println(" ");//eje y
delay(100);
}

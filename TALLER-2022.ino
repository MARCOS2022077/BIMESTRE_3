//1 endicamos a que pines van cada uno
const int infra=3;
const int led=2;
//2
const int infra1=5;
const int led1=4;
//3
const int infra2=7;
const int led2=6;
//4
const int infra3=9;
const int led3=8;



void setup() {
  //1
  pinMode(infra,INPUT);
  pinMode(led,OUTPUT);
  //2
  pinMode(infra1,INPUT);
  pinMode(led1,OUTPUT);
  //3
  pinMode(infra2,INPUT);
  pinMode(led2,OUTPUT);
  //4
  pinMode(infra3,INPUT);
  pinMode(led3,OUTPUT);

}
void loop() {
int valor = digitalRead(infra);//indicamos que valor va a hacer lo mismo que el digitalRead
if(valor == LOW){//si cumple la condición va a realizar lo siguiente
  digitalWrite(led, HIGH);//se se cumple esto la led se encendera
  delay(50);//se tome un tiempo 
}else{//si no hace esto 
  digitalWrite(led, LOW);//el led estara apagdo 
  delay(50);//se tome un tiempo 
}

int valor1 = digitalRead(infra1);//indicamos que valor va a hacer lo mismo que el digitalRead
if(valor1==LOW){//si cumple la condición va a realizar lo siguiente
  digitalWrite(led1, HIGH);//se se cumple esto la led se encendera
  delay(50);//se tome un tiempo 
}else{//si no hace esto 
  digitalWrite(led1, LOW);//el led estara apagdo 
  delay(50);//se tome un tiempo 
}

int valor2 = digitalRead(infra2);//indicamos que valor va a hacer lo mismo que el digitalRead
if(valor2==LOW){//si cumple la condición va a realizar lo siguiente
  digitalWrite(led2, HIGH);//se se cumple esto la led se encendera
  delay(50);//se tome un tiempo 
}else{//si no hace esto 
  digitalWrite(led2, LOW);//el led estara apagdo 
  delay(50);//se tome un tiempo 
}

int valor3 = digitalRead(infra3);//indicamos que valor va a hacer lo mismo que el digitalRead
if(valor3==LOW){//si cumple la condición va a realizar lo siguiente
  digitalWrite(led3, HIGH);//se se cumple esto la led se encendera
  delay(50);//se tome un tiempo 
}else{//si no hace esto 
  digitalWrite(led3, LOW);//el led estara apagdo 
  delay(50);//se tome un tiempo 
}

}



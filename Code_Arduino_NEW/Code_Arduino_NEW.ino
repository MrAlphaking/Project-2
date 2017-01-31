#include <Servo.h>     
#define trigPin1 7
#define echoPin1 6
#define trigPin2 11
#define echoPin2 10
#define trigPin3 9
#define echoPin3 8
Servo left;
Servo right;

void setup() {
 Serial.begin (9600);
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 pinMode(trigPin3, OUTPUT);
 pinMode(echoPin3, INPUT);
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
 left.attach(3);
 right.attach(5);
 Stop();
 
}

void loop() {
 if(sensor0() > 10 || sensor1() < 9){ //geen muur of geen afgrond voor.

  if(sensor2() <= 13){ //muur links.
   center();
  }
  
  else if(sensor2() > 13){ //geen muur links.
    vooruit();
    delay(430);
    turnLeft();
    vooruit();
    delay(430);
  }
 }


 if((sensor0() < 10 && sensor0() > 0 || sensor1() >= 9) && sensor2() <= 13 ){ //muur of afgrond en muur links.
  
    if(sensor1() >= 9) { //indien afgrond ga eerst achteruit.
      achteruit();
      delay(400);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    }
   turnRight();
   
   if (sensor0() > 8){
    vooruit();
    delay(200);
   }
   
   else if(sensor0() <= 8){
      turnRight();
   }
   
 }

}

int sensor0(){
  int duration, distance;
  digitalWrite(trigPin1, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println("Sensor 0");
  Serial.println(distance);
  if(distance < 0){ //indien distance negatief is.
    distance = 0;
  }
    return distance;
}

int sensor1(){
  int duration, distance;
  digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println("Sensor 1");
  Serial.println(distance);
  if(distance < 0){ //indien distance negatief is.
    distance = 0;
  }
    return distance;
}


int sensor2(){
  int duration, distance;
  digitalWrite(trigPin3, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin3, LOW);
  duration = pulseIn(echoPin3, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println("Sensor 2");
  Serial.println(distance);
  if(distance < 0){ //indien distance negatief is.
    distance = 0;
  }
    return distance;
}

void vooruit(){
 left.writeMicroseconds(1570);
 right.writeMicroseconds(0);
}
void Stop(){
 left.writeMicroseconds(1532);
 right.writeMicroseconds(1505);
}
void achteruit(){
 left.writeMicroseconds(1500);
 right.writeMicroseconds(1900);
}

void turnRight(){
 left.writeMicroseconds(1570);
 right.writeMicroseconds(1590);
 delay(585);
 left.writeMicroseconds(1532);
 right.writeMicroseconds(1505);
 delay(450);
}

void turnLeft(){
 left.writeMicroseconds(1500);
 right.writeMicroseconds(0);
 delay(525);
 left.writeMicroseconds(1532);
 right.writeMicroseconds(1505);
 delay(450);
}

void checkDL(){
 left.writeMicroseconds(1550);
 right.writeMicroseconds(100);
}

void checkDR(){
 left.writeMicroseconds(1580);
 right.writeMicroseconds(300);
}

void center(){
    if(sensor2() < 7){
      checkDR();
    }
    else if(sensor2() >= 7){
      checkDL();
    }
}


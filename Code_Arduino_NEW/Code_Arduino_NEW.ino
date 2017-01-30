#include <Servo.h>     
#define trigPin1 7
#define echoPin1 6
#define trigPin2 11
#define echoPin2 10
#define trigPin3 9
#define echoPin3 8
int right = 3;
int left = 5;


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
  pinMode(left,OUTPUT);
 pinMode(right,OUTPUT);
 
}

void loop() {
    //CW(right);
    //CCW(left);
 if(sensor0() > 10  /*&& sensor1() <= 13 && sensor2() <= 13*/){ //geen muur voor, muur links
    CW(right);
    CW(left);
  }
  /*if(sensor0() <= 10){
    CW(right);
    CW(left);
    delay(200);
  }*/

  /*else if(sensor1() > 13) { //geen muur links

    CW(right);
    CW(left);
    delay(300); //draai links
    
   if(sensor2() > 13){ //13
    CCW(right);
    CCW(left); //draai rechts 90 graden
    delay(200);
      
      if(sensor0() < 10 && sensor2() < 13){ //geen AFGROND voor
        CW(right);
        CCW(left);
      }
      else {
        CCW(right);
        CCW(left); //draai rechts 90 graden
        delay(200);
      }
    }
    
    else{ //geen afgrond, rij rechtdoor.
      CW(right);
      CCW(left);
    }
    
  }

    else if(sensor0() <= 10 && sensor1() <= 13){ //muur links, muur voor.
    
      CCW(right);
      CCW(left); //draai rechts 45 graden
      delay(100);
     
    }
  
  if(sensor1() <= 13 && sensor2 > 13) { //afgrond voor, geen muur links

    CW(right);
    CW(left);
    delay(300); //draai links.
    
    
    if(sensor2() > 13){ //13
       CCW(right);
       CCW(left); //draai rechts 1130 graden
       delay(200);
    }
    
    else{ //geen afgrond
      CW(right);
      CCW(left);;
    } 
  }*/
}

int sensor0(){
  int duration, distance;
  digitalWrite(trigPin1, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH);
  //delayMicroseconds(10); 
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
void CCW(int motor){
  digitalWrite(motor, HIGH);
  delayMicroseconds(2100);
  digitalWrite(motor,LOW);
}
void CW(int motor){
  digitalWrite(motor, HIGH);
  delayMicroseconds(200);
  digitalWrite(motor,LOW);
}
void STOP(int motor){
  digitalWrite(motor, HIGH);
  delayMicroseconds(1150);
  digitalWrite(motor,LOW);
}


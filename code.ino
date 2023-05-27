#include <AFMotor.h>


#define left A2
#define right A1
#define TRIG_PIN A4 
#define ECHO_PIN A5 
#define MAX_DISTANCE 200 

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int redPin= 12;
int greenPin = 10;
int bluePin = 7;

void setup() {
  setColor(255, 0, 0);
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
}

void loop(){
  Serial.println(digitalRead(left));
  Serial.println(digitalRead(right));

  //line detected by both
  if(digitalRead(left)==0 && digitalRead(right)==0){
    //Forward
    setColor(0, 255, 0);
    motor1.run(FORWARD);
    motor1.setSpeed(125);
    motor2.run(FORWARD);
    motor2.setSpeed(125);
    motor3.run(FORWARD);
    motor3.setSpeed(125);
    motor4.run(FORWARD);
    motor4.setSpeed(125);
  }
  //line detected by left sensor
  else if(digitalRead(left)==0 && !analogRead(right)==0){
    //turn left
    setColor(200, 30, 0);
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(BACKWARD);
    motor3.setSpeed(200);
    motor4.run(BACKWARD);
    motor4.setSpeed(200);
    
  }
  //line detected by right sensor
  else if(!digitalRead(left)==0 && digitalRead(right)==0){
    //turn right
    setColor(200, 30, 0);
    motor1.run(BACKWARD);
    motor1.setSpeed(200);
    motor2.run(BACKWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(FORWARD);
    motor4.setSpeed(200);
   
  }
  //line detected by none
  else if(!digitalRead(left)==0 && !digitalRead(right)==0){
    //stop
    setColor(255, 0, 0);
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
   
  }
  
}
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

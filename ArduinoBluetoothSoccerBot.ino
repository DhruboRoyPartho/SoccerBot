#include <AFMotor.h>
#include <SoftwareSerial.h>

#define Rx A0
#define Tx A1
#define l_speed 80
#define h_speed 255

SoftwareSerial newSerial(Rx, Tx);

AF_DCMotor motor_f1(3);
AF_DCMotor motor_f2(4);
AF_DCMotor motor_b1(2);
AF_DCMotor motor_b2(1);

char cmd;

void goAhead()
{
  motor_f1.setSpeed(255);
  motor_f2.setSpeed(255);
  motor_b1.setSpeed(255);
  motor_b2.setSpeed(255);
  
  motor_f1.run(FORWARD);
  motor_f2.run(FORWARD);
  motor_b1.run(FORWARD);
  motor_b2.run(FORWARD);
}

void goBack()
{
  motor_f1.setSpeed(255);
  motor_f2.setSpeed(255);
  motor_b1.setSpeed(255);
  motor_b2.setSpeed(255);
  
  motor_f1.run(BACKWARD);
  motor_f2.run(BACKWARD);
  motor_b1.run(BACKWARD);
  motor_b2.run(BACKWARD);
}

void rightMove()
{
  motor_f1.setSpeed(255);
  motor_f2.setSpeed(255);
  motor_b1.setSpeed(255);
  motor_b2.setSpeed(255);
  
  motor_f1.run(BACKWARD);
  motor_f2.run(FORWARD);
  motor_b1.run(BACKWARD);
  motor_b2.run(FORWARD);
}

void leftMove()
{
  motor_f1.setSpeed(255);
  motor_f2.setSpeed(255);
  motor_b1.setSpeed(255);
  motor_b2.setSpeed(255);
  
  motor_f1.run(FORWARD);
  motor_f2.run(BACKWARD);
  motor_b1.run(FORWARD);
  motor_b2.run(BACKWARD);
}

void frontRight()
{
  motor_f1.setSpeed(l_speed);
  motor_f2.setSpeed(255);
  motor_b1.setSpeed(l_speed-10);
  motor_b2.setSpeed(255);
  
  motor_f1.run(FORWARD);
  motor_f2.run(FORWARD);
  motor_b1.run(FORWARD);
  motor_b2.run(FORWARD);
}

void frontLeft()
{
  motor_f1.setSpeed(255);
  motor_f2.setSpeed(l_speed);
  motor_b1.setSpeed(255);
  motor_b2.setSpeed(l_speed-10);
  
  motor_f1.run(FORWARD);
  motor_f2.run(FORWARD);
  motor_b1.run(FORWARD);
  motor_b2.run(FORWARD);
}

void backRight()
{
  motor_f1.setSpeed(l_speed-10);
  motor_f2.setSpeed(255);
  motor_b1.setSpeed(l_speed);
  motor_b2.setSpeed(255);

  motor_f1.run(BACKWARD);
  motor_f2.run(BACKWARD);
  motor_b1.run(BACKWARD);
  motor_b2.run(BACKWARD);
}

void backLeft()
{
  motor_f1.setSpeed(255);
  motor_f2.setSpeed(l_speed-10);
  motor_b1.setSpeed(255);
  motor_b2.setSpeed(l_speed);

  motor_f1.run(BACKWARD);
  motor_f2.run(BACKWARD);
  motor_b1.run(BACKWARD);
  motor_b2.run(BACKWARD);
}

void Stop()
{
  motor_f1.setSpeed(255);
  motor_f2.setSpeed(255);
  motor_b1.setSpeed(255);
  motor_b2.setSpeed(255);
  
  motor_f1.run(RELEASE);
  motor_f2.run(RELEASE);
  motor_b1.run(RELEASE);
  motor_b2.run(RELEASE);
}

void setup() {
  // put your setup code here, to run once:
  motor_f1.setSpeed(255);
  motor_f2.setSpeed(255);
  motor_b1.setSpeed(255);
  motor_b2.setSpeed(255);

//  Serial.begin(230400);
  newSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(newSerial.available()>0){
    cmd = newSerial.read();
    //Serial.println(cmd);
    switch(cmd){
      case 'F':
//            Serial.println("front");
            goAhead();
            break;
      case 'B':
//            Serial.println("back");
            goBack();
            break;
      case 'L':
//            Serial.println("left");
            leftMove();
            break;
      case 'R':
//            Serial.println("right");
            rightMove();
            break;
      case 'G':
            Serial.println("front left");
            frontLeft();
            break;
      case 'I':
//            Serial.println("front right");
            frontRight();
            break;
      case 'H':
//            Serial.println("back left");
            backLeft();
            break;
      case 'J':
//            Serial.println("back right");
            backRight();
            break;
      case 'S':
            Serial.println("stop");
            Stop();
            break;
      default:
//            Serial.println("stop");
            Stop();
            break; 
    }
  }
}

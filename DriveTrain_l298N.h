#include "Arduino.h"
class DriveTrain_l298N {
public:
  DriveTrain_l298N(int in1, int in2, int in3, int in4) {
    _left1 = in1;
    _left2 = in2;
    _right1 = in3;
    _right2 = in4;
    pinMode(_left1, OUTPUT);
    pinMode(_left2, OUTPUT);
    pinMode(_right1, OUTPUT);
    pinMode(_right2, OUTPUT);
  }

  void stop() {
    digitalWrite(_left1, 0);
    digitalWrite(_left2, 0);
    digitalWrite(_right1, 0);
    digitalWrite(_right2, 0);
    delay(50);
  }

  void move(int leftPwr, int rightPwr) {
    leftPwr = constrain(leftPwr, -255, 255);
    rightPwr = constrain(rightPwr, -255, 255);
    if (leftPwr > 0) {
      digitalWrite(_left2, 0);
      analogWrite(_left1, leftPwr);
    } else {
      digitalWrite(_left1, 0);
      analogWrite(_left2, abs(leftPwr));
    }
	
    if (rightPwr > 0) {
      digitalWrite(_right2, 0);
      analogWrite(_right1, rightPwr);
    } else {
      digitalWrite(_right1, 0);
      analogWrite(_right2, abs(rightPwr));
    }
  }

  void move(int leftPwr, int rightPwr, int millsec) {
    move(leftPwr, rightPwr);
    delay(millsec);
    stop();
  }
  void reverse() {
    int a = _left1;
    _left1 = _right1;
    _right1 = a;
    a = _left2;
    _left2 = _right2;
    _right2 = a;
  }

  void reverseLeftMotor() {
    int a = _left1;
    _left1 = _left2;
    _left2 = a;
  }
  void reverseRightMotor() {
    byte a = _right1;
    _right1 = _right2;
    _right2 = a;
  }
  void setMaxPwrValue(unsigned int val){
    _maxPwrValue = val;
  }
  
  void pMove(int error, int pwr, float kp){
    int Psost = error * kp;
    move(pwr - Psost, pwr + Psost);
  }
  void pMove(int error, int pwr, float kp, int millsec){
	long currentMillis = millis();
	while (millis() - currentMillis < millsec) pMove(error, pwr, kp);
    stop();
  }
  
private:
  int _left1, _left2, _right1, _right2;
  unsigned int _maxPwrValue = 255;
};
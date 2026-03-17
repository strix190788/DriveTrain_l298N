class DriveTrain_l298N {
public:
  DriveTrain_l298N(byte in1, byte in2, byte in3, byte in4) {
    motor[0][0] = in1;
    motor[0][1] = in2;
    motor[1][0] = in3;
    motor[1][1] = in4;
    pinMode(motor[0][0], OUTPUT);
    pinMode(motor[1][0], OUTPUT);
    pinMode(motor[1][1], OUTPUT);
    pinMode(motor[0][1], OUTPUT);
  }
  void reverseLeftMotor() {
    motor[0][2] = not motor[0][2];
  }
  void reverseRightMotor() {
    motor[1][2] = not motor[1][2];
  }

  void stop() {
    digitalWrite(motor[0][0], 0);
    digitalWrite(motor[0][1], 0);
	digitalWrite(motor[1][0], 0);
    digitalWrite(motor[1][1], 0);
    delay(50);
  }

  void move(int pwrLeft, int pwrRight) {
    pwrLeft = constrain(pwrLeft, -255, 255);
    pwrRight = constrain(pwrRight, -255, 255);
    if (motor[0][2]==1) pwrLeft = pwrLeft * (-1);
    if (motor[1][2]==1) pwrRight = pwrRight * (-1);
	
    if (pwrLeft > 0) {
      
        digitalWrite(motor[0][0], 0);
        analogWrite(motor[0][1], pwrLeft);
      } else {
        digitalWrite(motor[0][1], 0);
        analogWrite(motor[0][0], abs(pwrLeft));
      }
    
    if (pwrRight > 0) {
      
        digitalWrite(motor[1][0], 0);
        analogWrite(motor[1][1], pwrRight);
      } 
	  else {
        digitalWrite(motor[1][1], 0);
        analogWrite(motor[1][0], abs(pwrRight));
    }
    
  }

  void move(byte pwrLeft, byte pwrRight, int millsec) {
    move(pwrLeft, pwrRight);
    delay(millsec);
    stop();
  }

  void reverse() {
    for (int i = 0; i < 3; i++) {
      byte a = motor[0][i];
      motor[0][i] = motor[1][i];
      motor[1][i] = a;
    }
    reverseLeftMotor();
    reverseRightMotor();
  }

private:
  byte motor[2][3] = { {0,0,0}, {0,0,0} };
};
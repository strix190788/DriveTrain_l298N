class driveTrain {
public:
  driveTrain(int in1, int in2, int in3, int in4) {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    _in1 = in1;
    _in2 = in2;
    _in3 = in3;
    _in4 = in4;
  }
  void move(int leftpwr, int rightpwr){
    analogWrite(_in1, leftpwr);
    digitalWrite(_in2, 0);

    analogWrite(_in3, rightpwr);
    digitalWrite(_in4, 0);
  }
private:
  int _in1, _in2, _in3, _in4;
};
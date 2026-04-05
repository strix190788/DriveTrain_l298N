#include <DriveTrain_l298N.h>
DriveTrain_l298N bot(3, 5, 11, 9);
void setup() {
  bot.move(80, 80, 2000);
  bot.move(-80, -80, 2000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
}

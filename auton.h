#define AUTON_L 0
#define AUTON_R 1

int Program = 0;

void auton()
{
  setBucket(-255);
  setL(255);
  setR(255);
  wait1Msec(1250);
  setBucket(20);
}

void autonL()
{
  auton();
}

void autonR()
{
  auton();
}

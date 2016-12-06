#define AUTON_L 0
#define AUTON_R 1

int Program = 0;

void autonR();
//b
void autonL()
{
	resetIme();
	setL(96);
	setR(24);
	while(  (abs(SensorValue[imeL])+abs(SensorValue[imeR]))/2.0 < 500 ){}
	setR(0);
	setL(-96);
	while(SensorValue[imeR]<150){}
	setR(0);
	setL(64);
	setR(64);
	wait1Msec(500);
	setL(0);
	setR(0);
	setE(255);
	while(abs(SensorValue[imeE])<2000);
	setE(-255);
	while(abs(SensorValue[imeE])>100);
	setE(0);
	motor[lock] = 128;
}
//r
void autonR()
{
	resetIme();
	setR(96);
	setL(24);
	while(  (abs(SensorValue[imeR])+abs(SensorValue[imeL]))/2.0 < 500 ){}
	setL(0);
	setR(-96);
	while(SensorValue[imeL]<150){}
	setL(0);
	setR(64);
	setL(64);
	wait1Msec(500);
	setR(0);
	setL(0);
	setE(255);
	while(abs(SensorValue[imeE])<2000);
	setE(-255);
	while(abs(SensorValue[imeE])>100);
	setE(0);
	motor[lock] = 128;
}

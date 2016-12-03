#define ELEVATOR_SPEED 255
#define ELEVATOR_REST 8

#define R_FACTOR 1
#define L_FACTOR -1

void setL(int val) {
	motor[left1] = motor[left2] = val * L_FACTOR;
}

void setR(int val) {
	motor[right1] = motor[right2] = val * R_FACTOR;
}

void setE(int val) {
	motor[elevator1] = motor[elevator2] = motor[elevator3] = motor[elevator4] = val;
}

void resetIme() {
	SensorValue[imeE] = SensorValue[imeL] = SensorValue[imeR] = 0;
}

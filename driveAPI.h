#define ELEVATOR_SPEED 255
#define ELEVATOR_REST 32

void setL(int val) {
	motor[left1] = motor[left2] = val;
}

void setR(int val) {
	motor[right1] = motor[right2] = val;
}

void setE(int val) {
	motor[elevator1] = motor[elevator2] = motor[elevator3] = motor[elevator4] = val;
}


#define MULT_L 1
#define MULT_R 1
#define MULT_LAT 255
#define MULT_SXR 1
#define MULT_BKT 255
#define MULT_FRG 255

void setL(int drive)
{
	motor[driveLeft] = drive * MULT_L;
}

void setR(int drive)
{
	motor[driveRight] = drive * MULT_R;
}

void setLateral(int drive)
{
	motor[driveLateral] = drive * MULT_LAT;
}

void setScissor(int drive)
{
	motor[motorScissor1] = motor[motorScissor2] = drive * MULT_SXR;
}

void setBucket(int drive)
{
	motor[motorBucket] = drive * MULT_BKT;
}

void setFiring(int drive)
{
	motor[motorFiring] = drive * MULT_FRG;
}

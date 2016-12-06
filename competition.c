#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  armRight,       sensorNone)
#pragma config(Sensor, dgtl12, override,       sensorDigitalIn)
#pragma config(Sensor, I2C_1,  imeR,           sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  imeL,           sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  imeE,           sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           left2,         tmotorVex393TurboSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           left1,         tmotorVex393TurboSpeed_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port3,           right1,        tmotorVex393TurboSpeed_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port4,           lock,          tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port5,            ,             tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           elevator1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           elevator2,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_3)
#pragma config(Motor,  port8,           elevator3,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           elevator4,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          right2,        tmotorVex393TurboSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "driveAPI.h"
#include "auton.h"
#include "lcdAPI.h"
#include "diag.h"

bool hasBeenSelected = false;

////////////////////
// PRE-AUTONOMOUS //
////////////////////



task lcdManager;
void pre_auton()
{
	resetIme();
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;
	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...

	/* Press and hold any LCD button BEFORE turning on robot
	* to enter autonomus selection mode.
	* If LCD buttons are not pressed (or LCD is not plugged in)
	* the default autonomous will run.
	*/
	startTask(lcdManager);
}

task lcdManager()
{

	short leftButton = 1;
	short centerButton = 2;
	short rightButton = 4;

	bLCDBacklight = true;

	while(1) {
		bool inMenu = ((!SensorValue[override]) ? hasBeenSelected : true);
		hasBeenSelected = true;
		while(inMenu)
		{
			lcdMngrStatus = 0;
			lcdShowStatus();
			int code = lcdWaitForBtnClick();
			if (code==leftButton)
			{
				Program = AUTON_L;
			}
			if (code==rightButton)
			{
				Program = AUTON_R;
			}
			if (code==centerButton)
			{
				diag();
				lcdClear();
				continue;
			}

			while(1)
			{
				lcdMngrStatus = Program + 1;
				lcdShowStatus();
				code = lcdWaitForBtnClick();
				if(code==centerButton)
				{
					inMenu=false;
					break;
				}
				else if (code==leftButton)
					diag();
				else
					break;
			}
		}
		lcdMngrStatus = 8;
		lcdShowStatus();
		lcdWaitForBtnClick();
	}
}

////////////////
// AUTONOMOUS //
////////////////

task autonomous()
{
	//lcdShowStatus();
	resetIme();
	autonR();
	return;
	// .....................................................................................
	// Insert user code here.
	// .....................................................................................
	switch(Program)
	{
	case AUTON_L:
		autonL();
		break;
	case AUTON_R:
		autonR();
		break;
	}

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

//////////////////
// USER CONTROL //
//////////////////

task usercontrol()
{
	lcdShowStatus();
	resetIme();
	// User control code here, inside the loop
	while(1)
	{
		setL(vexRT[Ch2]);
		setR(vexRT[Ch3]);
		if(vexRT[Btn7U]){
			setE(ELEVATOR_SPEED);
		}
		else if(vexRT[Btn7D]) {
			setE(-ELEVATOR_SPEED);
		} else {
			setE(ELEVATOR_REST);
		}
		if(vexRT[Btn8U]){
			motor[lock] = 128;
		} else if(vexRT[Btn8D]) {
			motor[lock] = -128;
		}
	}

}

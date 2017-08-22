#pragma config(Motor,  port2,           frontLeft,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           frontRight,    tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port4,           backRight,     tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port7,           leftArm,       tmotorVex393_MC29, openLoop, driveLeft)t
#pragma config(Motor,  port8,           rightArm,      tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port10,          claw,          tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Central Functions Section
void controllerBasic();
void turnAround();
void liftBasic();

//Drive Controller Section
void allOff();
void motorForward();
void motorBackward();
void motorLeftOn();
void motorRightOn();

//Lift Controller Section
void extendArm();
void retractArm();
void openClaw();
void closeClaw();
void moveArm(int power);
void autoGrab();

task main{
	while(true){
		controllerBasic();
		turnAround();
		
		liftBasic();
	}
}

//==================================================================================================
//                           C E N T R A L   F U N C T I O N S   S E C T I O N
//--------------------------------------------------------------------------------------------------
//			MAIN FUNCTIONS:
//				1. CONTROLLER BASIC
//				2. TURN AROUND
//				3. LIFT BASIC
//
//			CONTROLLER INDEX:
//				1. DRIVE CONTROLLER SECTION
//				2. LIFT CONTROLLER SECTION
//==================================================================================================

void controllerBasic(){
	motor[frontLeft] = vexRT(Ch3);
	motor[backLeft] = vexRT(Ch3);

	motor[frontRight] = vexRT(Ch2);
	motor[backRight] = vexRT(Ch2);
	
	while(vexRT[Btn7U] == 1){
		motorForward();
		motorBackward();
		motorLeftOn();
		motorRightOn();
		autoGrab();
	}
}

void turnAround(){
	if(vexRT[Btn8D] == 1){
		motor[frontLeft] = 127;
		motor[backLeft] = 127;

		motor[frontRight] = -127;
		motor[backRight] = -127;

		wait1Msec(2125);

		allOff();
	}
}

void liftBasic(){
	while(vexRT[Ch3Xmtr2] > 0){
		moveArm(vexRT[Ch3Xmtr2]);
	}
	while(vexRT[Btn8UXmtr2] == 1){
		openClaw();
	}
	while(vexRT[Btn8DXmtr2] == 1){
		closeClaw();
	}
}

//==================================================================================================
//                             D R I V E   C O N T R O L L E R   S E C T I O N
//==================================================================================================

void allOff(){
	motor[backLeft] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
}

void motorForward(){
	motor[backLeft] = 127;
	motor[backRight] = 127;
	motor[frontLeft] = 127;
	motor[frontRight] = 127;
}

void motorBackward(){
	motor[backLeft] = -127;
	motor[backRight] = -127;
	motor[frontLeft] = -127;
	motor[frontRight] = -127;
}

void motorLeftOn(){
	motor[backLeft] = 127;
	motor[backRight] = 0;
	motor[frontLeft] = 127;
	motor[frontRight] = 0;
}

void motorRightOn(){
	motor[backLeft] = 0;
	motor[backRight] = 127;
	motor[frontLeft] = 0;
	motor[frontRight] = 127;
}

//==================================================================================================
//                              L I F T   C O N T R O L L E R   S E C T I O N
//==================================================================================================

void moveArm(int power){
	motor[leftArm] = power;
	motor[rightArm] = power;
}

void extendArm(){
	motor[leftArm] = 127;
	motor[rightArm] = 127;
}

void closeClaw(){
	motor[leftArm] = 127;
	motor[rightArm] = 127;
}

void retractArm(){
	motor[leftArm] = -127;
	motor[rightArm] = -127;
}

void openClaw(){
	motor[claw] = -127;
}

void autoGrab(){
	extendArm();
	wait1Msec(0000);
	
	closeClaw();
	wait1Msec(0000);
	
	retractArm();
	wait1Msec(0000);
	
	openClaw();
	wait1Msec(0000);
	
}

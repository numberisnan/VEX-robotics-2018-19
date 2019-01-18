#pragma config(Motor,  port2,           mot2,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           mot3,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           mot4,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           mot5,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           motspin,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           motup,         tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

void pre_auton()
{

	bStopTasksBetweenModes = true;

}

const int M = 127, // Max value
H = 63, Q = 32;

void setmotor(int fl, int fr, int bl, int br){
	motor[mot2] = fl;
	motor[mot3] = fr;
	motor[mot4] = bl;
	motor[mot5] = br;
}

// Hackers be hackers
void diffarmup(int coeff){
	motor[motup] = (vexRT[Btn6U] ? H : Q) * coeff;
}

void setarmspin(int coeff){
	motor[motspin] = (vexRT[Btn6U] ? M : Q) * coeff;
}

// This code is self documenting
#define forward setmotor(M, M, M, M)
#define backward setmotor(-M, -M, -M, -M)
#define left setmotor(-M, M, -M, M)
#define right setmotor(M, -M, M, -M)
#define nomotor setmotor(0, 0, 0, 0)

// If you think this code sucks then I wish that all future
// balanced binary search trees you implement will segmentation fault
// 1,337 times before you get them right
#define wms wait1Msec
#define qsec wms(250)
#define hsec wms(500)
#define qqsec wms(750)
#define sec wms(1000)

//Checks whether ill get a girlfriend or not
bool flipped = false, taskflipflags = false;

void leftflippable(){
	if(flipped) right;
	else left;
}

void rightflippable(){
	if(flipped) left;
	else right;
}

#define ifleft leftflippable()
#define ifright rightflippable()

// Triggered by button 5U
void _autonomous_noflag(){
	if(taskflipflags){
		// no u
	}
	else{
		forward;
		sec;
		ifright;
		wms(550);
		forward;
		wms(4000);
	}
}

void _autonomous_flag() {
	if(taskflipflags){
		// E
	} else {
		backward;
		wms(1500);
		setmotor(-M/2, -M/2, -M/2, -M/2); //Back up slowly
		sec;
		forward;
		sec;


	}
}

task autonomous()
{
	_autonomous_noflag();
}

// I love you
// You love me
// We are a great big family
// Please marry me right now im so lonely
// I love you and you love me
//
// No
task usercontrol()
{
	// User control code here, inside the loop

	while (true){

		// Drive Controls

		if(vexRT[Btn7U]){
			forward;
		}
		else if(vexRT[Btn7D]){
			backward;
		}
		else if(vexRT[Btn7L]){
			left;
		}
		else if(vexRT[Btn7R]){
			right;
		}
		else{
			nomotor;
		}

		// Arm Control

		if(vexRT[Btn8U]){
			diffarmup(1);
		}
		else if(vexRT[Btn8D]){
			diffarmup(-1);
		}
		else{
			diffarmup(0);
		}

		// Arm Spin Control

		if(vexRT[Btn8L]){
			setarmspin(-1);
		}
		else if(vexRT[Btn8R]){
			setarmspin(1);
		}
		else{
			setarmspin(0);
		}

		// Autonomous Test ( DO NOT USE IN COMPETITION )
		if(vexRT[Btn5U]){
			_autonomous_flag();
		}

		// Autonomous Test - Changes whether the autonomous run is flipped or not

		if(vexRT[Btn5D]){
			flipped = false;
		}
		else if(vexRT[Btn6D]){
			flipped = true;
		}
	}
}

#pragma config(Motor,  port1,           motor2p,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           motor3p,       tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

const int INF = (1 << 30) - 1 + (1 << 30), MV = 127;

task main(){
	motor[motor2p] = MV;
	motor[motor3p] = MV;
	wait1Msec(INF);
}
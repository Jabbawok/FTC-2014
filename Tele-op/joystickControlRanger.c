#pragma config(StandardModel, "RANGER")
//*!!Code automatically generated by 'ROBOTC' configuration wizard           	!!*//
#include "JoystickDriver.c" //Joystick is included in this program
int threshold = 15; //to avoid unnecessary movement
int j1y1, j1y2, j1x1, j1x2;  //controller 1 integers
int j2y1, j2y2, j2x1, j2x2;  //controller 2 integers
//int aPosition; //servo arm position
//int gPosistion; //gripper arm position
int mSpeed = 1; //motor speed
task main()
{
  int threshold = 15; //to avoid unnecessary movement(both controllers)
  while(true) //infinite loop
  {
	getJoystickSettings(joystick); //retrieves data from the joystick
	j2y1 = joystick.joy2_y1;
	j2y2 = joystick.joy2_y2;
	j2x1 = joystick.joy2_x1;
	j2x2 = joystick.joy2_x2;
	j1y1 = joystick.joy1_y1;
	j1x1 = joystick.joy1_x1;
	j1y2 = joystick.joy1_y2;
	j1x2 = joystick.joy1_x2;
	if(abs(joystick.joy1_y1) > threshold)
	{
  	motor[motorD] = joystick.joy1_y1 * -1; //y1 controller moves motorD
	}
	else
	{
  	motor[motorD] = 0;
	}
	if(abs(joystick.joy1_y2) > threshold)
	{
  	motor[motorE] = joystick.joy1_y2 * -1; //y2 controller moves motorE
	}
	else
	{
  	motor[motorE] = 0;
	}
	//Detection for buttons such as a, b, x, y
	int dis_cm = 15;
 
	/*if(joy1Btn(7) == 1){
	while(SensorValue[S4] > dis_cm)
	motor[motorD] = 50;
	motor[motorE] = 50;*/   //ultrasonic code. do we need it?
   }
 
	if(joy1Btn(4) == 1){
	wait1Msec(10);
     servo[servo2] = servo[servo2]-mSpeed;
   } else if(joy1Btn(2) == 1){
     wait1Msec(10);
    servo[servo2] = servo[servo2]+mSpeed;
   } if(joy1Btn(3) == 1){
	 wait1Msec(10);
     servo[servo1] = servo[servo1]-mSpeed;
   } else if(joy1Btn(1) == 1){
     wait1Msec(10);
    servo[servo1] = servo[servo1]+mSpeed;
   }
   getJoystickSettings(joystick); //retrieves data from the joystick



	/*if(abs(joystick.joy1_y1) > threshold)
	{
  	motor[motorD] = (joystick.joy1_y1 * -); //y1 controller moves motorD
	}
	else
	{
  	motor[motorD] = 0;
	}
	if(abs(joystick.joy1_y2) > threshold)
	{
	 motor[motorE] = joystick.joy1_y2; //y2 controller moves motorE
	}
	else
	{
  	motor[motorE] = 0;
	}*/
	
	
	//Reset ze motor
 
 }
}

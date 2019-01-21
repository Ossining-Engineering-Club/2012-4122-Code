/* 
 * Declare the Interface for the Ossining High School Robot
 *  
 */ 
#ifndef SUBSYS_H_               //Checks if subsys.h has already been included
#define SUBSYS_H_				//Set SUBSYS_H when subsys.h is included to prevent it from being included multiple times
#include "WPILib.h"				//Include the FRC Library

/* 
 * Mecanum Drive Train Class
 */
class BotDrive : public RobotDrive
{
	public:
		BotDrive(UINT32 frontLeftMotorChannel, UINT32 rearLeftMotorChannel,
				UINT32 frontRightMotorChannel, UINT32 rearRightMotorChannel);
		void MecanumDrive(float leftx, float lefty, float rightx, float righty); //Drive using mecaunm, dissables autobalance and aimassist modes
		void SetThrottle(float);	//Change the throtle setting
		void AutoBalance();			//Turn on autobalance mode
		void AimAssist();			//Turn on aimassist mode			
	private:
		float scalespeed;
		float xValue, yValue, rValue;
}; 
 /* 
 * Arm Class
 * Two Opions to raise and lower:
 * 1) When moving up, call again and again with up command
 * 2) When moving up, call one time with up, then call continue on other calls
 */
class Arm 
{
	public:
		Arm(UINT32 channel);			//Constructor to initialize/set initial status
		void ArmUp();				//Accept command to raise up arm
		void ArmDown();				//Accept command to lower arm
		void ArmContinueMove(); 	//Continue moving arm or leaving it static
	private:
		Jaguar armmotor;
		 //State of the arm - same as LabView		
		enum armstates {Off,UpStart,UpMoving,Up,DownStart,DownMoving,Down}; //Same as Labview
		armstates ArmState;
		int ArmCycle;					//Counter when the arm is moving
};
// Define Arm related Constants
const float ArmUpDelta = 0.005;		//Amount Arm Power decreases for each cycle
const float ArmMinPower = 0.09;		//Minimum Power applied to Arm when not moving
const int ArmCyclesUp = 100;
const int ArmCyclesDown = 125;
/*
 * Belt Class
 */
class Belt
{
	public:
		Belt(UINT32 channel);					//Constructor to initialize - default is off
		void ButtonDown();
		void ButtonUp();
	private:
		Jaguar beltmotor;
		enum beltstates {OffPressed, Off, OnPressed, On};
		beltstates BeltState;   //State of the Belt
};

/*
 * Shooter Class
 */
class Shooter
{
	public:
		Shooter(int botchannel, int topchannel);	//Constructor to initialize
		void ShootBall();							//Take a shot
		void ChangeRangeMode();						//Change the rangemode
		void SetTargetHeight();						//Change the basket height (LOW,MEDIUM or HIGH)
		void CamContinueMove(); 					//Continue moving Cam or leaving it static
	private:
		Jaguar bottommotor;
		Jaguar topmotor;
		int shootmode;
		//State of the launch cam - same as LabView
		enum launchstates {Off,ForwardStart,Forward,Backward};
		launchstates LaunchState;
		enum basketmodes {LowBasket,MediumBasket,HighBasket};
		basketmodes AutoBasketMode;
		enum shootmodes {Manual, AutoRange, Key};
		shootmodes ShootMode;
};
//Define Shooter Related Constants
const float LowKey = 0.4;
const float LowScale = 0.00153;
const float MediumKey = 0.44;
const float MediumScale = 0.00153;
const float HighKey = 0.47;
const float HighScale = 0.00153;

#endif					//End if for inclusion of subsys.h

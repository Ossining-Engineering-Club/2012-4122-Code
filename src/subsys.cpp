#include "subsys.h"
#include "WPILib.h"

void BotDrive::MecanumDrive(float leftx, float lefty, float rightx, float righty)
{
	/* Compute x, y and r values, inverting sign for left joystick */
	xValue = scalespeed * (- leftx + rightx ) / 2.0;
	yValue = scalespeed * (- lefty + righty ) / 2.0;
	rValue = scalespeed * (- lefty - righty ) / 2.0;
	BotDrive::MecanumDrive_Cartesian(xValue, yValue, rValue, 0.0); // drive with the joysticks
}

void BotDrive::SetThrottle(float throttle)
{
	/* Compute x, y and r values, inverting sign for left joystick */
	scalespeed = 1/2 * ( 1 - throttle );
	BotDrive::MecanumDrive_Cartesian(xValue, yValue, rValue, 0.0); // drive with the joysticks
}

void BotDrive::AutoBalance()
{
	
}

void BotDrive::AimAssist()
{
		
}
Arm::Arm(UINT32 channel):
	armmotor(channel)
	
{
	ArmState = Off;
}

void Arm::ArmUp()
{

}

void Arm::ArmDown()
{
	
}

void Arm::ArmContinueMove()
{
	
}
Shooter::Shooter(int botchannel, int topchannel):
	bottommotor(botchannel),
	topmotor(topchannel)
{
	LaunchState = Off;
}
void Shooter::ShootBall()
{

}

void Shooter::ChangeRangeMode()
{
	
}

void Shooter::SetTargetHeight()
{
	
}

Belt::Belt(UINT32 channel):
	beltmotor(channel)
{
	BeltState = Off;
}

void Belt::ButtonDown()
{
//If button is pressed 
	switch (BeltState)
	{
		case Off:
			BeltState = OnPressed;
			beltmotor.Set(1);		
			break;
		case On:	
			BeltState = OffPressed;
			beltmotor.Set(0);
			break;
		case OffPressed: case OnPressed:
			break;
	}
}
void Belt::ButtonUp()
{
    //If button is not pressed
	switch (BeltState)
	{
		case OffPressed:
			BeltState = Off;
			break;
		case OnPressed:
			BeltState = On;
			break;
		case On:	case Off:
			break;
	}
}



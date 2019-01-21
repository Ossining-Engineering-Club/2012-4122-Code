#include "subsys.h"
#include "WPILib.h"
/*
 *  Mecanum Class Drive Robot Program
 * 
 * History
 * 12/6/12 Robot Code does not load
 */

//RobotDemo class inherits design from SimpleRobot super Class
//RobotDemo class is derived from SimpleRobot base Class
class RobotDemo : public SimpleRobot 
{
private:
	Joystick leftStick;
	Joystick rightStick;
	BotDrive ourdrive;
	Arm arm;
	Belt conveyer;
	Shooter shooter;
	
public:
/*Base class initiators specifies the data to pass to the 
 * constructors of the Base Class
 */
	RobotDemo():             	// Initialization Code
		leftStick(1),
		rightStick(2),
		ourdrive(4, 1, 2, 3),
		arm(9),					// Initialize with PWM Channel = 9		
		conveyer(5),			// Initialize with PWM Channel = 5
		shooter(6,7)			// Initialize with Bottom Motor PWM 6 and Top Motor PWM 7
	{
		GetWatchdog().SetEnabled(false);
	}
	
	void Autonomous()
	{
		// Autonomous Mode Placeholder - Add real Autonomous Mode Code Here
		for (int i = 0; i < 4; i++)
		{
			ourdrive.Drive(0.5, 0.0); 	// drive 50% forward speed with 0% turn
			Wait(2.0); 						// wait 2 seconds
			ourdrive.Drive(0.0, 0.75); 	// drive 0% forward speed with 75% turn
			Wait(0.75); 					// turn for 3/4 second
		}
		ourdrive.Drive(0.0, 0.0); 		// drive 0% forward speed with 0% turn (stop)
	}
	
	void OperatorControl()
	{
// While loop is executed once every 100 msec		
		while (1) 							// loop forever
		{
/*			
 * Slow Activities run every 100 msec are put here
 */
			// Set Throttle value
			ourdrive.SetThrottle(leftStick.GetThrottle());
			// Handle Conveyer
			if (rightStick.GetRawButton(2)) 
				conveyer.ButtonDown();
			else conveyer.ButtonUp();
			//Update LCD
//			lcd->UpdateLCD();
/*			
 * For Loop is executed once every 10 msec
 */			
			for (int i = 0 ; i < 10; ++i)
			{
				Wait(0.01);
				//
				// Fast Response activities run every 10 msec are put here
				// Drive Bot using Mecanum Drive
				ourdrive.MecanumDrive(leftStick.GetX(),leftStick.GetY(),rightStick.GetX(),rightStick.GetY());	

				// Continue to Move Arm
				
				
				// Continue Launch Cycle
								 	
				
			}
		}
	}
};
START_ROBOT_CLASS(RobotDemo);

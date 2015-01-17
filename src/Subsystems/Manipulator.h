//Header File for Drive Base
//This is where we Declare Everything
#ifndef MANIPULATOR_H_
#define MANIPULATOR_H_

#include "WPILib.h"
#include "../PhoenixLib/PhoenixLib.h"
#include "../Config/Constants.h"
#include "Subsystems/Pid.h"


class Manipulator
{


public:

	Manipulator(Victor* manipulatorMotorA, Victor* manipulatorMotorB, Encoder* manipEncoder); //This function is called the constructor


private:

	Constants* Constants_;

	//Motors
	Victor* ManipulatorMotorA_;
	Victor* ManipulatorMotorB_;

	//Sensors
	Encoder* ManipEncoder_;

	//PID
	Pid* ManipPid_;

	double heightMaxLimit;
	double heightMinLimit;

	double currentHeight;

	double toteHeight;
	double binHeight;

	double lowestHeight;
	double highestHeight; //TODO: Haven't implemented this because not sure if necessary.

public:

	void ResetEncoder();
	//Resets the Encoder reading.  Use for auto-sequencing.

	void UpdateHeight();

	void SetMotor(double speed);
	// Sets speed of Conveyor.  Same or different direction?  What is gearbox like?

	void SetLinearHeight(double goalHeight);
	// Function called to sequence conveyor up/down.

	bool askForHeight(double goalHeight);
	// Returns whether or not safe to move.  Can simply be an internal command.

	void SequenceTote(int numberTotes);

	void SequenceBin(int numberBins);

	void DropStack();//TODO: Don't think this function is correct, since we need to be able to track all pieces in robot's possession.	double setHeight = currentHeight + (numberTotes * toteHeight);

};

#endif

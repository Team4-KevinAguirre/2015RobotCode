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

	double heightLimit;

	double currentHeight;

	double toteHeight;
	double binHeight;

	double lowestHeight;
	double highestHeight;

public:

	void ResetEncoder();
	//Resets the Encoder reading.  Use for auto-sequencing.

	void UpdateHeight();

	void SetMotor(double speed);
	// Sets speed of Conveyor.  Same or different direction?  What is gearbox like?

	void SetLinearHeight(double goalHeight);
	// Function called to sequence conveyor up/down.

	bool askForHeight(double heightWanted);
	// Returns whether or not safe to move.  Can simply be an internal command.

	void SequenceTote(int numberTotes);

	void SequenceBin(int numberBins);



};

#endif

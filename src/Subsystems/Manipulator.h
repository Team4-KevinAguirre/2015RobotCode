//Header File for Drive Base
//This is where we Declare Everything
#ifndef MANIPULATOR_H_
#define MANIPULATOR_H_

#include "WPILib.h"
#include "../PhoenixLib/PhoenixLib.h"
#include "../Config/Constants.h"


class Manipulator
{


public:

	Manipulator(Victor* manipulatorMotorA, Victor* manipulatorMotorB); //This function is called the constructor


private:

	Constants* Constants_;

	//Motors
	Victor* ManipulatorMotorA_;
	Victor* ManipulatorMotorB_;


};

#endif

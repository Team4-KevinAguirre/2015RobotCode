#include <Subsystems/Manipulator.h>

Manipulator::Manipulator(Victor* manipulatorMotorA, Victor* manipulatorMotorB){

	Constants_ = Constants::GetInstance();

	//Motors
	ManipulatorMotorA_ = manipulatorMotorA;
	ManipulatorMotorB_ = manipulatorMotorB;
}


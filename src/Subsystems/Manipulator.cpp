#include <Subsystems/Manipulator.h>

Manipulator::Manipulator(Victor* manipulatorMotorA, Victor* manipulatorMotorB, Encoder* manipEncoder){

	Constants_ = Constants::GetInstance();

	//Motors
	ManipulatorMotorA_ = manipulatorMotorA;
	ManipulatorMotorB_ = manipulatorMotorB;

	//Sensors
	ManipEncoder_ = manipEncoder;

	//PID
	ManipPid_ = new Pid(&Constants_->PID_MANIP_KD,&Constants_->PID_MANIP_KI, &Constants_->PID_MANIP_KD);

	heightMaxLimit = 60.0;
	heightMinLimit = 0.0

	toteHeight = 13.1;
	binHeight = 24;

	currentHeight = 0.0;

	lowestHeight = 0;
	highestHeight = 0;
}

void Manipulator::ResetEncoder(){
	ManipEncoder_->Reset();
}

void Manipulator::UpdateHeight(){
	double scaleFactor = 1;
	currentHeight = ManipEncoder_->Get()*scaleFactor;
}

bool Manipulator::askForHeight(double goalHeight){
	if(goalHeight>heightMaxLimit || goalHeight <heightMinLimit )
		return false;
	else
		return true;
	return false;
}


void Manipulator::SetMotor(double speed){

	ManipulatorMotorA_->Set(PwmLimit(speed));
	ManipulatorMotorB_->Set(PwmLimit(speed));

}

void Manipulator::SetLinearHeight(double goalHeight){
	if(askForHeight(goalHeight)){

	double power = ManipPid_->Update(goalHeight, currentHeight);
	SetMotor(power);
	UpdateHeight();
	} else
	{
		//How to print to dashboard??  Maybe make a rumble?
	}
}

void Manipulator::SequenceTote(int numberTotes){
	double setHeight = currentHeight + (numberTotes * toteHeight);
	SetLinearHeight(setHeight);
	lowestHeight = setHeight;
}

void Manipulator::SequenceBin(int numberBins){
	double setHeight = currentHeight + (numberBins * binHeight);
	SetLinearHeight(setHeight);
	lowestHeight = setHeight;
}

void Manipulator::DropStack(){
	SetLinearHeight(0.0);
}

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
	heightLimit = 60.0;

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
	SetLinearHeight(currentHeight + (numberTotes * toteHeight));
}

void Manipulator::SequenceBin(int numberBins){
	SetLinearHeight(currentHeight + (numberBins * binHeight));
}

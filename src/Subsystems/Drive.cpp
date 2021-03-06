//Declaration File for Drive Base
//This is where we define everything.
#include "Drive.h"

Drive::Drive(VictorSP* leftDriveMotorA, VictorSP* leftDriveMotorB, VictorSP* rightDriveMotorA, VictorSP* rightDriveMotorB, RelativeGyro* driveGyro, Encoder* leftDriveEncoder, Encoder* rightDriveEncoder){

	Constants_ = Constants::GetInstance();

	//Motors
	LeftDriveMotorA_ = leftDriveMotorA;
	LeftDriveMotorB_ = leftDriveMotorB;

	RightDriveMotorA_ = rightDriveMotorA;
	RightDriveMotorB_ = rightDriveMotorB;

	//Sensors
	DriveGyro_ = driveGyro;
	LeftDriveEncoder_ = leftDriveEncoder;
	RightDriveEncoder_ = rightDriveEncoder;


	TurnPid_ = new Pid(&Constants_->PID_DRIVE_TURN_KD,&Constants_->PID_DRIVE_TURN_KI, &Constants_->PID_DRIVE_TURN_KD);

}

void Drive::SetLinearPower(double leftPower, double rightPower){
	LeftDriveMotorA_->Set(PwmLimit(-leftPower));
	LeftDriveMotorB_->Set(PwmLimit(-leftPower));
	RightDriveMotorA_->Set(PwmLimit(rightPower));
	RightDriveMotorB_->Set(PwmLimit(rightPower));

}

void Drive::resetGyro(){
	DriveGyro_->Reset();
}

void Drive::resetAbsoluteGyro(){
	DriveGyro_->ResetAbsolute();
}

void Drive::rotateDrive(float turnIncrement){
	//TODO: Remove newLeft/newRight because memory waste.  Put in here for ease of reading.
	float sens = .01;
	float newLeft = ((LeftDriveMotorA_->Get())+turnIncrement*sens);
	float newRight = ((RightDriveMotorA_->Get())+turnIncrement*sens);
	SetLinearPower(newLeft,newRight);
}

void Drive::rotateAbsoluteDrive(float rotationAngle){
	float currAngle = DriveGyro_->GetAngle();
	float setpointAngle = rotationAngle;

	double power = TurnPid_->Update(setpointAngle, currAngle);
	SetLinearPower(-power, power);
}

void Drive::DriveSpeedTurn(float speed, float turn, bool quickTurn){
	float temp_vel = speed;
		float sensitivity = 0;
		//float unscaled_turn = 0;
		if (temp_vel < 0)
			temp_vel = -temp_vel;

		//printf("Velocity: %f, stick: %f\r\n", velocity, temp_vel);

		if(speed < 0.10 && speed > -0.10)
			speed = 0;
		if ((turn < 0.10 && turn > -0.10) || (speed == 0 && !quickTurn))
			turn = 0;

		//unscaled_turn = turn;

		if(quickTurn) {
			sensitivity = 1;
			speed = 0;
		}
		else
			sensitivity = 0.4;

		turn *= sensitivity;
		turn = -turn;

		float left_power = speed - turn;
		float right_power = speed + turn;

		SetLinearPower(left_power, right_power);
}

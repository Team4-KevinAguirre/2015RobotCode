#include <PhoenixControlBoard.h>

/// Constructor for Phoenix Control Board
PhoenixControlBoard::PhoenixControlBoard(Joystick* DriveJoystick, Joystick* OperatorJoystick)

{
	Constants_ = Constants::GetInstance();
	DriveJoystick_ = DriveJoystick;
	OperatorJoystick_ = OperatorJoystick;

}


float PhoenixControlBoard::GetDriveAxis(int axis){
	return (DriveJoystick_->GetRawAxis(axis));
}

bool PhoenixControlBoard::GetDriveButton(int button){

	return (DriveJoystick_->GetRawButton(button));
}

float PhoenixControlBoard::GetDrivePOV(){
	return ((DriveJoystick_->GetPOV())*45);
}

float PhoenixControlBoard::GetOperatorAxis(int axis){
	return (OperatorJoystick_->GetRawAxis(axis));
}

bool PhoenixControlBoard::GetOperatorButton(int button){
	return (OperatorJoystick_->GetRawButton(button));
}

float PhoenixControlBoard::GetOperatorPOV(){
	return ((OperatorJoystick_->GetPOV())*45);
	}
}

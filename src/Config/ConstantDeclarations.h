/**
 * @author Eric Caldwell
 *
 * This file is read by Constants and contains the variables and default values that will be stored as member
 * variables in Constants. Use it by including it in the macro definition of the functions used below.
 */

// Joystick Ports

DECLARE_DOUBLE(JOY_PORT_DRIVE,0)
DECLARE_DOUBLE(JOY_PORT_OPERATOR,1)

//X-box Joystick Map
//http://az623152.vo.msecnd.net/library/images/support/kbgraphics/public/en-us/909385.jpg
//http://www.chiefdelphi.com/forums/showthread.php?t=120879&highlight=xbox+map
DECLARE_DOUBLE(JOY_AXIS_LJ_Y, 1)
DECLARE_DOUBLE(JOY_AXIS_LJ_X, 0)
DECLARE_DOUBLE(JOY_AXIS_L_TRIGGER, 2)
DECLARE_DOUBLE(JOY_AXIS_R_TRIGGER, 3)
DECLARE_DOUBLE(JOY_AXIS_RJ_X, 4)
DECLARE_DOUBLE(JOY_AXIS_RJ_Y,5)

//DECLARE_DOUBLE(JOY_AXIS_DPAD,6)

DECLARE_DOUBLE(JOY_BUTTON_A,1)
DECLARE_DOUBLE(JOY_BUTTON_B,2)
DECLARE_DOUBLE(JOY_BUTTON_X,3)
DECLARE_DOUBLE(JOY_BUTTON_Y,4)
DECLARE_DOUBLE(JOY_BUTTON_LB,5)
DECLARE_DOUBLE(JOY_BUTTON_RB,6)
DECLARE_DOUBLE(JOY_BUTTON_BACK,7)
DECLARE_DOUBLE(JOY_BUTTON_START,8)
DECLARE_DOUBLE(JOY_BUTTON_LJPRESS,9)
DECLARE_DOUBLE(JOY_BUTTON_RJPRESS,10)

// Motors

DECLARE_DOUBLE(PWM_LEFT_DRIVE_A, 0)
DECLARE_DOUBLE(PWM_LEFT_DRIVE_B, 1)
DECLARE_DOUBLE(PWM_RIGHT_DRIVE_A, 2)
DECLARE_DOUBLE(PWM_RIGHT_DRIVE_B, 3)


// Digital Sensors
DECLARE_DOUBLE(ENCODER_LEFT_DRIVE_A, 1);
DECLARE_DOUBLE(ENCODER_LEFT_DRIVE_B, 2);
DECLARE_DOUBLE(ENCODER_RIGHT_DRIVE_A, 3);
DECLARE_DOUBLE(ENCODER_RIGHT_DRIVE_B, 4);

//Sensors
DECLARE_DOUBLE(GYRO_DRIVE, 0);
DECLARE_DOUBLE(ENCODER_DRIVE_LEFT,1);
DECLARE_DOUBLE(ENCODER_DRIVE_RIGHT,2);


//PID Declarations
DECLARE_DOUBLE(PID_DRIVE_TURN_KP,0.1)
DECLARE_DOUBLE(PID_DRIVE_TURN_KI,0.0)
DECLARE_DOUBLE(PID_DRIVE_TURN_KD,0.0)

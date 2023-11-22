using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Cata;
extern rotation RotationSensor;
extern motor Intake;
extern motor LeftA;
extern motor LeftB;
extern motor RightA;
extern motor RightB;
extern inertial Inertial;
extern motor LeftC;
extern motor RightC;
extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;
extern digital_out BlockerPiston;
extern digital_out WingPistons;
extern limit LimitSwitchClose;
extern limit LimitSwitchFar;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
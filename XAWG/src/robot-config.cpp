#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Cata = motor(PORT2, ratio18_1, false);
rotation RotationSensor = rotation(PORT10, false);
motor Intake = motor(PORT20, ratio18_1, false);
motor LeftA = motor(PORT19, ratio18_1, true);
motor LeftB = motor(PORT8, ratio18_1, true);
motor LeftC = motor(PORT4, ratio18_1, true);
motor_group LeftDriveSmart = motor_group(LeftA, LeftB, LeftC);
motor RightA = motor(PORT11, ratio18_1, false);
motor RightB = motor(PORT7, ratio18_1, false);
motor RightC = motor(PORT9, ratio18_1, false);
motor_group RightDriveSmart = motor_group(RightA, RightB, RightC);
inertial Inertial = inertial(PORT19);
controller Controller1 = controller(primary);
digital_out WingPistons = digital_out(Brain.ThreeWirePort.B);
digital_out BlockerPiston = digital_out(Brain.ThreeWirePort.C);
limit LimitSwitchClose = limit(Brain.ThreeWirePort.G);
limit LimitSwitchFar = limit(Brain.ThreeWirePort.F);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {

    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}
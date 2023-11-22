#include "main.h"

/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 118; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 96;
const int SWING_SPEED = 97;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {

  pros::Motor CataIntakeMotorL(17, pros::E_MOTOR_GEARSET_06, true);
pros::Motor CataIntakeMotorR(16, pros::E_MOTOR_GEARSET_06, false);
pros::MotorGroup CataIntakeMotors({CataIntakeMotorL, CataIntakeMotorR});
pros::ADIDigitalOut Wings ('B');
pros::ADIDigitalOut Blocka ('C');
pros::Rotation CataRotation(21);
pros::ADIDigitalOut SideClimb ('D');
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}


void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}



void prog_skills() {}

void far() {

CataIntakeMotors.move(100);
chassis.set_drive_pid(3, DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_drive_pid(-34, DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_turn_pid(150, TURN_SPEED);
chassis.wait_drive();
chassis.set_drive_pid(15 , DRIVE_SPEED, true);
chassis.wait_drive();
Wings.set_value(true);
chassis.set_swing_pid(ez::RIGHT_SWING, 90, SWING_SPEED);
chassis.wait_drive();
Wings.set_value(false);
chassis.set_turn_pid(110, TURN_SPEED);
chassis.wait_drive();
chassis.set_drive_pid(15 , DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_turn_pid(90, TURN_SPEED);
chassis.wait_drive();
chassis.set_drive_pid(10 , DRIVE_SPEED, true);
chassis.wait_drive();
// CataIntakeMotors.move(-127);
// pros::delay(250);
// chassis.set_turn_pid(-13, TURN_SPEED);
// chassis.wait_drive();
// CataIntakeMotors.move(100);

}

void far2() {

Wings.set_value(true);
pros::delay(250);
Wings.set_value(false);
//Alliance Tri-ball kicked for placement
chassis.set_drive_pid(21, DRIVE_SPEED, true);
chassis.wait_drive();
CataIntakeMotors.move(115);
chassis.set_swing_pid(ez::RIGHT_SWING, -90, SWING_SPEED);
chassis.wait_drive();
chassis.set_drive_pid(20, DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_drive_pid(-10, DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_turn_pid(30, TURN_SPEED);
chassis.wait_drive();
CataIntakeMotors.move(-100);
pros::delay(375);
CataIntakeMotors.move(110);
//First Tri-ball placed in front of goal
chassis.set_turn_pid(-37, TURN_SPEED);
chassis.wait_drive();
chassis.set_drive_pid(23, DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_turn_pid(90, TURN_SPEED);
chassis.wait_drive();
Wings.set_value(true);
chassis.set_drive_pid(36, DRIVE_SPEED, true);
chassis.wait_drive();
//Three Tri-balls scored in front of goal
chassis.set_drive_pid(-9, DRIVE_SPEED, true);
chassis.wait_drive();
Wings.set_value(false);
CataIntakeMotors.move(0);
chassis.set_turn_pid(0, TURN_SPEED);
chassis.wait_drive();
chassis.set_drive_pid(-56, DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_turn_pid(-90, TURN_SPEED);
chassis.wait_drive();
CataIntakeMotors.move(110);
chassis.set_drive_pid(27, DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_drive_pid(-31, DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_turn_pid(65, TURN_SPEED);
chassis.wait_drive();
chassis.set_drive_pid(20, DRIVE_SPEED, true);
chassis.wait_drive();
Wings.set_value(true);
chassis.set_turn_pid(20, TURN_SPEED);
chassis.wait_drive();
Wings.set_value(false);
chassis.set_drive_pid(23, DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_drive_pid(-11, DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_drive_pid(22, DRIVE_SPEED, true);
chassis.wait_drive();
chassis.set_drive_pid(-10, DRIVE_SPEED, true);
chassis.wait_drive();
CataIntakeMotors.move(0);



}

void close(){
  
}


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Cata                 motor         2               
// Intake               motor         20               
// Inertial             inertial      19              
// RotationSensor       rotation      10              
// WingPistons          digital_out   B              
// LeftA                motor         11              
// LeftB                motor         13              
// LeftC                motor         16              
// RightA               motor         12              
// RightB               motor         14              
// RightC               motor         15              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cmath>



using namespace vex;

// A global instance of competition
competition Competition;


// Define PID constants for driving straight
double kP_drive = 2.5;
double kI_drive = 0.01;
double kD_drive = 0.25;

// Define PID constants for turning
double kP_turn = 0.58;
double kP_Cata = 0.5;



// Custom function to drive forward a specified distance in inches
void DriveFor(double wanteddistance) {

LeftA.resetPosition();
RightA.resetPosition();
double kp = 5.5;
double prevError = 0;


    while (true) {

    double Lefttraveled = (LeftA.position(degrees)*36/60 /( 3.25*3.141592653));
    double Righttraveled = (RightA.position(degrees)*36/60 /( 3.25*3.141592653));
    double currentposition = (Lefttraveled + Righttraveled)/2;
    double error = wanteddistance - currentposition;
    std::cout<<Lefttraveled << " " << Righttraveled << std::endl;

  // Calculate PID output for driving
    double Pvalue = error * kp;

        // Apply PID output to the motors for turning
          LeftDriveSmart.spin(forward, Pvalue, percent);
          RightDriveSmart.spin(forward, Pvalue, percent);
          wait(10, msec);

// Exit the loop when driving is complete
        if (fabs(error) < 0.5) { // Adjust the threshold as needed
            LeftDriveSmart.stop();
            RightDriveSmart.stop();
            break;
        }

        prevError = error;

        vex::task::sleep(20); // Add a small delay
    }
}



// Custom function to turn to a specified heading using the gyro
void TurnToHeading(double targetAngle) {
Inertial.resetHeading();
  
    double  derivative_turn = 0, lastTurnError = 0;

    while (true) {
        // Read the current angle from the gyro
        double currentAngle = Inertial.rotation(degrees);
        double turnError = targetAngle - currentAngle;
        if(turnError>180){
          turnError-=360;
        }

        // Calculate integral and derivative terms for turning
        derivative_turn = turnError - lastTurnError;

        // Calculate PID output for turning
        double turnPidOutput = kP_turn * turnError;

        // Apply PID output to the motors for turning
        LeftDriveSmart.spin(forward, turnPidOutput, pct);
        RightDriveSmart.spin(reverse, turnPidOutput, pct);

        // Exit the loop when turning is complete
        if (fabs(turnError) < 2.0) { // Adjust the threshold as needed
            LeftDriveSmart.stop();
            RightDriveSmart.stop();
            break;
        }

        lastTurnError = turnError;

        vex::task::sleep(20); // Add a small delay
    }
}



int auto_program = 1;

void LimitSwitchClose_pressed() {
    auto_program = 2;
}

void LimitSwitchFar_pressed() {
    auto_program = 3;
}


void pre_auton(void) {


Brain.Screen.clearScreen();
Brain.Screen.drawImageFromFile("Brain Screen Decal.png", 0, 0);

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}

void autonomous(void) {


 if (auto_program == 1) {

//Runs Prog Skills if No switches are pressed
Cata.setVelocity(65, percent);
Cata.spinFor(reverse, 92*360, degrees);
Cata.stop();
TurnToHeading(-24);
DriveFor(-92);
TurnToHeading(-113);
DriveFor(24);
TurnToHeading(-60);
DriveFor(32);
TurnToHeading(-113);
DriveFor(12);
TurnToHeading(-24);
WingPistons.set(true);
DriveFor(-36);
DriveFor(20);
WingPistons.set(false);
TurnToHeading(107);
DriveFor(-20);
TurnToHeading(62);
DriveFor(-4);
TurnToHeading(-27);
WingPistons.set(true);
DriveFor(-36);
DriveFor(9);
WingPistons.set(false);

    }

    

 else if (auto_program == 2) {

//Runs Close Side
Cata.setVelocity(100, pct);
Cata.spinFor(reverse, 800, degrees, false);
Intake.spin(forward, 100, pct);
wait(0.45, sec);
DriveFor(8.5);
WingPistons.set(true);
TurnToHeading(-40);
wait(0.1, sec);
TurnToHeading(0);
WingPistons.set(false);
TurnToHeading(82);
DriveFor(32);
TurnToHeading(45);
DriveFor(21);
TurnToHeading(-43);
Intake.spin(reverse, 100, percent);
wait(0.25, seconds);
DriveFor(10);
wait(0.2, seconds);
DriveFor(-12);
TurnToHeading(47);
DriveFor(-55);
TurnToHeading(137);
DriveFor(28);
wait(0.5, seconds);
Intake.stop();

}



else if (auto_program == 3){

//Runs Far Side 
Cata.setVelocity(70, pct);
Cata.spinFor(reverse, 800, degrees, false);
Intake.spin(forward, 100, pct);
wait(0.45, sec);
DriveFor(-25.5);
TurnToHeading(-26);
WingPistons.set(true);
DriveFor(-22.5);
TurnToHeading(-80);
WingPistons.set(false);
TurnToHeading(-50);
DriveFor(-16);
TurnToHeading(-90);
DriveFor(-10.3);
// Preload Scored and Red Matchload Scored
DriveFor(7.4);
TurnToHeading(0);
wait(0.1, seconds);
TurnToHeading(95);
DriveFor(14);
// Triball Scored
DriveFor(-15);
TurnToHeading(18);
DriveFor(57);
TurnToHeading(82);
DriveFor(24);
TurnToHeading(180);
Intake.stop();
DriveFor(36);
DriveFor(-12);
}

}



void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
\

      while(Competition.isDriverControl()){
   LeftA.spin(fwd, Controller1.Axis3.value() + (Controller1.Axis1.value()*.45),  pct);
   LeftB.spin(fwd, Controller1.Axis3.value() + (Controller1.Axis1.value()*.45),  pct);
   LeftC.spin(fwd, Controller1.Axis3.value() + (Controller1.Axis1.value()*.45),  pct);

   RightA.spin(fwd, Controller1.Axis3.value() - (Controller1.Axis1.value()*.45),  pct);
   RightB.spin(fwd, Controller1.Axis3.value() - (Controller1.Axis1.value()*.45),  pct);
   RightC.spin(fwd, Controller1.Axis3.value() - (Controller1.Axis1.value()*.45),  pct);
      

    if(RotationSensor.angle() > 315|| Controller1.ButtonR1.pressing() || (RotationSensor.angle() > 0 && RotationSensor.angle() < 5)){
      Cata.spin(reverse,70,percent);

    } 
    else{
    Cata.stop(hold);

    }



   if(Controller1.ButtonL1.pressing()){
   WingPistons.set(true);
   }
else {
WingPistons.set(false);
}

if(Controller1.ButtonUp.pressing()){
  BlockerPiston.set(true);
}
if(Controller1.ButtonDown.pressing()){
  BlockerPiston.set(false);
}


if(Controller1.ButtonX.pressing()){

Cata.setVelocity(70, percent);
Cata.spinFor(reverse, 92*360, degrees);
Cata.stop();
TurnToHeading(-24);

}

if(Controller1.ButtonR2.pressing()){
  Intake.spin(forward, 100, percent);
  Intake.setBrake(coast);
}

if(Controller1.ButtonL2.pressing()){
  Intake.spin(reverse, 100, percent);
  Intake.setBrake(coast);
}

if(Controller1.ButtonA.pressing()){
  Intake.stop();
}

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }}}


//
// Main will set up the competition functions and callbacks.
//
int main() {

LimitSwitchClose.pressed(LimitSwitchClose_pressed);
LimitSwitchFar.pressed(LimitSwitchFar_pressed);

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

     while(1) {
        // Allow other tasks to run
        if( !Competition.isEnabled() ){


        this_thread::sleep_for(10);
        }

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}}

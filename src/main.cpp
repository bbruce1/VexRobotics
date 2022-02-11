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
// armright             motor         1               
// backleft             motor         2               
// frontright           motor         3               
// backright            motor         4               
// backlift             motor         7               
// armleft              motor         8               
// frontleft            motor         9               
// Controller1          controller                    
// dig1                 digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;
using signature = vision::signature;
using code = vision::code;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
    // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
/*      Whan that april with its showers sota the drought of march hath perces to to rota and bathed every veyne in swich liquour of which zephrus eek with his swete brethe           */
//Bakers a little hoe I love that about him oop
// AUTONOMOUS PHASE
// AUTONOMOUS PHASE
void roboMovement(int velocity, int degree, double wait /* seconds */ ) {
  frontleft.setVelocity(velocity, percent);
  backleft.setVelocity(velocity, percent);
  frontright.setVelocity(velocity, percent);
  backright.setVelocity(velocity, percent);
  frontleft.startRotateFor(vex::directionType::fwd, degree, vex::rotationUnits::deg);
  backleft.startRotateFor(vex::directionType::fwd, degree, vex::rotationUnits::deg);
  frontright.startRotateFor(vex::directionType::fwd, degree, vex::rotationUnits::deg);
  backright.rotateFor(vex::directionType::fwd, degree, vex::rotationUnits::deg);
  vex::task::sleep(wait * 1000);
}
// Check if can turn both ways or only 1 each function
void turnRobot(int velocity, int degree, double wait) {
  frontleft.setVelocity(velocity, percent);
  backleft.setVelocity(velocity, percent);
  frontright.setVelocity(velocity, percent);
  backright.setVelocity(velocity, percent);
  frontleft.startRotateFor(vex::directionType::rev, degree, vex::rotationUnits::deg);
  backleft.startRotateFor(vex::directionType::rev, degree, vex::rotationUnits::deg);
  frontright.startRotateFor(vex::directionType::fwd, degree, vex::rotationUnits::deg);
  backright.rotateFor(vex::directionType::fwd, degree, vex::rotationUnits::deg);
  vex::task::sleep(wait * 1000);
}

void armMove(int velocity, int dist, double wait) {
  armleft.setVelocity(velocity, percent);
  armright.setVelocity(velocity, percent);
  armleft.startRotateFor(vex::directionType::fwd, dist, vex::rotationUnits::deg);
  armright.rotateFor(vex::directionType::fwd, dist, vex::rotationUnits::deg);
}

void adjustBackLift(int velocity, int dist, double wait) {
  backlift.setVelocity(velocity, percent);
  backlift.rotateFor(vex::directionType::fwd, dist, vex::rotationUnits::deg);
}

void moveAndBackDown(int velocityBackLift, int velocityMove, int distMove, int distMoveBackLift, double wait) {
    // Back lift
    backlift.setVelocity(velocityBackLift, percent);
    backlift.startRotateFor(vex::directionType::fwd, distMoveBackLift, vex::rotationUnits::deg);

    // Movement
    frontleft.setVelocity(velocityMove, percent);
    backleft.setVelocity(velocityMove, percent);
    frontright.setVelocity(velocityMove, percent);
    backright.setVelocity(velocityMove, percent);
    frontleft.startRotateFor(vex::directionType::fwd, distMove, vex::rotationUnits::deg);
    backleft.startRotateFor(vex::directionType::fwd, distMove, vex::rotationUnits::deg);
    frontright.startRotateFor(vex::directionType::fwd, distMove, vex::rotationUnits::deg);
    backright.rotateFor(vex::directionType::fwd, distMove, vex::rotationUnits::deg);
    vex::task::sleep(wait * 1500);
}

void putUpAndMoveBack(int velocityBackLift, int velocityMove, int distMove, int distMoveBackLift, double wait) {
    // Back lift
    backlift.setVelocity(velocityBackLift, percent);
    backlift.startRotateFor(vex::directionType::fwd, distMoveBackLift, vex::rotationUnits::deg);
    vex::task::sleep(1000);


    // Movement
    frontleft.setVelocity(velocityMove, percent);
    backleft.setVelocity(velocityMove, percent);
    frontright.setVelocity(velocityMove, percent);
    backright.setVelocity(velocityMove, percent);
    frontleft.startRotateFor(vex::directionType::fwd, distMove, vex::rotationUnits::deg);
    backleft.startRotateFor(vex::directionType::fwd, distMove, vex::rotationUnits::deg);
    frontright.startRotateFor(vex::directionType::fwd, distMove, vex::rotationUnits::deg);
    backright.rotateFor(vex::directionType::fwd, distMove, vex::rotationUnits::deg);
    vex::task::sleep(wait * 1000);
} 

void pneumaticAutonDown() {
  dig1.set(false);
  vex::task::sleep(1000);
}

void pneumaticAutonUp() {
  dig1.set(true);
  vex::task::sleep(1000);
}

double automFoot = 325.55;

void autonomous(void) {
  // Practice 750deg fwd, 90degleftturn, 500deg rev
  pneumaticAutonUp();
  roboMovement(100, automFoot * 4.5, 0.0);
  roboMovement(30, automFoot * 1.5, 0.2);
  pneumaticAutonDown();
  roboMovement(100, automFoot * 4.5 * -1, 0.2);
}

// USER CONTROL PHASE 
// USER CONTROL PHASE
// USER CONTROL PHASE

// Tank Drive Code
//void tankDrive() {
  //  frontleft.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
    //backleft.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
    //frontright.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
//    backright.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
//}

// Arcade Arcade Drive Code

void backLiftingLol(int setarmspeed) {
  if (Controller1.ButtonL1.pressing()) {
    backlift.spin(vex::directionType::fwd, setarmspeed, vex::velocityUnits::pct);
  } else if (Controller1.ButtonL2.pressing()) {
    backlift.spin(vex::directionType::rev, setarmspeed, vex::velocityUnits::pct);
  } else if (!Controller1.ButtonL1.pressing() && !Controller1.ButtonL2.pressing()) {
    backlift.stop(vex::brakeType::hold);
  } else {
    Brain.Screen.print("What the Thaddues is going on");
  }
}


void usercontrol(void) {
  // Variable Setting
  int armspeed = 60; 
  dig1.set(true);
  bool isFast = false;
  // Infinite Loop for doing robot stuff
  while (1) {
    // Pneumatics
    if (Controller1.ButtonA.pressing()) {    
        dig1.set(true);
        wait(100, msec);
    }
    if (Controller1.ButtonY.pressing()) {
      dig1.set(false);
      wait(100, msec);
    }
    float leftMotorDriveSpeed = Controller1.Axis3.position() + Controller1.Axis1.position() * 0.3;
    float rightMotorDriveSpeed = Controller1.Axis3.position() - Controller1.Axis1.position() * 0.3;
    // Movement
      frontleft.spin(vex::directionType::fwd, leftMotorDriveSpeed, vex::velocityUnits::pct);
      backleft.spin(vex::directionType::fwd, leftMotorDriveSpeed, vex::velocityUnits::pct);
      frontright.spin(vex::directionType::fwd, rightMotorDriveSpeed, vex::velocityUnits::pct);
      backright.spin(vex::directionType::fwd, rightMotorDriveSpeed, vex::velocityUnits::pct);
      // frontleft.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
      // backleft.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
      // frontright.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
      // backright.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
    // Backlift
    // Changing Armlift Speed
    if (Controller1.ButtonB.pressing()) {
      if (isFast == false) {
        armspeed = 100;
        isFast = true;
      } else {
        armspeed = 60;
        isFast = false;
      }
    }
    backLiftingLol(armspeed);
    // Armlift
    if (Controller1.ButtonR2.pressing()) {
      armleft.spin(vex::directionType::fwd, armspeed, vex::velocityUnits::pct);
      armright.spin(vex::directionType::fwd, armspeed, vex::velocityUnits::pct);
    } else if (Controller1.ButtonR1.pressing()) {
      armleft.spin(vex::directionType::rev, armspeed, vex::velocityUnits::pct);
      armright.spin(vex::directionType::rev, armspeed, vex::velocityUnits::pct);
    } else if (!Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing()) {
      armleft.stop(hold);
      armright.stop(hold);
    } else {
      Brain.Screen.print("What the Thaddues is going on");
      break;
    }
    wait(20, msec);  
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  if (Controller1.ButtonX.pressing()) {
    Competition.autonomous(autonomous);
  }
  // Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}






// Yoooooooooooooooooooo
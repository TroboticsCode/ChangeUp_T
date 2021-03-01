#include "Autons.h"
#include "DriveFunctionsConfig.h"
#include "Functions.h"
#include "vex.h"

// Put your auton routines in here

void Auton1() {
  //          kP   kI  kD slew minDT
  setLinGains(45, 0.004, 15, 40, 30);
  setLinGains(85, 0.04, 15, 40, 30);
  // setRotGains(0.008, 0.00000025, 0.065, 40, 30);
  setRotGains(0.015, 0.000000008, 0.07, 40, 30);
  // moveLinear(36, 100);
  moveRotate(-45, 100, 30);
  //moveLinear(6, 100, 30);
  moveStop();
}

void AutonSkills1() {
  // setLinGains(80, 0.001, 35, 30, 20);
  // setRotGains(35, 0.004, 20, 30, 20);

  intakeUp(3); // shoot ball #1

  moveLinear(-58, 100, 30); // inital back up
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.print("Move 1 Complete");
  wait(1, sec);

  moveRotate(-56, 100, 30); // rotate to align with tower
  Brain.Screen.setCursor(2, 1);
  Brain.Screen.print("Move 2 Complete");
  wait(1, sec);

  moveLinear(-16, 100, 30); // drive into tower
  Brain.Screen.setCursor(3, 1);
  Brain.Screen.print("Move 3 Complete");

  punch(); // Punch 1 forward
  Brain.Screen.setCursor(4, 1);
  Brain.Screen.print("Punch 1 Complete");
  wait(1, seconds);

  punchBack();
  wait(1, seconds);
  Brain.Screen.setCursor(5, 1); // punch 1 backward
  Brain.Screen.print("PunchBack 1 Complete");

  punch(); // Punch 2 forward
  Brain.Screen.setCursor(6, 1);
  Brain.Screen.print("Punch 2 Complete");
  wait(1, seconds);

  punchBack();
  wait(1, seconds); // punch 2 backward
  Brain.Screen.setCursor(7, 1);
  Brain.Screen.print("PunchBack 2 Complete");

  punch(); // Punch 3 forward
  Brain.Screen.setCursor(8, 1);
  Brain.Screen.print("Punch 3 Complete");
  wait(1, seconds);

  punchBack();
  wait(1, seconds);
  Brain.Screen.setCursor(9, 1); // punch 3 backward
  Brain.Screen.print("PunchBack 3 Complete");

  moveLinear(24, 100, 30);
  moveRotate(-80, 100, 30); // align to pick up ball #2

  /*double distanceValue = 0;
  bool Ball = 0;
  distanceValue =
      outsideDistance.takeSnapshot(outsideDistance__SIG_1); // pick up ball #2

  Drivetrain.driveFor(forward, distanceValue, inches);
  Ball = intakeDistance.isObjectDetected();
  if (Ball == 1) {
    pickUp(2);
  }
  Drivetrain.driveFor(reverse, 36, inches);
  Drivetrain.turnFor(right, 35, degrees);
  Drivetrain.driveFor(forward, 40, inches); // align to score ball #2
  Drivetrain.driveFor(reverse, 2, inches);

  intakeUp(3); // score ball #2

  Drivetrain.driveFor(reverse, 40, inches);
  Drivetrain.turnFor(left, 35, degrees);
  // distanceValue = outsideDistance.objectDistance(inches); // reset for ball
  // #3
  Drivetrain.driveFor(forward, distanceValue, inches);

  Drivetrain.driveFor(reverse, 37, inches);
  Drivetrain.turnFor(left, 90, degrees);
  // distanceValue = outsideDistance.objectDistance(inches); //pick up ball #3
  Drivetrain.driveFor(forward, distanceValue, inches);
  Ball = intakeDistance.isObjectDetected();
  if (Ball == 1) {
    pickUp(2);*/
}

void AutonSkills2() {
  setLinGains(45, 0.004, 15, 40, 30);
  setRotGains(0.015, 0.000000008, 0.07, 40, 30);
  cameraCenter(SIGRED);

  setLinGains(85, 0.04, 15, 40, 30);
  moveLinear(6, 100, 30);
  moveStop();
  rollerBottom.setVelocity(25, rpm); // pick up ball one
  rollerBottom.spinFor(forward, 3, seconds);

  setLinGains(45, 0.004, 15, 40, 30);
  moveRotate(140, 100, 30);
  moveStop();
  moveLinear(20, 100, 30); // align with tower 1
  moveStop();

  intakeUp(3); // shoot preload

  rollerBottom.setVelocity(25, percent);
  rollerBottom.spin(forward);
  moveLinear(-53, 100, 30); // hold ball and align with tower 2
  moveStop();
  rollerBottom.stop();

  moveRotate(75, 100, 30);
  moveStop(); // score ball 1
  intakeUp(3);

  moveRotate(90, 100, 30);
  moveStop();
  rollerBottom.setVelocity(25, percent); // move to tower 3 and grab ball 2
  rollerBottom.spin(forward);
  moveLinear(36, 100, 30);
  moveStop();
  rollerBottom.stop();

  moveRotate(-40, 100, 30);
  moveStop();
  moveLinear(6, 100, 30); // align and score ball 2
  moveStop();
  intakeUp(3);
}
#include "functions.h"
#include "DriveFunctionsConfig.h"
#include "vex.h"
#include "vision.h"
#include "vision2.h"

#define CENTER_X 316 / 2.0f
#define CENTER_Y 212 / 2.0f

void testPID() {
  for (int i = 0; i < 8; i++) {
    moveLinear(12, 100, 30);
    moveRotate(-90, 90, 30);
  }
  // moveStop();
  wait(20, msec); // Sleep the task for a short amount of time t
}

void punch() {
  Puncher.setVelocity(100, percent);
  Puncher.spinFor(reverse, 1.8, rev, true);
}
void punchBack() {
  Puncher.setVelocity(100, percent);
  Puncher.spinFor(forward, 1.8, rev, true);
}

void intakeUp(float time) {
  rollerBottom.setVelocity(100, pct);
  rollerTop.setVelocity(100, pct);
  rollerBottom.setStopping(brake);
  rollerTop.setStopping(brake);

  rollerBottom.spin(forward);
  rollerTop.spin(forward);
  wait(time, seconds);
  rollerBottom.stop();
  rollerTop.stop();
}

void intakeTop(float time) {
  rollerBottom.setVelocity(0, pct);
  rollerTop.setVelocity(100, pct);
  rollerBottom.setStopping(brake);
  rollerTop.setStopping(brake);

  rollerBottom.spin(forward);
  rollerTop.spin(forward);
  wait(time, seconds);
  rollerBottom.stop();
  rollerTop.stop();
}

void intakeDown(float time) {
  rollerBottom.setVelocity(100, pct);
  rollerTop.setVelocity(100, pct);
  rollerBottom.setStopping(brake);
  rollerTop.setStopping(brake);

  rollerBottom.spin(reverse);
  rollerTop.spin(reverse);
  wait(time, seconds);
  rollerBottom.stop();
  rollerTop.stop();
}
void pickUp(float time) {
  rollerBottom.setVelocity(100, pct);
  rollerBottom.setStopping(brake);

  rollerBottom.spin(forward);
  wait(time, seconds);
  rollerBottom.stop();
}
void Flipper() {
  flipper.setVelocity(75, percent);
  flipper.spinFor(forward, 5, rev);
  wait(3, seconds);
  flipper.stop();
}

void towerCenter(int color) {
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.print("Starting tower center routine");

  if (color == SIGRED)
    Vision1.takeSnapshot(REDSIG);
  else if (color == SIGBLUE)
    Vision1.takeSnapshot(BLUESIG);
  else if (color == SIGGREEN)
    Vision1.takeSnapshot(GREENSIG);

  int objectCenter = Vision1.largestObject.centerX;

  while ((objectCenter > CENTER_X + 10) || (objectCenter < CENTER_X - 10)) {
    if (color == SIGRED)
      Vision1.takeSnapshot(REDSIG);
    else if (color == SIGBLUE)
      Vision1.takeSnapshot(BLUESIG);
    else if (color == SIGGREEN)
      Vision1.takeSnapshot(GREENSIG);

    objectCenter = Vision1.largestObject.centerX;
    Brain.Screen.setCursor(2, 2);
    Brain.Screen.clearLine();
    Brain.Screen.print(objectCenter);

    if (objectCenter > CENTER_X + 5) {
      Brain.Screen.print("turn right");
      BackRight.spin(directionType::rev, 10, velocityUnits::pct);
      BackLeft.spin(directionType::fwd, 10, velocityUnits::pct);
      FrontRight.spin(directionType::rev, 10, velocityUnits::pct);
      FrontLeft.spin(directionType::fwd, 10, velocityUnits::pct);
    } else if (objectCenter < CENTER_X - 5) {
      Brain.Screen.print("turn left ");
      BackRight.spin(directionType::fwd, 10, velocityUnits::pct);
      BackLeft.spin(directionType::rev, 10, velocityUnits::pct);
      FrontRight.spin(directionType::fwd, 10, velocityUnits::pct);
      FrontLeft.spin(directionType::rev, 10, velocityUnits::pct);
    } else {
      Brain.Screen.print("Dont move");
      BackRight.stop();
      BackLeft.stop();
      FrontRight.stop();
      FrontLeft.stop();
    }
  }
  Brain.Screen.newLine();
  Brain.Screen.print("DONE");
  BackRight.stop(brakeType::brake);
  BackLeft.stop(brakeType::brake);
  FrontRight.stop(brakeType::brake);
  FrontLeft.stop(brakeType::brake);
}

void ballCenter(int color) {
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.print("Starting ball center routine");

  if (color == SIGRED)
    Vision2.takeSnapshot(REDSIG2);
  else if (color == SIGBLUE)
    Vision2.takeSnapshot(BLUESIG2);
  else if (color == SIGGREEN)
    Vision2.takeSnapshot(GREENSIG2);

  int objectCenter = Vision2.largestObject.centerX;

  while ((objectCenter > CENTER_X + 10) || (objectCenter < CENTER_X - 10)) {
    if (color == SIGRED)
      Vision2.takeSnapshot(REDSIG2);
    else if (color == SIGBLUE)
      Vision2.takeSnapshot(BLUESIG2);
    else if (color == SIGGREEN)
      Vision2.takeSnapshot(GREENSIG2);

    objectCenter = Vision2.largestObject.centerX;
    Brain.Screen.setCursor(2, 2);
    Brain.Screen.clearLine();
    Brain.Screen.print(objectCenter);

    if (objectCenter < CENTER_X - 5) {
      Brain.Screen.print("turn right");
      BackRight.spin(directionType::rev, 10, velocityUnits::pct);
      BackLeft.spin(directionType::fwd, 10, velocityUnits::pct);
      FrontRight.spin(directionType::rev, 10, velocityUnits::pct);
      FrontLeft.spin(directionType::fwd, 10, velocityUnits::pct);
    } else if (objectCenter > CENTER_X + 5) {
      Brain.Screen.print("turn left ");
      BackRight.spin(directionType::fwd, 10, velocityUnits::pct);
      BackLeft.spin(directionType::rev, 10, velocityUnits::pct);
      FrontRight.spin(directionType::fwd, 10, velocityUnits::pct);
      FrontLeft.spin(directionType::rev, 10, velocityUnits::pct);
    } else {
      Brain.Screen.print("Dont move");
      BackRight.stop();
      BackLeft.stop();
      FrontRight.stop();
      FrontLeft.stop();
    }
  }
  Brain.Screen.newLine();
  Brain.Screen.print("DONE");
  BackRight.stop(brakeType::brake);
  BackLeft.stop(brakeType::brake);
  FrontRight.stop(brakeType::brake);
  FrontLeft.stop(brakeType::brake);
}

void tower(uint8_t timeOut) {
  uint64_t startTime = Brain.timer(timeUnits::sec);
  while ((!bumpSwitch.pressing()) &&
         (Brain.timer(timeUnits::sec) - startTime < timeOut)) {
    BackRight.spin(directionType::fwd, 35, velocityUnits::pct);
    BackLeft.spin(directionType::fwd, 35, velocityUnits::pct);
    FrontRight.spin(directionType::fwd, 35, velocityUnits::pct);
    FrontLeft.spin(directionType::fwd, 35, velocityUnits::pct);
  }
  BackRight.stop();
  BackLeft.stop();
  FrontRight.stop();
  FrontLeft.stop();
}

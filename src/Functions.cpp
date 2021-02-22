#include "functions.h"
#include "DriveFunctionsConfig.h"
#include "vex.h"
#include "vision.h"

#define CENTER_X 316 / 2.0f
#define CENTER_Y 212 / 2.0f

void testPID() {
  for (int i = 0; i < 8; i++) {
    moveLinear(12, 100);
    moveRotate(-90, 90);
  }
  // moveStop();
  wait(20, msec); // Sleep the task for a short amount of time t
}

void cameraCenter(vision::signature &sig)
{
  int numObjects = Vision1.takeSnapshot(sig);

  Brain.Screen.setCursor(2, 1);
  Brain.Screen.print("centerX: %d\n", Vision1.largestObject.centerX);
  Brain.Screen.newLine();
  Brain.Screen.print("centerY: %d", Vision1.largestObject.centerY);
  Brain.Screen.newLine();
  Brain.Screen.clearLine();

  if (Vision1.largestObject.exists) {
    if (Vision1.largestObject.centerX > (CENTER_X + 20)) {
      Brain.Screen.print("turn right");
      BackRight.spin(directionType::rev, 20, velocityUnits::pct);
      BackLeft.spin(directionType::fwd, 20, velocityUnits::pct);
      FrontRight.spin(directionType::rev, 20, velocityUnits::pct);
      FrontLeft.spin(directionType::fwd, 20, velocityUnits::pct);
    } else if (Vision1.largestObject.centerX < (CENTER_X - 20)) {
      Brain.Screen.print("turn left ");
      BackRight.spin(directionType::fwd, 20, velocityUnits::pct);
      BackLeft.spin(directionType::rev, 20, velocityUnits::pct);
      FrontRight.spin(directionType::fwd, 20, velocityUnits::pct);
      FrontLeft.spin(directionType::rev, 20, velocityUnits::pct);
    } else {
      Brain.Screen.print("Dont move");
      BackRight.stop();
      BackLeft.stop();
      FrontRight.stop();
      FrontLeft.stop();
    }
  } else {
    Brain.Screen.print("nothing detected");
    BackRight.stop();
    BackLeft.stop();
    FrontRight.stop();
    FrontLeft.stop();
  }

  wait(20, msec); // Sleep the task for a short amount of time to
}

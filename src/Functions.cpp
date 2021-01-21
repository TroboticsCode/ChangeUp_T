#include "functions.h"
#include "DriveFunctionsConfig.h"
#include "vex.h"

void testPID()
{
  for(int i = 0; i < 8; i++)
  {
    moveLinear(12, 100);  
    moveRotate(-90, 90);
    
  }
  //moveStop();
  wait(20, msec); // Sleep the task for a short amount of time t
}
void runIntake(float speed, float time){
  rollerTop.spin(directionType::fwd, speed, velocityUnits::pct);
  rollerBottom.spin(directionType::fwd, speed, velocityUnits::pct);
  wait(time, msec);
  rollerTop.stop(brakeType::brake);
  rollerBottom.stop();
}
void punch(){
  puncher.rotateFor(-1.8, rotationUnits::rev, 100, velocityUnits::pct, true);

  //puncher.spin(directionType::fwd, 100, velocityUnits::pct);
  //wait(time, msec);
  //puncher.stop(brakeType::brake);
}
void punchBack(){
  puncher.rotateFor(2.25, rotationUnits::rev, 100, velocityUnits::pct, true);
  /*puncher.spin(directionType::rev, 100, velocityUnits::pct);
  wait(time, msec);
  puncher.stop(brakeType::brake);*/
}
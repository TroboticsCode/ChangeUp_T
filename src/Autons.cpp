#include "vex.h"
#include "Autons.h"
#include "Functions.h"
#include "DriveFunctionsConfig.h"

//Put your auton routines in here

void Auton1()
{
  //          kP kI  kD slew minDT
  setLinGains(40, 0.00, 35, 1.8, 30);
  setRotGains(35, 0.004, 20, 3, 20);
  //moveLinear(36, 100);
  moveRotate(-360, 25);
  moveStop();
}

void AutonSkeleton()
{  
  //setLinGains(80, 0.001, 35, 30, 20);
  //setRotGains(35, 0.004, 20, 30, 20);
}
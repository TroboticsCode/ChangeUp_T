#include "vex.h"
#include "Autons.h"
#include "Functions.h"
#include "DriveFunctionsConfig.h" 

//Put your auton routines in here

void Auton1()
{
  runIntake(100, 5000);
  punch();

  moveLinear(-70, 50);
  
  wait(5000, msec);
  punchBack();
  wait(1000, msec);
}
void Auton2()
{
  punch();
}
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

void pidTuning()
{
  moveLinear(36, 100);
  /*for(int i = 0; i < 8; i++)
  {
    moveLinear(12, 100);  
    moveRotate(-90, 90);
    
  }
  */
  moveStop();
  wait(20, msec); // Sleep the task for a short amount of time t
}
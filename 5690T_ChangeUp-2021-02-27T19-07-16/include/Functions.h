#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//always include vex.h because it has all the robot setup declarations
//as well as the API for the code.
#include "vex.h"

#define SIGRED   1
#define SIGBLUE  2
#define SIGGREEN 3

//enter the prototypes for other functions here
//lift, claw, etc
//drive function prototypes can go here but they should be in the DriveFunctions.h file
void testPID(void);
void cameraCenter(int color);

void punch();
void punchBack();
void intakeUp (float time);
void intakeDown (float time);
void intakeDrive (float time, float angle);
void intakeEnd();
void pickUp(float time);
void Flipper ();
void tower();

#endif
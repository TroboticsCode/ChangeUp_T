#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

using namespace vex;

extern brain Brain;

// VEXcode devices - declare new devices here, set them up
// in robot-config.cpp
extern controller Controller1;
extern motor rollerTop;
extern motor rollerBottom;
extern motor Puncher;
extern motor flipper;
extern bumper bumpSwitch;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

#endif
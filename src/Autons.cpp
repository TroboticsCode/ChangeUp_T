#include "Autons.h"
#include "DriveFunctionsConfig.h"
#include "Functions.h"
#include "vex.h"

// Put your auton routines in here

void Auton1() {
  //          kP   kI  kD slew minDT
  setLinGains(45, 0.004, 15, 40, 30); // large move

  //setLinGains(85, 0.04, 15, 40, 30); // small move
  // setRotGains(0.008, 0.00000025, 0.065, 40, 30);
  // setRotGains(0.015, 0.000000008, 0.07, 40, 30);
  // moveLinear(36, 100);
  // moveRotate(-45, 100, 30);
  // moveLinear(6, 100, 30);
  // moveStop();
  // ballCenter(SIGRED);
 YOLO(5);
}

void AutonSkills1() {
  /*setLinGains(45, 0.004, 15, 40, 30);
  setRotGains(0.015, 0.000000008, 0.07, 40, 30);
  moveLinear(24, 100, 1000);
  moveStop();
  moveRotate(-135, 100, 1000);
  moveStop();
  moveLinear(18,100,1000);
  towerCenter(SIGGREEN);
  moveTower(2500);
  towerCenter(SIGGREEN);
  rollerTop.setVelocity(100, percent);
  rollerTop.spinFor(1.5, seconds);
  rollerTop.stop();
  moveLinear(-60, 100, 1000);
  moveStop();
  moveRotate(-55, 100, 1000);
  moveStop();
  moveLinear(16, 100, 1000);
  moveStop();
  towerCenter(SIGGREEN);
  moveLinear(17, 100, 1000);
  moveStop();
  towerCenter(SIGGREEN);
  intakeUp(2);
  moveLinear(-24, 100, 1000);
  moveStop();
  moveRotate(-50, 100, 1000);
  moveStop();
  moveLinear(25, 100, 2000);
  moveStop();
  towerCenter(SIGGREEN);
  moveLinear(30, 100, 1000);
  moveStop();
  moveTower(3000);
  intakeUp(2);*/

  /*setLinGains(45, 0.004, 15, 40, 30);
  setRotGains(0.015, 0.000000008, 0.07, 40, 30);
  moveTower(3000);
  towerCenter(SIGGREEN);
  rollerTop.setVelocity(100, percent);
  rollerTop.spinFor(1.5, seconds);
  rollerTop.stop();
  moveLinear(-61, 100, 3000);
  moveStop();
  moveRotate(-50, 100, 1000);
  moveStop();
  tower(3000); 
  intakeUp(1.7); //score middle tower
  moveRotate(-100, 100, 1000);
  moveStop();
  moveLinear(48, 100, 1000); //move towards last tower
  moveStop();
  moveRotate(50, 100, 1000);
  moveStop();
  towerCenter(SIGGREEN);
  YOLO (5);*/
  YOLO(5);
  }

void AutonSkills2() {
  myGyro.calibrate();
  while (myGyro.isCalibrating())
    ;
  myGyro.resetRotation();
  setLinGains(45, 0.004, 15, 40, 30);
  setRotGains(0.015, 0.000000008, 0.07, 40, 30); // gains for big moves

  setLinGains(85, 0.04, 15, 40, 30); // gain for little moves
  moveLinear(10, 100, 1000);
  moveStop(); // move to a pick up ball 1
  rollerBottom.setVelocity(40, rpm);
  rollerBottom.spinFor(forward, 1.5, seconds);

  setLinGains(45, 0.004, 15, 40, 30);
  moveRotate(110, 100, 1500);
  moveStop();
  towerCenter(SIGGREEN); // rotates and aligns with tower 1
  tower(2000);
  towerCenter(SIGGREEN);
  setLinGains(85, 0.04, 15, 40, 30);
  moveLinear(-1, 100, 500);
  moveStop();
  setLinGains(45, 0.004, 15, 40, 30);

  intakeTop(1.5); // shoots preload

  rollerBottom.setVelocity(75, percent);
  rollerBottom.spin(forward);
  moveLinear(-48, 100, 3500); // holds ball 1 and moves to tower 2
  moveStop();

  rollerBottom.stop();
  moveRotate(77, 100, 1500);
  moveStop(); // aligns with tower 2 and shoots ball 1
  towerCenter(SIGGREEN);
  tower(1500);
  intakeUp(2.5);

  moveRotate(90, 100, 1250);
  moveStop();
  rollerBottom.setVelocity(75, percent); // moves to tower 3 and grab ball 2
  rollerBottom.spin(forward);
  ballCenter(SIGRED);
  moveLinear(20, 100, 2000);
  moveStop();
  ballCenter(SIGRED);
  moveLinear(16, 100, 1500);
  moveStop();
  rollerBottom.stop();

  moveRotate(-40, 100, 1000);
  moveStop();
  towerCenter(SIGGREEN);
  tower(2000); // aligns and scores ball 2
  towerCenter(SIGGREEN);
  intakeUp(2.5);

  moveLinear(-9, 100, 500);
  moveStop();
  moveRotate(120, 100, 1000);
  moveStop();
  ballCenter(SIGRED);
  rollerBottom.setVelocity(25, percent); // moves to tower 4 and picks up ball 3
  rollerBottom.spin(forward);
  moveLinear(24, 100, 2000);
  moveStop();
  ballCenter(SIGRED);
  moveLinear(24, 100, 2000);
  moveStop();
  rollerBottom.stop(brake);

  moveRotate(-80, 100, 1250);
  moveStop();
  towerCenter(SIGGREEN); // aligns with tower 4 and shoots ball 3
  tower(1500);
  intakeUp(2.5);

  setLinGains(45, 0.04, 15, 40, 30);
  moveLinear(-6, 100, 1000);
  moveStop();
  setLinGains(45, 0.004, 15, 40, 30);
  moveRotate(90, 100, 1500);
  moveStop();
  rollerBottom.setVelocity(40, percent);
  rollerBottom.spin(forward);
  ballCenter(SIGRED); // aligns to pickup ball 4
  moveLinear(32, 100, 3000);
  moveStop();
  ballCenter(SIGRED);
  moveLinear(16, 100, 1500);
  moveStop();
  rollerBottom.stop(brake);

  moveRotate(-45, 100, 1500);
  moveStop();
  towerCenter(SIGGREEN); // aligns with tower 5 and shoots ball 4
  tower(1500);
  towerCenter(SIGGREEN);
  intakeUp(2.5);

  moveLinear(-6, 100, 1000);
  moveStop();
  moveRotate(160, 100, 1500);
  moveStop();
  rollerBottom.setVelocity(25, percent);
  rollerBottom.spin(forward);
  moveLinear(24, 100, 2000);
  moveStop();
  ballCenter(SIGRED);
  moveLinear(15, 100, 1500);
  moveStop();    // aligns with tower 6 and shoots ball 5 
  ballCenter(SIGRED);
  moveLinear(15, 100, 1500);
  moveStop();
  rollerBottom.stop(brake);
  moveRotate(-110, 100, 1500);
  moveStop();
  towerCenter(SIGGREEN);
  rollerTop.setVelocity(100, percent);
  rollerBottom.setVelocity(100, percent);
  rollerTop.spin(forward);
  rollerBottom.spin(forward);
  tower(1500);
  wait(3,sec);
  rollerBottom.stop();
  rollerTop.stop();

  moveLinear(-4, 100, 1000);
  moveStop();
  moveRotate(90,100,1000);
  moveStop();
  rollerBottom.setVelocity(100,percent);
  ballCenter(SIGRED);
  moveLinear(16, 100, 1000);
  moveStop();
  ballCenter(SIGRED);
  moveLinear(16,100,1000);
  moveStop();
  rollerBottom.stop();
  towerCenter(SIGGREEN);
  tower(2000);
  rollerBottom.setVelocity(100,percent);
  rollerTop.setVelocity(100, percent);
  towerCenter(SIGGREEN);
}
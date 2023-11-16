#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;
controller Controller(primary);

// VEXcode device constructors

//DriveTrain
motor BRMotor(PORT1, ratio18_1, false);
motor BLMotor(PORT10, ratio18_1, true);
motor FLMotor(PORT20, ratio18_1, true);
motor FRMotor(PORT11, ratio18_1);

//Hitter
motor HLeft(PORT19, ratio36_1, true);
motor HRight(PORT13, ratio36_1);

motor_group Hitter = motor_group(HLeft, HRight);


// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;
controller Controller(primary);

// VEXcode device constructors

//DriveTrain
motor BRMotor(PORT12, ratio18_1, true);
motor BLMotor(PORT15, ratio18_1, false);
motor FLMotor(PORT20, ratio18_1, false);
motor FRMotor(PORT11, ratio18_1, true);
motor MLMotor(PORT14, ratio18_1, false);
motor MRMotor(PORT13, ratio18_1, true);

motor SLeft(PORT8, ratio36_1, true);
motor SRight(PORT2, ratio36_1);

motor_group Slapper(SLeft, SRight);

digital_out LWing(Brain.ThreeWirePort.G);
digital_out RWing(Brain.ThreeWirePort.H);

// VEXcode generated functions
/*
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}

//END 23-24 SEASON
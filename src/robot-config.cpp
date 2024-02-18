#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;
controller Controller(primary);

// VEXcode device constructors

//DriveTrain
motor BRMotor(PORT11, ratio18_1, true);
motor BLMotor(PORT19, ratio18_1, false);
motor FLMotor(PORT1, ratio18_1, false);
motor FRMotor(PORT10, ratio18_1, true);
motor MLMotor(PORT2, ratio18_1, false);
motor MRMotor(PORT3, ratio18_1, true);


//Hitter
motor SLeft(PORT5, ratio36_1, true);
motor SRight(PORT3, ratio36_1);

motor_group Slapper(SLeft, SRight);

digital_out LWing(Brain.ThreeWirePort.A);
digital_out RWing(Brain.ThreeWirePort.B);
// VEXcode generated functions
/*
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
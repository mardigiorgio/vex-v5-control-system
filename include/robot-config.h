using namespace vex;

extern brain Brain;
extern controller Controller;

// VEXcode devices

extern motor BLMotor;
extern motor BRMotor;
extern motor FLMotor;
extern motor FRMotor;

extern motor HLeft;
extern motor HRight;

extern motor_group Hitter;
/*
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
*/
void vexcodeInit( void );
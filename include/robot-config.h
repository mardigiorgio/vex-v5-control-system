using namespace vex;

extern brain Brain;
extern controller Controller;

// VEXcode devices

extern motor BLMotor;
extern motor BRMotor;
extern motor FLMotor;
extern motor FRMotor;

extern motor SLeft;
extern motor SRight;

extern motor_group Slapper;
/*
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
*/
void vexcodeInit( void );
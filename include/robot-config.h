using namespace vex;

extern brain Brain;
extern controller Controller;

// VEXcode devices

extern motor BLMotor;
extern motor BRMotor;
extern motor FLMotor;
extern motor FRMotor;
extern motor MRMotor;
extern motor MLMotor;

extern motor SLeft;
extern motor SRight;

extern motor_group Slapper;

extern digital_out LWing;
extern digital_out RWing;
/*
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
*/
void vexcodeInit( void );

//END 23-24 SEASON
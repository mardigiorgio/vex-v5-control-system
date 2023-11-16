#include "vex.h"

using namespace vex;
competition Competition;

Drive chassis(
TANK_TWO_ROTATION,

//Left Motors:
motor_group(BLMotor, FLMotor),

//Right Motors:
motor_group(BRMotor, FRMotor),

//Inertial Sensor
PORT12,

//DriveTrain Wheel Diameter
3.08,

//DriveTrain Gear Ratio
2,

//Gyro scaling factor to reduce error
360,


//For no tracking only adjust the forward tracker center distance.

//holonomatic drives only: input drive motors by position.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//Forward tracker port
PORT2,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
-2.58,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
-1.93,

//Sideways Tracker Port
PORT5,

//Sideways tracker diameter(reverse for direction switch):
2.58,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
0.96

);

int current_auton_selection = 0;
bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  while(auto_started == false){            
    Brain.Screen.clearScreen();           
    switch(current_auton_selection){      
      case 0:
        Brain.Screen.printAt(50, 50, "Drive Test");
        break;
      case 1:
        Brain.Screen.printAt(50, 50, "Drive Test");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "Turn Test");
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "Swing Test");
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "Full Test");
        break;
      case 5:
        Brain.Screen.printAt(50, 50, "Odom Test");
        break;
      case 6:
        Brain.Screen.printAt(50, 50, "Tank Odom Test");
        break;
      case 7:
        Brain.Screen.printAt(50, 50, "Holonomic Odom Test");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){  
    case 0:
      odom_test(); //default auton
      break;        
    case 1:         
      drive_test();
      break;
    case 2:
      turn_test();
      break;
    case 3:
      swing_test();
      break;
    case 4:
      full_test();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}

void usercontrol(void) {
  chassis.set_coordinates(0, 0, 0);
  Brain.Screen.clearScreen();
  while (1) {
    chassis.control_arcade();
    
    if(Controller.ButtonDown.pressing()) {
      chassis.drive_to_point(0, 0, 6, 12, 5, 5000, 30000, 0.45 , 0.2, 0.2, 0, 0.5, 0.2, 0.5, 0);
    } 

    if(Controller.ButtonR1.pressing()) {
      Hitter.spin(forward, 8, volt);
    } else {
      Hitter.spin(forward, 0, volt);
    }

    wait(20, msec); // Sleep the task for a short amount of time to prevent wasted resources.
  }
}


int main() {
  // set up callbacks for autonomous and driver control periods
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // run the pre-autonomous function
  pre_auton();

  // prevent main from exiting with an infinite loop
  while (true) {
    wait(100, msec);
  }
}

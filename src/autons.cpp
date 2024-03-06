#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(12, 1.2, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, 0.5, .03, 3, 15);
  chassis.set_swing_constants(12, 1.2, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}

void push() {
  chassis.drive_distance(70);
  chassis.drive_distance(-25);
  chassis.drive_distance(40);
  chassis.drive_distance(-70);
}

void skills() {
  default_constants();

  //Sets the bots coords to 0,0 at 0 deg
  chassis.set_coordinates(0,0,0);

  //Turn and back up to touch the match load bar
  chassis.turn_to_angle(-20);
  chassis.drive_distance(-4);

  //Start spinning the slapper
  Slapper.spin(forward, 15, volt);

  //Stop the slapper
  Slapper.spin(forward, 0, volt);

  //Drive away from the match load ar
  chassis.drive_distance(15);
  chassis.turn_to_angle(25);
  chassis.drive_distance(45);

  //Drive under the elevation bar
  chassis.turn_to_point(7,80);
  chassis.drive_to_point(7,80);

  //Turn towards the goal and group the balls up on the right side of the goal
  chassis.right_swing_to_angle(-40);
  LWing.set(true);
  RWing.set(true);
  chassis.drive_distance(70, -40, 12, 12);
  RWing.set(false);

  //Face right side of goal and push balls in
  chassis.right_swing_to_angle(-85);
  chassis.drive_distance(-15);
  chassis.drive_distance(45, -85, 12, 12, 0, 0, 2000);
  
  //Drive away from the goal and towards the long bar
  chassis.drive_distance(-15);
  LWing.set(false);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-90, 0, 12, 12);

  //Drive towards the middle of field
  chassis.left_swing_to_angle(-90);
  chassis.drive_distance(80, -90, 12, 12);

  //Turn towards goal
  chassis.left_swing_to_angle(0);

  //Open Wings
  LWing.set(true);
  RWing.set(true);

  //Drive backwards for more accel time
  chassis.drive_distance(-20, 0, 12, 12);

  //Push into goal
  chassis.drive_distance(60, 0, 12, 12);
}
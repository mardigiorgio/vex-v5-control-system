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
  chassis.turn_to_angle(12);
  chassis.drive_distance(110, 12);
  chassis.drive_distance(-110, 12);
  pre_driver_match();
}

void skills() {
  default_constants();

  //Sets the bots coords to 0,0 at 0 deg
  chassis.set_coordinates(0,0,0);

  //Turn and back up to touch the match load bar
  chassis.turn_to_angle(-25);
  chassis.drive_distance(-3);

  int trueX = chassis.get_X_position();
  int trueY = chassis.get_Y_position();
  int trueHeading = chassis.get_absolute_heading();

  //Start spinning the slapper
  Slapper.spin(forward, 15, volt);
  wait(28,sec);
  //Stop the slapper
  Slapper.spin(forward, 0, volt);

  //Sets the bots coords to actual heading before vibration interferance
  chassis.set_coordinates(trueX,trueY,trueHeading);

  //Drive away from the match load ar
  chassis.drive_distance(15);
  chassis.turn_to_angle(25);
  chassis.drive_distance(45);

  //Drive under the elevation bar
  chassis.turn_to_point(8,80);
  chassis.drive_to_point(8,80);

  //left turn
  chassis.turn_to_angle(-90);
  chassis.drive_distance(60);

  //Drive towards long bar
  chassis.turn_to_angle(0);
  chassis.drive_distance(-60);

  //Turn left towards middle of longbar amd drive 
  chassis.turn_to_angle(-90);
  chassis.drive_distance(90);

  chassis.turn_to_angle(0);

  //Open Wings
  LWing.set(true);
  RWing.set(true);

  //Drive backwards for more accel time
  chassis.drive_distance(-10, 0, 12, 12, 0, 500, 500);

  //Push into goal
  chassis.drive_distance(90, 0, 12, 12, 5, 1500, 1500);
  chassis.drive_distance(-50, 0, 12, 12, 5, 1300, 1300);
  chassis.drive_distance(50, 0, 12, 12, 5, 1300, 1300);
  chassis.drive_distance(-80, 0, 12, 12, 5, 1200, 1200);

  LWing.set(false);
  RWing.set(false);

  chassis.turn_to_angle(18);
  chassis.drive_distance(90, 18, 12, 12, 5, 1200, 1200);
  chassis.drive_distance(-50, 18, 12, 12, 5, 1200, 1200);
  chassis.drive_distance(50, 18, 12, 12, 5, 1200, 1200);
  chassis.drive_distance(-80, 18, 12, 12, 5, 1200, 1200);

  chassis.turn_to_angle(-19);
  chassis.drive_distance(90, -19, 12, 12, 5, 1200, 1200);
  chassis.drive_distance(-50, -19, 12, 12, 5, 1200, 1200);
  chassis.drive_distance(50, -19, 12, 12, 5, 1200, 1200);
  chassis.drive_distance(-80, -19, 12, 12, 5, 1200, 1200);
}

void pre_driver() {
  default_constants();
  //Turn and back up to touch the match load bar
  chassis.turn_to_angle(-25);
  chassis.drive_distance(-3);

  int trueX = chassis.get_X_position();
  int trueY = chassis.get_Y_position();
  int trueHeading = chassis.get_absolute_heading();

  //Start spinning the slapper
  Slapper.spin(forward, 12, volt);
  wait(26 ,sec);
  //Stop the slapper
  Slapper.spin(forward, 0, volt);

  //Sets the bots coords to actual heading before vibration interferance
  chassis.set_coordinates(trueX,trueY,trueHeading);
}

void pre_driver_match() {
  default_constants();
  //Turn and back up to touch the match load bar
  chassis.turn_to_angle(-25);
  chassis.drive_distance(-8);
}

void winpoint() {
  chassis.set_coordinates(0,0,90);
  chassis.turn_to_angle(110);
  chassis.drive_distance(80);
  chassis.drive_distance(-20);
  chassis.turn_to_angle(130);
  chassis.drive_distance(-75);
  chassis.turn_to_angle(0);
  chassis.drive_distance(110);
}

void push_bad() {
  chassis.set_coordinates(0,0,90);
  chassis.turn_to_angle(110);
  chassis.drive_distance(80);
  chassis.drive_distance(-20);
  chassis.turn_to_angle(130);
  chassis.drive_distance(-75);
  chassis.turn_to_angle(0);
}

void descore_winpoint() {
  chassis.drive_distance(22);
  LWing.set(true);
  chassis.turn_to_angle(45);
  chassis.drive_distance(33);
  LWing.set(false);
  chassis.drive_distance(-33);
  chassis.turn_to_angle(10);
  chassis.drive_distance(-90);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-10);
}

//END 23-24 SEASON
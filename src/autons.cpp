#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void move_for(double inches) {
  bool slew = false;
  if (inches > 14) {
    slew = true;
  }
  chassis.set_drive_pid(inches, DRIVE_SPEED, slew, true);
  chassis.wait_drive();
}

void turn_to(double degrees) {
  chassis.set_turn_pid(degrees, TURN_SPEED);
  chassis.wait_drive();
}

///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}

void not_facing_roller() {
  move_for(24);

  turn_to(90);

  move_for(24);

  move_roller(-175);
}

void facing_roller() {
  move_for(12);

  move_roller(-175);
}

void auton_wp() {
  
}

void skills() {
  //go to goal
  move_for(-48);
  fire_cata();
  // get roller
  move_for(60);
  turn_to(90);
  move_for(24);
  move_roller(-450);
  //reposition
  move_for(-4);
  turn_to(270);
  //intake disc
  toggle_roller();
  move_for(24);
  toggle_roller();
  //go to goal
  turn_to(0);
  move_for(24);
  turn_to(90);
  move_for(-48);
  pros::delay(250);
  fire_cata();
  // go to roller
  move_for(48);
  turn_to(0);
  move_for(24);
  move_roller(-450);
  //go to matchload
  move_for(-4);
  turn_to(270);
  move_for(24);
  turn_to(0);
  move_for(24);
  pros::delay(3000);
  // go to goal
  move_for(-4);
  turn_to(90);
  move_for(-24);
  fire_cata();
  // go to matchload
  move_for(24);
  turn_to(0);
  move_for(24);
  pros::delay(3000);
  // go to goal
  move_for(-4);
  turn_to(90);
  move_for(-24);
  fire_cata();
  //go to matchload
  move_for(24);
  turn_to(180);
  move_for(160);
  pros::delay(3000);
  // go to goal
  move_for(-4);
  turn_to(270);
  move_for(-24);
  fire_cata();
  // go to matchload
  move_for(24);
  turn_to(180);
  move_for(24);
  pros::delay(3000);
  // go to goal
  move_for(-4);
  turn_to(270);
  move_for(-24);
  fire_cata();
  // go to roller
  move_for(-72);
  turn_to(180);
  move_for(24);
  move_roller(-450);
  // go to roller
  move_for(-28);
  turn_to(270);
  move_for(48);
  move_roller(-450);
  // position expansion
  move_for(-4);
  turn_to(180);
  move_for(12);
  turn_to(225);
  //fire_expansion();
}

void hold_position() {

}

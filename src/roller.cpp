#include "main.h"

void toggle_roller() {
  if (fabs(roller.get_actual_velocity()) >= 50) {
    roller.move_velocity(0);
  } else {
    roller.move_velocity(200);
  }
}

void reverse_roller() {
  if (roller.get_actual_velocity() >= 50) {
    roller.move_velocity(-200);
  } else if (roller.get_actual_velocity() <= -50) {
    roller.move_velocity(200);
  }
}

void move_roller(int distance) {
    roller.move_relative(distance, 175);
    wait_roller();
}

void wait_roller() {
  while (fabs(roller.get_target_position() - roller.get_position()) < 2) {
    pros::delay(10);
  }
  pros::delay(500);
}
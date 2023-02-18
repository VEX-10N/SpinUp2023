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

void move_roller(double distance, double speed) {
    roller.move_relative(distance, speed);
}
#include "main.h"

int selectedAuton = 0;
bool autonLocked = false;

void select_auton() {
    if (!autonLocked) {
        if (selectedAuton >= ez::as::auton_selector.auton_count - 1) {
            selectedAuton = 0;
        } else {
            selectedAuton++;
        }
    }
}

void lock_auton() {
    autonLocked = true;
}

void init_gui() {
    
}

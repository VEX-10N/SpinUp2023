#include "main.h"

bool firingCata = false;
bool firstFire = false;

int cata_task() {
    while (true) {
        if (master.get_digital(DIGITAL_L2)) {
            cata.move_velocity(150);
        } else {
            cata.move_velocity(0);
        }
        pros::delay(20);
    }    
    return 0;
}

void fire_cata() {
    firingCata = true;
    firstFire = true;
}




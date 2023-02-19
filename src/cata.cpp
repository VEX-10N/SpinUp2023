#include "main.h"

const int cata_stop = 260;
bool firingCata = false;
bool firstFire = false;

int cata_task() {
    while (true) {
        if (firingCata == true) {
            double rotation = cataRotation.get_angle() * 0.01;
            if (rotation >= 0 && rotation <= 50) rotation = 359;
            std::cout << rotation << std::endl;
            if (rotation <= cata_stop) {
                if (firstFire) {
                    cata.move_velocity(200);
                    pros::delay(1000);
                } else {
                    cata.move_velocity(0);
                    firingCata = false;
                }
            } else if (rotation <= (cata_stop + 20)) {
                cata.move_velocity(50);
            } else if (rotation <= 360) {
                cata.move_velocity(200);
            }
            firstFire = false;
        } else if (firingCata == false && master.get_digital_new_press(DIGITAL_L2)) {
            fire_cata();
        }  
        pros::delay(20);
    }    
    return 0;
}

void fire_cata() {
    firingCata = true;
    firstFire = true;
}




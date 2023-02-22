#include "main.h"

bool firingCata = false;
bool firstFire = false;

int cata_task() {
    while (true) {
        if (firingCata == true) {
            double rotation = cataRotation.get_angle() * 0.01;
            if (rotation >= 0 && rotation <= 50) rotation = 359;
            if (rotation <= CATA_STOP) {
                if (firstFire) {
                    firstFire = false;
                    std::cout << rotation << std::endl;
                    cata.move_velocity(200);
                    pros::delay(1000);
                } else {
                    cata.move_velocity(0);
                    firingCata = false;
                    std::cout << rotation << std::endl;
                }
            } else if (rotation <= (CATA_STOP + 15)) {
                cata.move_velocity(30);
            } else if (rotation <= 360) {
                cata.move_velocity(200);
            }
        }  
        pros::delay(20);
    }    
    return 0;
}

void fire_cata() {
    firingCata = true;
    firstFire = true;
}

void wait_cata() {
  while (firingCata) {
    pros::delay(10);
  }
  pros::delay(250);
}




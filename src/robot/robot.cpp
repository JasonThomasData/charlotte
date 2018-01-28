#include <memory>
#include <unistd.h>

#include "../leg/i_leg_driver.h" 
#include "robot.h"

Robot::Robot(ILegDriver* leg_0_to_add, ILegDriver* leg_1_to_add,
             ILegDriver* leg_2_to_add, ILegDriver* leg_3_to_add)
    :leg_0(leg_0_to_add), leg_1(leg_1_to_add), leg_2(leg_2_to_add), leg_3(leg_3_to_add){};

void Robot::walk_forward()
{
    leg_0->up();
    usleep(1000000);
    leg_0->anti_clockwise();
    usleep(1000000);
    leg_0->down();
    usleep(1000000);
    leg_0->clockwise();
    usleep(1000000);
    leg_0->extend_flat();
    usleep(1000000);
    leg_0->middle();
    usleep(1000000);
}

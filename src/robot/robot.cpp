#include <memory>
#include <unistd.h>

#include "../leg/i_leg_driver.h" 
#include "robot.h"

Robot::Robot(ILegDriver* leg_0_to_add, ILegDriver* leg_1_to_add,
             ILegDriver* leg_2_to_add, ILegDriver* leg_3_to_add,
             int duration)
    :leg_0(leg_0_to_add), leg_1(leg_1_to_add), leg_2(leg_2_to_add), leg_3(leg_3_to_add), action_duration(duration){};

void Robot::walk_forward()
{
    //move_lock = true;

    leg_0->up();
    leg_2->up();

    usleep(action_duration);

    leg_0->anti_clockwise();
    leg_1->clockwise();
    leg_2->clockwise();
    leg_3->anti_clockwise();

    usleep(action_duration);

    leg_0->down();
    leg_1->up();
    leg_2->down();
    leg_3->up();

    usleep(action_duration);

    leg_0->clockwise();
    leg_1->anti_clockwise();
    leg_2->anti_clockwise();
    leg_3->clockwise();

    usleep(action_duration);

    leg_0->up();
    leg_1->down();
    leg_2->up();
    leg_3->down();

    usleep(action_duration);

    leg_0->middle();
    leg_1->middle();
    leg_2->middle();
    leg_3->middle();

    usleep(action_duration);

    leg_0->down();
    leg_2->down();

    //move_lock = false;
}

#include <memory>

#include "leg_driver_02.h"

// NOTE - To save future confusion, this is the prototype leg.

LegDriver_02::LegDriver_02(IServoDriver* bottom_to_add,
                           IServoDriver* middle_to_add,
                           IServoDriver* top_to_add)
{
    bottom_servo = bottom_to_add;
    middle_servo = middle_to_add;
    top_servo = top_to_add;
}

void LegDriver_02::up()
{
    bottom_servo->goto_27_degrees();
    middle_servo->goto_27_degrees();
    top_servo->off();
}

void LegDriver_02::down()
{
    bottom_servo->goto_90_degrees();
    middle_servo->goto_135_degrees();
    top_servo->off();
}

void LegDriver_02::extend_flat()
{
    bottom_servo->goto_135_degrees();
    middle_servo->goto_90_degrees();
    top_servo->off();
}


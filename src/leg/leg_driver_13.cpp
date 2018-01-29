#include <memory>

#include "leg_driver_13.h"

LegDriver_13::LegDriver_13(IServoDriver* bottom_to_add,
                           IServoDriver* middle_to_add,
                           IServoDriver* top_to_add)
{
    bottom_servo = bottom_to_add;
    middle_servo = middle_to_add;
    top_servo = top_to_add;
}

void LegDriver_13::up()
{
    bottom_servo->goto_153_degrees();
    middle_servo->goto_153_degrees();
    top_servo->off();
}

void LegDriver_13::down()
{
    bottom_servo->goto_90_degrees();
    middle_servo->goto_45_degrees();
    top_servo->off();
}

void LegDriver_13::extend_flat()
{
    bottom_servo->goto_45_degrees();
    middle_servo->goto_90_degrees();
    top_servo->off();
}


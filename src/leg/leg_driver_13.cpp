#include <memory>

#include "leg_driver_13.h"

LegDriver_13::LegDriver_13(IServoDriver* bottom_to_add,
                           IServoDriver* middle_to_add,
                           IServoDriver* top_to_add)
    :bottom_servo(bottom_to_add), middle_servo(middle_to_add), top_servo(top_to_add){};

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

// Find a way to compose what's below

void LegDriver_13::clockwise()
{
    bottom_servo->off();
    middle_servo->off();
    top_servo->goto_126_degrees();
}

void LegDriver_13::middle()
{
    bottom_servo->off();
    middle_servo->off();
    top_servo->goto_90_degrees();
}

void LegDriver_13::anti_clockwise()
{
    bottom_servo->off();
    middle_servo->off();
    top_servo->goto_54_degrees();
}

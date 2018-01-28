#include "leg_driver_base.h"

void LegDriverBase::clockwise()
{
    bottom_servo->off();
    middle_servo->off();
    top_servo->goto_126_degrees();
}

void LegDriverBase::middle()
{
    bottom_servo->off();
    middle_servo->off();
    top_servo->goto_90_degrees();
}

void LegDriverBase::anti_clockwise()
{
    bottom_servo->off();
    middle_servo->off();
    top_servo->goto_54_degrees();
}

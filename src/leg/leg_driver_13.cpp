#include <memory>

#include "leg_driver_13.h"

LegDriver_13::LegDriver_13(std::unique_ptr<IServoDriver> bottom_to_add,
                           std::unique_ptr<IServoDriver> middle_to_add,
                           std::unique_ptr<IServoDriver> top_to_add)
{
    bottom_servo = std::move(bottom_to_add);
    middle_servo = std::move(middle_to_add);
    top_servo = std::move(top_to_add);
}

void LegDriver_13::up()
{
    bottom_servo->goto_117_degrees();
    middle_servo->goto_153_degrees();
    top_servo->off();
}

void LegDriver_13::down()
{
    bottom_servo->goto_45_degrees();
    middle_servo->goto_45_degrees();
    top_servo->off();
}

void LegDriver_13::extend_flat()
{
    bottom_servo->goto_0_degrees();
    middle_servo->goto_90_degrees();
    top_servo->off();
}

void LegDriver_13::rest()
{
    bottom_servo->goto_90_degrees();
    middle_servo->goto_135_degrees();
    top_servo->off();
}

#include <memory>

#include "leg_driver_02.h"

LegDriver_02::LegDriver_02(std::unique_ptr<IServoDriver> bottom_to_add,
                           std::unique_ptr<IServoDriver> middle_to_add,
                           std::unique_ptr<IServoDriver> top_to_add)
{
    bottom_servo = std::move(bottom_to_add);
    middle_servo = std::move(middle_to_add);
    top_servo = std::move(top_to_add);
}

void LegDriver_02::up()
{
    bottom_servo->goto_63_degrees();
    middle_servo->goto_27_degrees();
    top_servo->off();
}

void LegDriver_02::down()
{
    bottom_servo->goto_135_degrees();
    middle_servo->goto_135_degrees();
    top_servo->off();
}

void LegDriver_02::extend_flat()
{
    bottom_servo->goto_0_degrees();
    middle_servo->goto_90_degrees();
    top_servo->off();
}

void LegDriver_02::rest()
{
    bottom_servo->goto_90_degrees();
    middle_servo->goto_45_degrees();
    top_servo->off();
}

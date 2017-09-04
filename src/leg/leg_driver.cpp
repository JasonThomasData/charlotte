#include <memory>

#include "leg_driver.h"
#include "../servo/i_servo_driver.h"

LegDriver::LegDriver(std::unique_ptr<IServoDriver> bottom_to_add,
                     std::unique_ptr<IServoDriver> middle_to_add,
                     std::unique_ptr<IServoDriver> top_to_add)
    :bottom_servo(std::move(bottom_to_add)),middle_servo(std::move(middle_to_add)), top_servo(std::move(top_to_add))
{}

//////////////
// Horizontal

void LegDriver::clockwise()
{
    bottom_servo->off();
    middle_servo->off();
    top_servo->goto_126_degrees();
}

void LegDriver::middle()
{
    bottom_servo->off();
    middle_servo->off();
    top_servo->goto_90_degrees();
}

void LegDriver::anti_clockwise()
{
    bottom_servo->off();
    middle_servo->off();
    top_servo->goto_54_degrees();
}

//////////////
// Vertical

void LegDriver::up()
{
    bottom_servo->goto_117_degrees();
    middle_servo->goto_153_degrees();
    top_servo->off();
}

void LegDriver::down()
{
    bottom_servo->goto_45_degrees();
    middle_servo->goto_45_degrees();
    top_servo->off();
}

void LegDriver::extend_flat()
{
    bottom_servo->goto_0_degrees();
    middle_servo->goto_90_degrees();
    top_servo->off();
}

void LegDriver::rest()
{
    bottom_servo->goto_90_degrees();
    middle_servo->goto_135_degrees();
    top_servo->off();
}

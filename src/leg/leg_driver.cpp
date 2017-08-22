#include "leg_driver.h"

LegDriver::LegDriver(int bottom_pin, int middle_pin, int top_pin)
    :bottom_servo(bottom_pin), middle_servo(middle_pin), top_servo(top_pin)
{}

//////////////
// Horizontal

void LegDriver::clockwise()
{
    bottom_servo.off();
    middle_servo.off();
    top_servo.goto_123_degrees();
}

void LegDriver::middle()
{
    bottom_servo.off();
    middle_servo.off();
    top_servo.goto_90_degrees();
}

void LegDriver::anti_clockwise()
{
    bottom_servo.off();
    middle_servo.off();
    top_servo.goto_57_degrees();
}

//////////////
// Vertical

void LegDriver::up()
{
    bottom_servo.goto_115_degrees();
    middle_servo.goto_148_degrees();
    top_servo.off();
}

void LegDriver::down()
{
    bottom_servo.goto_49_degrees();
    middle_servo.goto_49_degrees();
    top_servo.off();
}

void LegDriver::extend_flat()
{
    bottom_servo.goto_0_degrees();
    middle_servo.goto_90_degrees();
    top_servo.off();
}

void LegDriver::rest()
{
    bottom_servo.goto_90_degrees();
    middle_servo.goto_131_degrees();
    top_servo.off();
}

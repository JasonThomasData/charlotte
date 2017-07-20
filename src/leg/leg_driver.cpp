#include "leg_driver.h"

LegDriver::LegDriver(int bottom_pin, int middle_pin, int top_pin)
    :bottom_servo(bottom_pin), middle_servo(middle_pin), top_servo(top_pin)
{}

void LegDriver::update_servos(int bottom_pos, int middle_pos, int top_pos)
{
    bottom_servo.change_position(bottom_pos);
    middle_servo.change_position(middle_pos);
    top_servo.change_position(top_pos);
}

//////////////
// Horizontal

void LegDriver::clockwise()
{
    int bottom_pos = 0;
    int middle_pos = 0;
    int top_pos = 18;
    update_servos(bottom_pos, middle_pos, top_pos);
}

void LegDriver::middle()
{
    int bottom_pos = 0;
    int middle_pos = 0;
    int top_pos = 14;
    update_servos(bottom_pos, middle_pos, top_pos);
}

void LegDriver::anti_clockwise()
{
    int bottom_pos = 0;
    int middle_pos = 0;
    int top_pos = 10;
    update_servos(bottom_pos, middle_pos, top_pos);
}

//////////////
// Vertical

void LegDriver::up()
{
    int bottom_pos = 16;
    int middle_pos = 20;
    int top_pos = 0;
    update_servos(bottom_pos, middle_pos, top_pos);
}

void LegDriver::down()
{
    int bottom_pos = 8;
    int middle_pos = 8;
    int top_pos = 0;
    update_servos(bottom_pos, middle_pos, top_pos);
}

void LegDriver::extend_flat()
{
    int bottom_pos = 2;
    int middle_pos = 13;
    int top_pos = 0;
    update_servos(bottom_pos, middle_pos, top_pos);
}

void LegDriver::rest()
{
    int bottom_pos = 13;
    int middle_pos = 18;
    int top_pos = 0;
    update_servos(bottom_pos, middle_pos, top_pos);
}

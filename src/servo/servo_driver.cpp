#include <softPwm.h>
#include <wiringPi.h>
#include <iostream>

#include "servo_driver.h"

ServoDriver::ServoDriver(int pin_number)
{
    range = 100; //Not application logic, this is a wiringPi setting. This works for the positions
    config_pin(pin_number);
}

int ServoDriver::check_new_position(int new_position)
{
    if (positions.minimum <= new_position and
        new_position <= positions.maximum or
        new_position == positions.off)
    {
        return 0;
    }
    return 1;
}

void ServoDriver::change_position(int new_position)
{
    int position_valid = check_new_position(new_position);
    if (position_valid == 0)
    {
        positions.current = new_position;
        softPwmWrite(pin_number, new_position);
    } else
    {
        // For now STDOUT is fine, but make a txt log.
        std::cout<< "A position outside safe limits was given."<< std::endl;
    }
}

void ServoDriver::config_pin(int pin_number_init)
{
    pin_number = pin_number_init;
    pinMode(pin_number, OUTPUT);
    digitalWrite(pin_number, LOW);
    softPwmCreate(pin_number, 0, range);
}

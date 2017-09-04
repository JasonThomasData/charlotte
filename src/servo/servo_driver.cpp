#include <softPwm.h>
#include <wiringPi.h>
#include <iostream>

#include "servo_driver.h"

ServoDriver::ServoDriver(int pin_number)
{
    range = 140; //Not application logic, this is a wiringPi setting. This works for the positions
    config_pin(pin_number);
}

void ServoDriver::config_pin(int pin_number_init)
{
    pin_number = pin_number_init;
    pinMode(pin_number, OUTPUT);
    digitalWrite(pin_number, LOW);
    softPwmCreate(pin_number, 0, range);
}

void ServoDriver::off()
{
    int off_signal = 0;
    softPwmWrite(pin_number, off_signal);
}

void ServoDriver::goto_0_degrees()
{
    int pwm_signal = 3;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_45_degrees()
{
    int pwm_signal = 8;
    softPwmWrite(pin_number, pwm_signal);
}

//Merge all of these into 8
void ServoDriver::goto_54_degrees()
{
    int pwm_signal = 9;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_90_degrees()
{
    int pwm_signal = 13;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_117_degrees()
{
    int pwm_signal = 16;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_126_degrees()
{
    int pwm_signal = 17;
    softPwmWrite(pin_number, pwm_signal);
}

//Make this 18
void ServoDriver::goto_135_degrees()
{
    int pwm_signal = 19;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_153_degrees()
{
    int pwm_signal = 20;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_180_degrees()
{
    int pwm_signal = 23;
    softPwmWrite(pin_number, pwm_signal);
}

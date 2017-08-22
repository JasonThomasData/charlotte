#include <softPwm.h>
#include <wiringPi.h>
#include <iostream>

#include "servo_driver.h"

ServoDriver::ServoDriver(int pin_number)
{
    range = 100; //Not application logic, this is a wiringPi setting. This works for the positions
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
    int pwm_signal = 2;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_49_degrees()
{
    int pwm_signal = 8;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_57_degrees()
{
    int pwm_signal = 9;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_90_degrees()
{
    int pwm_signal = 13;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_115_degrees()
{
    int pwm_signal = 16;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_123_degrees()
{
    int pwm_signal = 17;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_131_degrees()
{
    int pwm_signal = 19;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_148_degrees()
{
    int pwm_signal = 20;
    softPwmWrite(pin_number, pwm_signal);
}

void ServoDriver::goto_180_degrees()
{
    int pwm_signal = 24;
    softPwmWrite(pin_number, pwm_signal);
}

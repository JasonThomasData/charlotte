#include <wiringPi.h>
#include <iostream>
#include <unistd.h>

#include "../leg/leg_driver.h"
#include "../servo/servo_driver.h"

//main.cpp
int main(int argc, char* argv[])
{
    if (wiringPiSetup() < 0) return 1;

    int servo_0_pin = 0;
    int servo_1_pin = 1;
    int servo_2_pin = 2;

    LegDriver leg_0(servo_0_pin, servo_1_pin, servo_2_pin);

    return 0;
}

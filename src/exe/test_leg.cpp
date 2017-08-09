#include <wiringPi.h>
#include <iostream>
#include <unistd.h>

#include "../leg/leg_driver.h"
#include "../servo/servo_driver.h"

/* test_leg.cpp
 * This will do one full rotation, then set the servos to their extend_flat (bottom and middle
 * servos) and middle (top servos) positions.
 */

int main(int argc, char* argv[])
{
    if (wiringPiSetup() < 0) return 1;

    int servo_0_pin = 0;
    int servo_1_pin = 1;
    int servo_2_pin = 2;

    LegDriver leg_0(servo_0_pin, servo_1_pin, servo_2_pin);
    leg_0.up();
    usleep(1000000);
    leg_0.anti_clockwise();
    usleep(1000000);
    leg_0.down();
    usleep(1000000);
    leg_0.clockwise();
    usleep(1000000);
    leg_0.extend_flat();
    usleep(1000000);
    leg_0.middle();
    usleep(1000000);
    return 0;
}

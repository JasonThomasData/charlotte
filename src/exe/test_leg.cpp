#include <memory>
#include <wiringPi.h>
#include <iostream>
#include <unistd.h>

#include "../leg/leg_driver_02.h"
#include "../servo/i_servo_driver.h"
#include "../servo/servo_driver.h"

/* test_leg.cpp
 * This will do one full rotation, then set the servos to their extend_flat (bottom and middle
 * servos) and middle (top servos) positions.
 */

int main(int argc, char* argv[])
{
    if (wiringPiSetup() < 0) return 1;

    std::unique_ptr<IServoDriver> servo_0 = std::make_unique<ServoDriver>(0);
    std::unique_ptr<IServoDriver> servo_1 = std::make_unique<ServoDriver>(1);
    std::unique_ptr<IServoDriver> servo_2 = std::make_unique<ServoDriver>(2);

    LegDriver_02 leg_0(std::move(servo_0),
                       std::move(servo_1),
                       std::move(servo_2));

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

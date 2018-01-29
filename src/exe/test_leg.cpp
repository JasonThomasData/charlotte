#include <memory>
#include <wiringPi.h>
#include <unistd.h>

#include "../servo/i_servo_driver.h"
#include "../servo/servo_driver.h"
#include "../leg/i_leg_driver.h"
#include "../leg/leg_driver_02.h"

#include "../builder/builder.h"

/* test_leg.cpp
 * This will do one full rotation, then set the servos to their extend_flat (bottom and middle
 * servos) and middle (top servos) positions.
 */

int main(int argc, char* argv[])
{
    if (wiringPiSetup() < 0) return 1;

    IServoDriver* servo_0 = new ServoDriver(0);
    IServoDriver* servo_1 = new ServoDriver(1);
    IServoDriver* servo_2 = new ServoDriver(2);

    ILegDriver* leg_0 = new LegDriver_02(servo_0, servo_1, servo_2);

    leg_0->up();
    usleep(1000000);
    leg_0->anti_clockwise();
    usleep(1000000);
    leg_0->down();
    usleep(1000000);
    leg_0->clockwise();
    usleep(1000000);
    leg_0->extend_flat();
    usleep(1000000);
    leg_0->middle();
    usleep(1000000);

    return 0;
}

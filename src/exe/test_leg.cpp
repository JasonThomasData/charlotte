#include <memory>
#include <wiringPi.h>
#include <unistd.h>

#include <sstream>
#include <string>
#include <stdexcept>

#include "../servo/i_servo_driver.h"
#include "../servo/servo_driver.h"
#include "../leg/i_leg_driver.h"
#include "../leg/leg_driver_02.h"
#include "../leg/leg_driver_13.h"

#include "../builder/builder.h"

/* test_leg.cpp
 * This will do one full rotation, then set the servos to their extend_flat (bottom and middle
 * servos) and middle (top servos) positions.
 */

int main(int argc, char* argv[])
{
    if (wiringPiSetup() < 0) return 1;

    if (argc < 2)
    {
        std::string message = "You should pass a leg number to test, like `./bin/test_leg 0`";
        throw std::invalid_argument(message);
    }

    std::istringstream ss(argv[1]);
    int leg_number;
    ss >> leg_number;

    IServoDriver* bottom_servo;
    IServoDriver* middle_servo;
    IServoDriver* top_servo;
    ILegDriver* leg;

    if (leg_number == 0)
    {
        bottom_servo = new ServoDriver(0);
        middle_servo = new ServoDriver(1);
        top_servo = new ServoDriver(2);
        leg = new LegDriver_02(bottom_servo, middle_servo, top_servo);
    }
    else if (leg_number == 1)
    {
        bottom_servo = new ServoDriver(3);
        middle_servo = new ServoDriver(4);
        top_servo = new ServoDriver(5);
        leg = new LegDriver_13(bottom_servo, middle_servo, top_servo);
    }
    else if (leg_number == 2)
    {
        bottom_servo = new ServoDriver(6);
        middle_servo = new ServoDriver(7);
        top_servo = new ServoDriver(8);
        leg = new LegDriver_02(bottom_servo, middle_servo, top_servo);
    }
    else if (leg_number == 3)
    {
        bottom_servo = new ServoDriver(9);
        middle_servo = new ServoDriver(10);
        top_servo = new ServoDriver(11);
        leg = new LegDriver_13(bottom_servo, middle_servo, top_servo);
    }
    else
    {
        std::string message = "You should enter a leg number 0-3, like `./bin/test_leg 2`";
        throw std::invalid_argument(message);
    }

    leg->up();
    usleep(1000000);
    leg->anti_clockwise();
    usleep(1000000);
    leg->down();
    usleep(1000000);
    leg->clockwise();
    usleep(1000000);
    leg->extend_flat();
    usleep(1000000);
    leg->middle();
    usleep(1000000);

    return 0;
}

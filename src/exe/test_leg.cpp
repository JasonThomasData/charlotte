#include <memory>
#include <wiringPi.h>
#include <unistd.h>

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

    ILegDriver* leg_0 = Builder::build_leg<LegDriver_02>(0, 1, 2);

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

#include <wiringPi.h>
#include <unistd.h>

#include "../servo/servo_driver.h"

/* test_servo.cpp
 * This test will go to the maximum, then the minimum, then to the middle.
 */

int main(int argc, char* argv[])
{
    if (wiringPiSetup() < 0) return 1;

    int servo_pin = 0;
    ServoDriver servo(servo_pin);

    int min_position = 1;
    int mid_position = 12;
    int max_position = 23;

    servo.change_position(min_position);
    usleep(1000000);
    servo.change_position(max_position);
    usleep(1000000);
    servo.change_position(mid_position);
    usleep(1000000);

    return 0;
}

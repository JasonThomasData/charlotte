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

    servo.goto_0_degrees();
    usleep(1000000);
    servo.goto_180_degrees();
    usleep(1000000);
    servo.goto_90_degrees();
    usleep(1000000);

    return 0;
}

#include <memory>

#include "../leg/i_leg_driver.h"
#include "../servo/i_servo_driver.h"
#include "../servo/servo_driver.h"
#include "../robot/robot.h"

namespace Builder
{
    template <class T>
    ILegDriver& build_leg(int pin_0, int pin_1, int pin_2)
    {
        IServoDriver servo_0 = new ServoDriver(pin_0);
        IServoDriver servo_1 = new ServoDriver(pin_1);
        IServoDriver servo_2 = new ServoDriver(pin_2);

        ILegDriver leg = new T(servo_0, servo_1, servo_2);

        return leg;
    }
    Robot build_robot();
}

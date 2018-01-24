#include <memory>

#include "../leg/i_leg_driver.h"
#include "../servo/i_servo_driver.h"
#include "../servo/servo_driver.h"
#include "../robot/robot.h"

namespace Builder
{
    template <class T>
    std::unique_ptr<ILegDriver> build_leg(int pin_0, int pin_1, int pin_2)
    {
        std::unique_ptr<IServoDriver> servo_0 = std::make_unique<ServoDriver>(pin_0);
        std::unique_ptr<IServoDriver> servo_1 = std::make_unique<ServoDriver>(pin_1);
        std::unique_ptr<IServoDriver> servo_2 = std::make_unique<ServoDriver>(pin_2);

        std::unique_ptr<ILegDriver> leg = std::make_unique<T>(std::move(servo_0),
                                                              std::move(servo_1),
                                                              std::move(servo_2));

        return leg;
    }
    Robot build_robot();
}

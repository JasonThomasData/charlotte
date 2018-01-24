#include <memory>

#include "../leg/i_leg_driver.h"
#include "../leg/leg_driver_02.h"
#include "../leg/leg_driver_13.h"
#include "../servo/i_servo_driver.h"
#include "../servo/servo_driver.h"
#include "../charlotte/charlotte.h"

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

    /*
    Charlotte build_charlotte()
    {
        std::unique_ptr<ILegDriver> leg_0 = build_leg<LegDriver_02>(0, 1, 2);
        std::unique_ptr<ILegDriver> leg_1 = build_leg<LegDriver_13>(3, 4, 5);
        std::unique_ptr<ILegDriver> leg_2 = build_leg<LegDriver_02>(6, 7, 8);
        std::unique_ptr<ILegDriver> leg_3 = build_leg<LegDriver_13>(9, 10, 11);

        Charlotte charlotte = Charlotte(std::move(leg_0),
                                        std::move(leg_1),
                                        std::move(leg_2),
                                        std::move(leg_3));

        return charlotte;
    }
    */
}

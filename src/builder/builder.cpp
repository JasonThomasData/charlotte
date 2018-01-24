#include <memory> 

#include "builder.h"
#include "../leg/i_leg_driver.h"
#include "../leg/leg_driver_02.h"
#include "../leg/leg_driver_13.h"
#include "../robot/robot.h"

Robot Builder::build_robot()
{
    std::unique_ptr<ILegDriver> leg_0 = build_leg<LegDriver_02>(0, 1, 2);
    std::unique_ptr<ILegDriver> leg_1 = build_leg<LegDriver_13>(3, 4, 5);
    std::unique_ptr<ILegDriver> leg_2 = build_leg<LegDriver_02>(6, 7, 8);
    std::unique_ptr<ILegDriver> leg_3 = build_leg<LegDriver_13>(9, 10, 11);

    Robot robot = Robot(std::move(leg_0),
                        std::move(leg_1),
                        std::move(leg_2),
                        std::move(leg_3));

    return robot;
}

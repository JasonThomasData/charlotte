#include <memory> 

#include "builder.h"
#include "../leg/i_leg_driver.h"
#include "../leg/leg_driver_02.h"
#include "../leg/leg_driver_13.h"
#include "../robot/robot.h"

Robot& Builder::build_robot()
{
    ILegDriver& leg_0 = Builder::build_leg<LegDriver_02>(0, 1, 2);
    ILegDriver& leg_1 = Builder::build_leg<LegDriver_13>(3, 4, 5);
    ILegDriver& leg_2 = Builder::build_leg<LegDriver_02>(6, 7, 8);
    ILegDriver& leg_3 = Builder::build_leg<LegDriver_13>(9, 10, 11);

    Robot robot = new Robot(leg_0, leg_1, leg_2, leg_3);

    return robot;
}

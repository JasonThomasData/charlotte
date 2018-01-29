#include <memory> 

#include "../../lib/catch.hpp"
#include "../../lib/fakeit.hpp"

#include "../../src/leg/i_leg_driver.h"
#include "../../src/robot/robot.h"

using namespace fakeit;

Mock<ILegDriver> leg_helper()
{
    Mock<ILegDriver> leg;

    When(Method(leg, up)).AlwaysReturn();
    When(Method(leg, down)).AlwaysReturn();
    When(Method(leg, extend_flat)).AlwaysReturn();
    When(Method(leg, clockwise)).AlwaysReturn();
    When(Method(leg, middle)).AlwaysReturn();
    When(Method(leg, anti_clockwise)).AlwaysReturn();

    return leg;
}

TEST_CASE("Robot - walk forward")
{

    Mock<ILegDriver> leg_0 = leg_helper();
    Mock<ILegDriver> leg_1 = leg_helper();
    Mock<ILegDriver> leg_2 = leg_helper();
    Mock<ILegDriver> leg_3 = leg_helper();

    ILegDriver* leg_0_ptr = &leg_0.get();
    ILegDriver* leg_1_ptr = &leg_1.get();
    ILegDriver* leg_2_ptr = &leg_2.get();
    ILegDriver* leg_3_ptr = &leg_3.get();

    int action_duration = 0;

    Robot robot = Robot(leg_0_ptr, leg_1_ptr, leg_2_ptr, leg_3_ptr, action_duration);

    robot.walk_forward();

    Verify(
            Method(leg_0, up) +
            Method(leg_2, up) +

            Method(leg_0, anti_clockwise) +
            Method(leg_1, clockwise) +
            Method(leg_2, clockwise) +
            Method(leg_3, anti_clockwise) +

            Method(leg_0, down) +
            Method(leg_1, up) +
            Method(leg_2, down) +
            Method(leg_3, up) +

            Method(leg_0, clockwise) +
            Method(leg_1, anti_clockwise) +
            Method(leg_2, anti_clockwise) +
            Method(leg_3, clockwise) +

            Method(leg_0, up) +
            Method(leg_1, down) +
            Method(leg_2, up) +
            Method(leg_3, down) +

            Method(leg_0, middle) +
            Method(leg_1, middle) +
            Method(leg_2, middle) +
            Method(leg_3, middle) +

            Method(leg_0, down) +
            Method(leg_2, down)
           );
}


#include <memory> 

#include "../../lib/catch.hpp"
#include "../../lib/fakeit.hpp"

#include "../../src/leg/i_leg_driver.h"
#include "../../src/sleep/i_sleep.h"
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

Mock<ISleep> sleep_helper()
{
    Mock<ISleep> sleep;

    When(Method(sleep, full_move_duration)).AlwaysReturn();

    return sleep;
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

    Mock<ISleep> sleep = sleep_helper();
    ISleep* sleep_ptr = &sleep.get();

    Robot robot = Robot(leg_0_ptr, leg_1_ptr, leg_2_ptr, leg_3_ptr, sleep_ptr);

    robot.walk_forward();

    Verify(
            Method(leg_0, up) +
            Method(leg_2, up) +

            Method(sleep, full_move_duration) +

            Method(leg_0, anti_clockwise) +
            Method(leg_1, clockwise) +
            Method(leg_2, clockwise) +
            Method(leg_3, anti_clockwise) +

            Method(sleep, full_move_duration) +

            Method(leg_0, down) +
            Method(leg_1, up) +
            Method(leg_2, down) +
            Method(leg_3, up) +

            Method(sleep, full_move_duration) +

            Method(leg_0, clockwise) +
            Method(leg_1, anti_clockwise) +
            Method(leg_2, anti_clockwise) +
            Method(leg_3, clockwise) +

            Method(sleep, full_move_duration) +

            Method(leg_0, up) +
            Method(leg_1, down) +
            Method(leg_2, up) +
            Method(leg_3, down) +

            Method(sleep, full_move_duration) +

            Method(leg_0, middle) +
            Method(leg_1, middle) +
            Method(leg_2, middle) +
            Method(leg_3, middle) +

            Method(sleep, full_move_duration) +

            Method(leg_0, down) +
            Method(leg_2, down)
           );
}


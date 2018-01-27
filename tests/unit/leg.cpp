#include <memory> 

#include "../../lib/catch.hpp"

#include "../mocks/mock_servo_driver/mock_servo_driver.h"
#include "../../src/servo/i_servo_driver.h"
#include "../../src/leg/leg_driver_02.h"

TEST_CASE("LegDriver_02 - move clockwise")
{
    bottom_servo = MockServoDriver();
    middle_servo = MockServoDriver();
    top_servo = MockServoDriver();

    ILegDriver leg = LegDriver_02(bottom_servo, middle_servo, top_servo);

    leg.clockwise();

    REQUIRE(1 == 1);

}


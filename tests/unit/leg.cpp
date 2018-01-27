#include <memory> 

#include "../../lib/catch.hpp"

#include "../mocks/mock_servo_driver/mock_servo_driver.h"
#include "../../src/servo/i_servo_driver.h"
#include "../../src/leg/leg_driver_02.h"

TEST_CASE("LegDriver_02 - move clockwise")
{
    std::unique_ptr<IServoDriver> bottom_servo = std::make_unique<MockServoDriver>();
    std::unique_ptr<IServoDriver> middle_servo = std::make_unique<MockServoDriver>();
    std::unique_ptr<IServoDriver> top_servo = std::make_unique<MockServoDriver>();

    std::unique_ptr<ILegDriver> leg = std::make_unique<LegDriver_02>(std::move(bottom_servo),
                                                                     std::move(middle_servo),
                                                                     std::move(top_servo));

    leg->clockwise();

    REQUIRE(bottom_servo->get_test_result() == "off");
    REQUIRE(middle_servo->get_test_result() == "off");
    REQUIRE(top_servo->get_test_result() == "goto_27_degrees");
}



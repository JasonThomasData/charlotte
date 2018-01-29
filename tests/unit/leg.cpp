#include <memory> 

#include "../../lib/catch.hpp"
#include "../../lib/fakeit.hpp"

#include "../../src/servo/i_servo_driver.h"
#include "../../src/leg/leg_driver_02.h"
#include "../../src/leg/leg_driver_13.h"

using namespace fakeit;

Mock<IServoDriver> servo_helper()
{
    Mock<IServoDriver> servo;

    When(Method(servo, off)).AlwaysReturn();
    When(Method(servo, goto_0_degrees)).AlwaysReturn();
    When(Method(servo, goto_27_degrees)).AlwaysReturn();
    When(Method(servo, goto_45_degrees)).AlwaysReturn();
    When(Method(servo, goto_54_degrees)).AlwaysReturn();
    When(Method(servo, goto_63_degrees)).AlwaysReturn();
    When(Method(servo, goto_90_degrees)).AlwaysReturn();
    When(Method(servo, goto_117_degrees)).AlwaysReturn();
    When(Method(servo, goto_126_degrees)).AlwaysReturn();
    When(Method(servo, goto_135_degrees)).AlwaysReturn();
    When(Method(servo, goto_153_degrees)).AlwaysReturn();
    When(Method(servo, goto_180_degrees)).AlwaysReturn();

    return servo;
}

TEST_CASE("LegDriver_02 - move up")
{

    Mock<IServoDriver> bottom_servo = servo_helper();
    Mock<IServoDriver> middle_servo = servo_helper();
    Mock<IServoDriver> top_servo = servo_helper();

    IServoDriver* bottom_servo_ptr = &bottom_servo.get();
    IServoDriver* middle_servo_ptr = &middle_servo.get();
    IServoDriver* top_servo_ptr = &top_servo.get();

    ILegDriver* leg = new LegDriver_02(bottom_servo_ptr, middle_servo_ptr, top_servo_ptr);

    leg->up();

    Verify(Method(bottom_servo, goto_27_degrees));
    Verify(Method(middle_servo, goto_27_degrees));
    Verify(Method(top_servo, off));
}

TEST_CASE("LegDriver_02 - move down")
{

    Mock<IServoDriver> bottom_servo = servo_helper();
    Mock<IServoDriver> middle_servo = servo_helper();
    Mock<IServoDriver> top_servo = servo_helper();

    IServoDriver* bottom_servo_ptr = &bottom_servo.get();
    IServoDriver* middle_servo_ptr = &middle_servo.get();
    IServoDriver* top_servo_ptr = &top_servo.get();

    ILegDriver* leg = new LegDriver_02(bottom_servo_ptr, middle_servo_ptr, top_servo_ptr);

    leg->down();

    Verify(Method(bottom_servo, goto_90_degrees));
    Verify(Method(middle_servo, goto_135_degrees));
    Verify(Method(top_servo, off));
}

TEST_CASE("LegDriver_02 - move extend_flat")
{

    Mock<IServoDriver> bottom_servo = servo_helper();
    Mock<IServoDriver> middle_servo = servo_helper();
    Mock<IServoDriver> top_servo = servo_helper();

    IServoDriver* bottom_servo_ptr = &bottom_servo.get();
    IServoDriver* middle_servo_ptr = &middle_servo.get();
    IServoDriver* top_servo_ptr = &top_servo.get();

    ILegDriver* leg = new LegDriver_02(bottom_servo_ptr, middle_servo_ptr, top_servo_ptr);

    leg->extend_flat();

    Verify(Method(bottom_servo, goto_135_degrees));
    Verify(Method(middle_servo, goto_90_degrees));
    Verify(Method(top_servo, off));
}

TEST_CASE("LegDriver_02 - move clockwise")
{
    //Logic same for LegDriver_13

    Mock<IServoDriver> bottom_servo = servo_helper();
    Mock<IServoDriver> middle_servo = servo_helper();
    Mock<IServoDriver> top_servo = servo_helper();

    IServoDriver* bottom_servo_ptr = &bottom_servo.get();
    IServoDriver* middle_servo_ptr = &middle_servo.get();
    IServoDriver* top_servo_ptr = &top_servo.get();

    ILegDriver* leg = new LegDriver_02(bottom_servo_ptr, middle_servo_ptr, top_servo_ptr);

    leg->clockwise();

    Verify(Method(bottom_servo, off));
    Verify(Method(middle_servo, off));
    Verify(Method(top_servo, goto_126_degrees));
}

TEST_CASE("LegDriver_02 - move middle")
{
    //Logic same for LegDriver_13

    Mock<IServoDriver> bottom_servo = servo_helper();
    Mock<IServoDriver> middle_servo = servo_helper();
    Mock<IServoDriver> top_servo = servo_helper();

    IServoDriver* bottom_servo_ptr = &bottom_servo.get();
    IServoDriver* middle_servo_ptr = &middle_servo.get();
    IServoDriver* top_servo_ptr = &top_servo.get();

    ILegDriver* leg = new LegDriver_02(bottom_servo_ptr, middle_servo_ptr, top_servo_ptr);

    leg->middle();

    Verify(Method(bottom_servo, off));
    Verify(Method(middle_servo, off));
    Verify(Method(top_servo, goto_90_degrees));
}

TEST_CASE("LegDriver_02 - move anti-clockwise")
{
    //Logic same for LegDriver_13

    Mock<IServoDriver> bottom_servo = servo_helper();
    Mock<IServoDriver> middle_servo = servo_helper();
    Mock<IServoDriver> top_servo = servo_helper();

    IServoDriver* bottom_servo_ptr = &bottom_servo.get();
    IServoDriver* middle_servo_ptr = &middle_servo.get();
    IServoDriver* top_servo_ptr = &top_servo.get();

    ILegDriver* leg = new LegDriver_02(bottom_servo_ptr, middle_servo_ptr, top_servo_ptr);

    leg->anti_clockwise();

    Verify(Method(bottom_servo, off));
    Verify(Method(middle_servo, off));
    Verify(Method(top_servo, goto_54_degrees));
}

TEST_CASE("LegDriver_13 - move up")
{

    Mock<IServoDriver> bottom_servo = servo_helper();
    Mock<IServoDriver> middle_servo = servo_helper();
    Mock<IServoDriver> top_servo = servo_helper();

    IServoDriver* bottom_servo_ptr = &bottom_servo.get();
    IServoDriver* middle_servo_ptr = &middle_servo.get();
    IServoDriver* top_servo_ptr = &top_servo.get();

    ILegDriver* leg = new LegDriver_13(bottom_servo_ptr, middle_servo_ptr, top_servo_ptr);

    leg->up();

    Verify(Method(bottom_servo, goto_153_degrees));
    Verify(Method(middle_servo, goto_153_degrees));
    Verify(Method(top_servo, off));
}

TEST_CASE("LegDriver_13 - move down")
{

    Mock<IServoDriver> bottom_servo = servo_helper();
    Mock<IServoDriver> middle_servo = servo_helper();
    Mock<IServoDriver> top_servo = servo_helper();

    IServoDriver* bottom_servo_ptr = &bottom_servo.get();
    IServoDriver* middle_servo_ptr = &middle_servo.get();
    IServoDriver* top_servo_ptr = &top_servo.get();

    ILegDriver* leg = new LegDriver_13(bottom_servo_ptr, middle_servo_ptr, top_servo_ptr);

    leg->down();

    Verify(Method(bottom_servo, goto_90_degrees));
    Verify(Method(middle_servo, goto_45_degrees));
    Verify(Method(top_servo, off));
}

TEST_CASE("LegDriver_13 - move extend_flat")
{

    Mock<IServoDriver> bottom_servo = servo_helper();
    Mock<IServoDriver> middle_servo = servo_helper();
    Mock<IServoDriver> top_servo = servo_helper();

    IServoDriver* bottom_servo_ptr = &bottom_servo.get();
    IServoDriver* middle_servo_ptr = &middle_servo.get();
    IServoDriver* top_servo_ptr = &top_servo.get();

    ILegDriver* leg = new LegDriver_13(bottom_servo_ptr, middle_servo_ptr, top_servo_ptr);

    leg->extend_flat();

    Verify(Method(bottom_servo, goto_45_degrees));
    Verify(Method(middle_servo, goto_90_degrees));
    Verify(Method(top_servo, off));
}

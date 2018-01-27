#include <string> 

#include "mock_servo_driver.h"

MockServoDriver::MockServoDriver(){}

void MockServoDriver::off()
{
    test_result = "off";
}

void MockServoDriver::goto_0_degrees()
{
    test_result = "goto_0_degrees";
}
void MockServoDriver::goto_27_degrees()
{
    test_result = "goto_27_degrees";
}

void MockServoDriver::goto_45_degrees()
{
    test_result = "goto_45_degrees";
}

void MockServoDriver::goto_54_degrees()
{
    test_result = "goto_54_degrees";
}

void MockServoDriver::goto_63_degrees()
{
    test_result = "goto_63_degrees";
}

void MockServoDriver::goto_90_degrees()
{
    test_result = "goto_90_degrees";
}

void MockServoDriver::goto_117_degrees()
{
    test_result = "goto_117_degrees";
}

void MockServoDriver::goto_126_degrees()
{
    test_result = "goto_126_degrees";
}

void MockServoDriver::goto_135_degrees()
{
    test_result = "goto_135_degrees";
}

void MockServoDriver::goto_153_degrees()
{
    test_result = "goto_153_degrees";
}

void MockServoDriver::goto_180_degrees()
{
    test_result = "goto_180_degrees";
}

std::string MockServoDriver::get_test_result()
{
    return test_result;
}

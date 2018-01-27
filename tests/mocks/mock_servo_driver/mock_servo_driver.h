#ifndef MockServoDriver_h
#define MockServoDriver_h

#include <string>

#include "../../../src/servo/i_servo_driver.h"

class MockServoDriver : public IServoDriver
{
    public:
        std::string test_result;
        MockServoDriver();
        void off() override;
        void goto_0_degrees() override;
        void goto_27_degrees() override;
        void goto_45_degrees() override;
        void goto_54_degrees() override;
        void goto_63_degrees() override;
        void goto_90_degrees() override;
        void goto_117_degrees() override;
        void goto_126_degrees() override;
        void goto_135_degrees() override;
        void goto_153_degrees() override;
        void goto_180_degrees() override;
        std::string get_test_result() override;
};

#endif

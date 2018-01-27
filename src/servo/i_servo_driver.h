#ifndef IServoDriver_h
#define IServoDriver_h

#include <string>

class IServoDriver
{
    public:
        virtual void off() = 0;
        virtual void goto_0_degrees() = 0;
        virtual void goto_27_degrees() = 0;
        virtual void goto_45_degrees() = 0;
        virtual void goto_54_degrees() = 0;
        virtual void goto_63_degrees() = 0;
        virtual void goto_90_degrees() = 0;
        virtual void goto_117_degrees() = 0;
        virtual void goto_126_degrees() = 0;
        virtual void goto_135_degrees() = 0;
        virtual void goto_153_degrees() = 0;
        virtual void goto_180_degrees() = 0;
        virtual std::string get_test_result() = 0;
};

#endif

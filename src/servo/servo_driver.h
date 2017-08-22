#ifndef ServoDriver_h
#define ServoDriver_h

/* The sg90 servo motors work best with 3.3 volts, and positions between 2 and 24. See the
 * positions.h. The best middle position seems to be 13 (2+11=13+11=24).
 */

#include "i_servo_driver.h"

class ServoDriver : public IServoDriver
{
    private:
        int pin_number;
        int range; //Not part of application logic, see wiringPi documentation.
        void config_pin(int pin_number);
    public:
        ServoDriver(int pin_number);
        void off() override;
        void goto_0_degrees() override;
        void goto_45_degrees() override;
        void goto_54_degrees() override;
        void goto_90_degrees() override;
        void goto_117_degrees() override;
        void goto_126_degrees() override;
        void goto_135_degrees() override;
        void goto_153_degrees() override;
        void goto_180_degrees() override;
};

#endif

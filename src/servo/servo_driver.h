#ifndef ServoDriver_h
#define ServoDriver_h

/* The sg90 servo motors work best with 3.3 volts, and positions between 2 and 24. See the
 * positions.h. The best middle position seems to be 13 (2+11=13+11=24).
 */

#include "positions.h"
#include "i_servo_driver.h"

class ServoDriver : public IServoDriver
{
    private:
        Positions positions;
        int pin_number;
        int range; //Not part of application logic, see wiringPi documentation.
        void config_pin(int pin_number);
        int check_new_position(int new_position);
    public:
        ServoDriver(int pin_number);
        void change_position(int new_position) override;
};

#endif

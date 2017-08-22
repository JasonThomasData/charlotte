#ifndef LegDriver_h
#define LegDriver_h

#include "i_leg_driver.h"
#include "../servo/servo_driver.h"

class LegDriver : public ILegDriver
{
    private:
        ServoDriver bottom_servo;
        ServoDriver middle_servo;
        ServoDriver top_servo;
    public:
        LegDriver(int bottom_pin, int middle_pin, int top_pin);
        void clockwise() override;
        void middle() override;
        void anti_clockwise() override;
        void up() override;
        void down() override;
        void extend_flat() override;
        void rest() override;
};

#endif

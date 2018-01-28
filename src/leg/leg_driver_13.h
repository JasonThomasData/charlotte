#ifndef LegDriver_13_h
#define LegDriver_13_h

#include <memory>

#include "../servo/i_servo_driver.h"

#include "i_leg_driver.h"

class LegDriver_13 : public ILegDriver
{
    private:
        IServoDriver* bottom_servo;
        IServoDriver* middle_servo;
        IServoDriver* top_servo;
    public:
        LegDriver_13(IServoDriver* bottom_to_add,
                     IServoDriver* middle_to_add,
                     IServoDriver* top_to_add);
        void up() override;
        void down() override;
        void extend_flat() override;
        void clockwise() override;
        void middle() override;
        void anti_clockwise() override;
};

#endif

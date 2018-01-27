#ifndef LegDriver_02_h
#define LegDriver_02_h

#include <memory>

#include "../servo/i_servo_driver.h"

#include "i_leg_driver.h"

// NOTE - To save future confusion, this is the prototype leg.

class LegDriver_02 : public ILegDriver
{
    private:
        IServoDriver& bottom_servo;
        IServoDriver& middle_servo;
        IServoDriver& top_servo;
    public:
        LegDriver_02(IServoDriver& bottom_to_add,
                     IServoDriver& middle_to_add,
                     IServoDriver& top_to_add);
        void up() override;
        void down() override;
        void extend_flat() override;
        void clockwise() override;
        void middle() override;
        void anti_clockwise() override;
};
    
#endif

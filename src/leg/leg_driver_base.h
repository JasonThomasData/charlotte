#ifndef LegDriverBase_h
#define LegDriverBase_h

#include <memory>

#include "i_leg_driver.h"
#include "../servo/i_servo_driver.h"

/* The base class handles horizontal movements, which are the same for every leg. 
 */

class LegDriverBase : public ILegDriver
{
    protected:
        IServoDriver* bottom_servo;
        IServoDriver* middle_servo;
        IServoDriver* top_servo;
    public:
        void clockwise() override;
        void middle() override;
        void anti_clockwise() override;
};

#endif

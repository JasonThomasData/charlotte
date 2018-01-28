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
        std::unique_ptr<IServoDriver> bottom_servo;
        std::unique_ptr<IServoDriver> middle_servo;
        std::unique_ptr<IServoDriver> top_servo;
    public:
        void clockwise() override;
        void middle() override;
        void anti_clockwise() override;
};

#endif

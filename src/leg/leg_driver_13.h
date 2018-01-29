#ifndef LegDriver_13_h
#define LegDriver_13_h

#include <memory>

#include "i_leg_driver.h"
#include "leg_driver_base.h"

class LegDriver_13 : public LegDriverBase
{
    public:
        LegDriver_13(IServoDriver* bottom_to_add,
                     IServoDriver* middle_to_add,
                     IServoDriver* top_to_add);
        void up() override;
        void down() override;
        void extend_flat() override;
};

#endif

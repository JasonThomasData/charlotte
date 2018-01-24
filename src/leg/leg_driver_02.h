#ifndef LegDriver_02_h
#define LegDriver_02_h

#include <memory>

#include "leg_driver_base.h"

// NOTE - To save future confusion, this is the prototype leg.

class LegDriver_02 : public LegDriverBase
{
    public:
        LegDriver_02(std::unique_ptr<IServoDriver> bottom_to_add,
                     std::unique_ptr<IServoDriver> middle_to_add,
                     std::unique_ptr<IServoDriver> top_to_add);
        void up() override;
        void down() override;
        void extend_flat() override;
};
    
#endif

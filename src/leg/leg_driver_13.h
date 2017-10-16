#ifndef LegDriver_13_h
#define LegDriver_13_h

#include <memory>

#include "leg_driver_base.h"

class LegDriver_13 : public LegDriverBase
{
    public:
        LegDriver_13(std::unique_ptr<IServoDriver> bottom_to_add,
                     std::unique_ptr<IServoDriver> middle_to_add,
                     std::unique_ptr<IServoDriver> top_to_add);
        void up() override;
        void down() override;
        void extend_flat() override;
        void rest() override;
};

#endif

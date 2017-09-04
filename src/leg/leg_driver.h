#ifndef LegDriver_h
#define LegDriver_h

#include <memory>

#include "i_leg_driver.h"
#include "../servo/servo_driver.h"
#include "../servo/i_servo_driver.h"

class LegDriver : public ILegDriver
{
    private:
        std::unique_ptr<IServoDriver> bottom_servo;
        std::unique_ptr<IServoDriver> middle_servo;
        std::unique_ptr<IServoDriver> top_servo;
    public:
        LegDriver(std::unique_ptr<IServoDriver> bottom_to_add,
                  std::unique_ptr<IServoDriver> middle_to_add,
                  std::unique_ptr<IServoDriver> top_to_add);
        void clockwise() override;
        void middle() override;
        void anti_clockwise() override;
        void up() override;
        void down() override;
        void extend_flat() override;
        void rest() override;
};

#endif

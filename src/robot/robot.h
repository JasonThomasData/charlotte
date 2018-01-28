#ifndef Robot_h
#define Robot_h

#include <memory>

#include "../leg/i_leg_driver.h" 

class Robot
{
    private:
        std::unique_ptr<ILegDriver> leg_0;
        std::unique_ptr<ILegDriver> leg_1;
        std::unique_ptr<ILegDriver> leg_2;
        std::unique_ptr<ILegDriver> leg_3;
    public:
        Robot(std::unique_ptr<ILegDriver> leg_0_to_add,
              std::unique_ptr<ILegDriver> leg_1_to_add,
              std::unique_ptr<ILegDriver> leg_2_to_add,
              std::unique_ptr<ILegDriver> leg_3_to_add);
        void walk_forward();
        //void walk_backward();
        //void turn_left();
        //void turn_right();
        //void stop();
};
    
#endif

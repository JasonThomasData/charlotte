#ifndef Robot_h
#define Robot_h

#include <memory>

#include "../leg/i_leg_driver.h" 

class Robot
{
    private:
        ILegDriver& leg_0;
        ILegDriver& leg_1;
        ILegDriver& leg_2;
        ILegDriver& leg_3;
    public:
        Robot(ILegDriver& leg_0_to_add, ILegDriver& leg_1_to_add,
              ILegDriver& leg_2_to_add, ILegDriver& leg_3_to_add);
        void walk_forward();
        //void walk_backward();
        //void turn_left();
        //void turn_right();
        //void stop();
};
    
#endif

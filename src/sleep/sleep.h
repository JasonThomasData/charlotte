#ifndef Sleep_h
#define Sleep_h

#include "i_sleep.h"

class Sleep : public ISleep
{
    private:
        int move_duration;
    public:
        Sleep(int move_duration);
        void full_move_duration() override;
};

#endif

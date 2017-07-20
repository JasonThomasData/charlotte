#ifndef IServoDriver_h
#define IServoDriver_h

class IServoDriver
{
    public:
        virtual void change_position(int new_position) = 0;
};

#endif

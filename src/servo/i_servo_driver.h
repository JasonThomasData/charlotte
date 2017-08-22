#ifndef IServoDriver_h
#define IServoDriver_h

class IServoDriver
{
    public:
        virtual void off() = 0;
        virtual void goto_0_degrees() = 0;
        virtual void goto_49_degrees() = 0;
        virtual void goto_57_degrees() = 0;
        virtual void goto_90_degrees() = 0;
        virtual void goto_115_degrees() = 0;
        virtual void goto_123_degrees() = 0;
        virtual void goto_131_degrees() = 0;
        virtual void goto_148_degrees() = 0;
        virtual void goto_180_degrees() = 0;
};

#endif

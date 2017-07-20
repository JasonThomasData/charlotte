#ifndef ILegDriver_h
#define ILegDriver_h

class ILegDriver
{
    public:
        virtual void clockwise() = 0;
        virtual void middle() = 0;
        virtual void anti_clockwise() = 0;
        virtual void up() = 0;
        virtual void down() = 0;
        virtual void extend_flat() = 0;
        virtual void rest() = 0;
};

#endif

#include <iostream>
#include <wiringPi.h>

#include "../builder/builder.h"
#include "../robot/robot.h"

int main()
{
    if (wiringPiSetup() < 0) return 1;
    std::cout<< "HELLO"<< std::endl; 
}

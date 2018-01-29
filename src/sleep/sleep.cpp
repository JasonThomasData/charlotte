#include <unistd.h>

#include "sleep.h"

Sleep::Sleep(int duration)
    :move_duration(duration){};

void Sleep::full_move_duration()
{
    usleep(move_duration);
}

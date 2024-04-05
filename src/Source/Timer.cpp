#include "../Header/Timer.h"


Timer::Timer(double interval) {
    last_update_time = 0;
    this->interval = interval;
}

bool Timer::EventTrigger() {
    current_time = GetTime();
    if (current_time - last_update_time >= interval) {
        last_update_time = current_time;
        return true;
    }
    return false;
}
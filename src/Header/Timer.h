#pragma once
#include "raylib.h"

class Timer {
    double last_update_time;
    double current_time;
    double interval;
public:
    Timer(double interval);

    bool EventTrigger();
};
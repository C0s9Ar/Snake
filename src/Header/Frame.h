#pragma once
#include "Util.h"

class Frame {
public:
    Color color;
    float thickness;

    Frame();
    Frame(Color color, int thickness);

    void Draw();
};


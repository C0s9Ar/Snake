#pragma once
#include "Util.h"

class Snake {
public:
    deque<Vector2> body;
    Color color;
    Vector2 direction;
    Vector2 move_direction;
    bool add_segment;
    deque<Vector2> start_body;

    Snake();
    void Draw();
    void Update();
    void Reset();
};

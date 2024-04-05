#pragma once
#include "Util.h"
class Food {
public:
    Vector2 pos;
    Color color;
    Texture2D texture;

    Food(deque<Vector2> snake_body);
    ~Food();
    void Draw();
    Vector2 GenerateRandomCell();
    Vector2 GenerateRandomPos(deque<Vector2> snake_body);
};


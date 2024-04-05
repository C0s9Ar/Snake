#pragma once
#include "raylib.h"
#include <string>
using std::string;

class Text {
public:
    Vector2 pos;
    Color color;
    int font_size;
    string text;

    Text();

    Text(Vector2 pos, Color color, int font_size, string text);

    void Draw();
};

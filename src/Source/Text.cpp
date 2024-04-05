#include "../Header/Text.h"

Text::Text() {}

Text::Text(Vector2 pos, Color color, int font_size, string text) {
    this->pos = pos;
    this->color = color;
    this->font_size = font_size;
    this->text = text;
}

void Text::Draw() {
    DrawText(text.c_str(), pos.x, pos.y, font_size, color);
}

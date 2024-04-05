#include "../Header/Frame.h"


Frame::Frame() {}

Frame::Frame(Color color, int thickness) {
    this->color = color;
    this->thickness = thickness;
}

void Frame::Draw() {
    DrawRectangleLinesEx(Rectangle{ OFFSET - thickness, OFFSET - thickness, CELL_SIZE * CELL_AMOUNT + thickness * 2.0f, CELL_SIZE * CELL_AMOUNT + thickness * 2.0f }, thickness, color);
}


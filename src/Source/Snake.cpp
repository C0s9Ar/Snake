#include "../Header/Snake.h"


Snake::Snake() {
    float screen_center = CELL_AMOUNT / 2.0f - 1;
    start_body = { {screen_center, screen_center - 1}, {screen_center, screen_center}, {screen_center, screen_center + 1} };
    body = start_body;
    color = gray_color;
    direction = { 0, -1 };
    move_direction = { 0, -1 };
    add_segment = false;
}

void Snake::Draw() {
    for (auto ele : body) {
        Rectangle segment = Rectangle{ OFFSET + ele.x * CELL_SIZE, OFFSET + ele.y * CELL_SIZE, (float)CELL_SIZE, (float)CELL_SIZE };
        DrawRectangleRounded(segment, 0.5, 10, color);
    }
}
void Snake::Update() {
    body.push_front(Vector2Add(body.front(), direction));
    move_direction = direction;
    if (add_segment)
        add_segment = false;
    else
        body.pop_back();
}
void Snake::Reset() {
    body = start_body;
    direction = { 0, -1 };
    move_direction = { 0, -1 };
}

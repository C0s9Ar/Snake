#include "../Header/Food.h"

Food::Food(deque<Vector2> snake_body) {
    Image img = LoadImage("res/food.png");
    texture = LoadTextureFromImage(img);
    UnloadImage(img);
    pos = GenerateRandomPos(snake_body);
    color = WHITE;
}

Food::~Food() { UnloadTexture(texture); }

void Food::Draw() { DrawTexture(texture, OFFSET + pos.x * CELL_SIZE, OFFSET + pos.y * CELL_SIZE, color); }

Vector2 Food::GenerateRandomCell() { return { (float)GetRandomValue(0, CELL_AMOUNT - 1) , (float)GetRandomValue(0, CELL_AMOUNT - 1) }; }

Vector2 Food::GenerateRandomPos(deque<Vector2> snake_body) {
    Vector2 new_pos = GenerateRandomCell();
    while (ElementInDeque(new_pos, snake_body)) 
        new_pos = GenerateRandomCell();
    return new_pos;
}


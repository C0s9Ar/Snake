#pragma once
#include "Util.h"
#include "Timer.h"
#include "Text.h"
#include "Frame.h"
#include "Snake.h"
#include "Food.h"

class Game {
public:
    Snake *snake;
    Food *food;
    Text text_title;
    Text text_score;
    Frame frame;
    bool pause;
    int score;

    Sound eat_sound;
    Sound hit_sound;

    Game();
    ~Game();

    void Draw();
    void Update();

    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();

    void GameOver();
    void Control();
};


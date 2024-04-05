#include "../Header/Game.h"

Game::Game() {
    snake = new Snake();
    food = new Food(snake->body);

    pause = false;
    score = 0;
    InitAudioDevice();
    eat_sound = LoadSound("res/eat.mp3");
    hit_sound = LoadSound("res/hit.mp3");

    text_title = Text(Vector2{ (float)OFFSET, (float)OFFSET - 29 }, gray_color, 30, "Snake");

    text_score = Text(Vector2{ (float)OFFSET, (float)CELL_SIZE * CELL_AMOUNT + OFFSET + 3 }, gray_color, 30, to_string(score));

    frame = Frame(gray_color, 5);

}
Game::~Game() {
        UnloadSound(eat_sound);
        UnloadSound(hit_sound);
    }

    void Game::Draw() {
        snake->Draw();
        food->Draw();
        text_title.Draw();
        text_score.Draw();
        frame.Draw();
    }
    void Game::Update() {
        if (!pause) {
            snake->Update();
            CheckCollisionWithFood();
            CheckCollisionWithEdges();
            CheckCollisionWithTail();
        }
    }

    void Game::CheckCollisionWithFood() {
        if (Vector2Equals(snake->body.front(), food->pos)) {
            food->pos = food->GenerateRandomPos(snake->body);
            snake->add_segment = true;
            score++;
            text_score.text = to_string(score);
            PlaySound(eat_sound);
        }
    }
    void Game::CheckCollisionWithEdges() {
        if (snake->body.front().x == CELL_AMOUNT || snake->body.front().x == -1)
            GameOver();
        if (snake->body.front().y == CELL_AMOUNT || snake->body.front().y == -1)
            GameOver();
    }
    void Game::CheckCollisionWithTail() {
        deque<Vector2> headless_body = snake->body;
        headless_body.pop_front();
        if (ElementInDeque(snake->body.front(), headless_body))
            GameOver();
    }

    void Game::GameOver() {
        snake->Reset();
        food->pos = food->GenerateRandomPos(snake->body);
        pause = true;
        score = 0;
        text_score.text = to_string(score);
        PlaySound(hit_sound);
    }

    void Game::Control() {
        if (IsKeyDown(KEY_UP) && snake->move_direction.y != 1) {
            snake->direction = { 0, -1 };
            pause = false;
        }
        if (IsKeyDown(KEY_DOWN) && snake->move_direction.y != -1) {
            snake->direction = { 0, 1 };
            pause = false;
        }
        if (IsKeyDown(KEY_LEFT) && snake->move_direction.x != 1) {
            snake->direction = { -1, 0 };
            pause = false;
        }
        if (IsKeyDown(KEY_RIGHT) && snake->move_direction.x != -1) {
            snake->direction = { 1, 0 };
            pause = false;
        }
    }

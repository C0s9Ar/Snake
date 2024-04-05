#include "../Header/Util.h"
#include "../Header/Game.h"

int main() {
    Color bg_color = Color{168, 202, 100, 255};
    double interval = 0.2;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(2 * OFFSET + CELL_SIZE * CELL_AMOUNT, 2 * OFFSET + CELL_SIZE * CELL_AMOUNT, title.c_str());
    SetWindowState(FLAG_VSYNC_HINT);

    Game game;
    Timer timer(interval);

    while (!WindowShouldClose()){
        if (timer.EventTrigger())
            game.Update();

        game.Control();

        BeginDrawing();
        ClearBackground(bg_color);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

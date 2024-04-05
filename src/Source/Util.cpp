#include "../Header/Util.h"

int CELL_SIZE = 30;
int CELL_AMOUNT = 20;
int OFFSET = 50;
string title = "Snake";
Color gray_color = Color{ 39, 47, 23, 255 };

bool ElementInDeque(Vector2 element, deque<Vector2> deque) {
    for (auto ele : deque)
        if (Vector2Equals(element, ele))
            return true;
    return false;
}
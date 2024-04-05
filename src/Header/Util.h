#pragma once
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <deque>
#include <string>

using namespace std;

extern int CELL_SIZE;
extern int CELL_AMOUNT;
extern int OFFSET;
extern string title;
extern Color gray_color;

bool ElementInDeque(Vector2 element, deque<Vector2> deque);

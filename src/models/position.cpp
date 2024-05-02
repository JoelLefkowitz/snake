#include "position.hpp"
#include "graphics.hpp"
#include <stdlib.h>

Position::Position(int x, int y) : x(x), y(y) {}

Position Position::random_position() {
    int x = rand() % SIZE;
    int y = rand() % SIZE;
    return {x, y};
}

bool Position::operator==(const Position &rhs) { return x == rhs.x && y == rhs.y; }

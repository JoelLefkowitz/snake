#include "position.hpp"
#include "../engine/graphics.hpp"
#include <cstdlib>
#include <random>

Position::Position(int x, int y) : x(x), y(y) {
}

Position Position::random_position() {
    int x = static_cast<int>(arc4random()) % SIZE;
    int y = static_cast<int>(arc4random()) % SIZE;
    return {x, y};
}

bool Position::operator==(const Position &rhs) const {
    return x == rhs.x && y == rhs.y;
}

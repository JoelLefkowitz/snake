#ifndef SNAKE_MODELS_POSITION_HPP
#define SNAKE_MODELS_POSITION_HPP

class Position {
  public:
    int x;
    int y;

    static Position random_position();

    Position(int x, int y);

    bool operator==(const Position &rhs);
};

#endif

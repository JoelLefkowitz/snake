#ifndef POSITION_H
#define POSITION_H

class Position {
  public:
    int x;
    int y;

    static Position random_position();

    Position(int x, int y);

    bool operator==(const Position &rhs);
};

#endif

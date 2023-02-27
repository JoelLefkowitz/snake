#ifndef STATE_H
#define STATE_H

#include "inputs.hpp"
#include <SDL2/SDL.h>
#include <vector>

struct Position {
    int x;
    int y;
};

enum Direction { UP, RIGHT, DOWN, LEFT };

Position random_position();

class GameState {
  private:
    void update_heading(const KeyEvents &keys);

    void update_head();
    void update_bean();
    void update_tail(const Position &prev_head);

    void check_game_over();

  public:
    Position              bean;
    Position              head;
    std::vector<Position> tail;

    Direction heading;

    bool over;
    int  score;

    GameState();
    void update(const KeyEvents &keys);
};

#endif
#ifndef SNAKE_ENGINE_STATE_HPP
#define SNAKE_ENGINE_STATE_HPP

#include "../models/position.hpp"
#include <vector>

struct KeyEvents;

enum Direction { UP, RIGHT, DOWN, LEFT };

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

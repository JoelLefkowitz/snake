#ifndef STATE_H
#define STATE_H

#include <vector>
#include <SDL2/SDL.h>
#include "inputs.hpp"

struct Position {
    int x;
    int y;
};


struct GameState {
    Position head;
    Position bean;
    std::vector<Position> tail;
    int heading;
    int score;
    bool game_over;
};

GameState init_state();
void update_state(GameState* game_state, KeyEvents keys);
void update_heading(GameState* game_state, KeyEvents keys);
void update_head(GameState* game_state);
void update_bean(GameState* game_state);
void update_tail(GameState* game_state, Position prev_head);
void check_game_over(GameState* game_state);

#endif
#ifndef STATE_H
#define STATE_H

#include <SDL2/SDL.h>
#include "inputs.hpp"

struct GameState {
    int head_x;
    int head_y;
    int bean_x;
    int bean_y;
    int heading;
};

GameState random_state();
void update_state(GameState* game_state, KeyEvents keys);

#endif
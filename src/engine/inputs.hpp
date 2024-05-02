#ifndef SNAKE_ENGINE_INPUTS_HPP
#define SNAKE_ENGINE_INPUTS_HPP

#include "SDL2/SDL_events.h"

struct KeyEvents {
    bool up;
    bool right;
    bool down;
    bool left;
};

KeyEvents keys(const SDL_Event &event);

#endif

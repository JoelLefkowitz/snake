#include "inputs.hpp"

KeyEvents keys(const SDL_Event &event) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    KeyEvents events;
    events.up    = state[SDL_SCANCODE_UP];
    events.right = state[SDL_SCANCODE_RIGHT];
    events.down  = state[SDL_SCANCODE_DOWN];
    events.left  = state[SDL_SCANCODE_LEFT];

    return events;
}

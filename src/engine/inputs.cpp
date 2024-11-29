#include "inputs.hpp"
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <cstddef>

KeyEvents keys() {
    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    KeyEvents events = {
        // NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)
        state[SDL_SCANCODE_UP] != 0U,
        state[SDL_SCANCODE_RIGHT] != 0U,
        state[SDL_SCANCODE_DOWN] != 0U,
        state[SDL_SCANCODE_LEFT] != 0U,
        // NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    };

    return events;
}

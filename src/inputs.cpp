#include "inputs.hpp"

KeyEvents handle_keys(SDL_Event event) {
  KeyEvents keys;
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  keys.up = state[SDL_SCANCODE_UP];
  keys.right = state[SDL_SCANCODE_RIGHT];
  keys.down = state[SDL_SCANCODE_DOWN];
  keys.left = state[SDL_SCANCODE_LEFT];
  return keys;
}

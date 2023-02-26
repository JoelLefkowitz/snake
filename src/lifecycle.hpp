#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include "draw.hpp"
#include <SDL2/SDL.h>

bool init_sdl(SDL_Window **window, SDL_Renderer **renderer);
void close_sdl(SDL_Window *window, SDL_Renderer *renderer);

const int init_width = n_horizontal * side;
const int init_height = n_vertical * side;

#endif
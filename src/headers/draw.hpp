#ifndef DRAW_H
#define DRAW_H

#include <SDL2/SDL.h>
#include "state.hpp"

const int side = 10;
const int n_vertical = 10;
const int n_horizontal = 10;

bool init_draw(SDL_Surface** surface);
void close_draw(SDL_Surface* surface);
void paint_texture(SDL_Surface* surface, SDL_Renderer* renderer, GameState game_state);

void draw_grid (SDL_Surface* surface);
void draw_head (SDL_Surface* surface, int head_x, int head_y);
void draw_bean (SDL_Surface* surface, int bean_x, int bean_y);

#endif
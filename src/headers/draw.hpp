#ifndef DRAW_H
#define DRAW_H

#include <SDL2/SDL.h>
#include "colours.hpp"
#include "state.hpp"

const int side = 30;
const int n_vertical = 20;
const int n_horizontal = 20;

bool init_draw(SDL_Surface** surface);
void close_draw(SDL_Surface* surface);
void init_rect(SDL_Rect* rect, int x, int y, int w, int h);

void paint_texture(SDL_Surface* surface, SDL_Renderer* renderer, GameState game_state);
void draw_grid (SDL_Surface* surface);
void draw_rect_at_position(SDL_Surface* surface, Position pos, RGB rgb);
void draw_bean (SDL_Surface* surface, Position bean);
void draw_head (SDL_Surface* surface, Position head);
void draw_tail(SDL_Surface* surface, std::vector<Position> tail);

#endif
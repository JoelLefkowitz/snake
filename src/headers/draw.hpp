#include <SDL2/SDL.h>

const int side = 10;
const int n_vertical = 10;
const int n_horizontal = 10;
const int width = n_horizontal * side;
const int height = n_vertical * side;
void draw_grid (SDL_Surface* surface);
void draw_head (SDL_Surface* surface, int head_x,
                int head_y);
void draw_bean (SDL_Surface* surface, int bean_x,
                int bean_y);

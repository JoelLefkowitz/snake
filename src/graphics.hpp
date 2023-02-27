#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "state.hpp"
#include <SDL2/SDL.h>
#include <string>

const int size = 10;
const int side = 30;

const int height = 300;
const int width  = 300;

const Uint32 window_flags = SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE;

const Uint32 renderer_flags = SDL_RENDERER_PRESENTVSYNC |
    SDL_RENDERER_ACCELERATED;

struct RGB {
    int r;
    int g;
    int b;
};

class Graphics {
  private:
    std::string title = "Snake";

    SDL_Window   *window   = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Surface  *surface  = nullptr;

    void draw(const Position &pos, const RGB &rgb);
    RGB  grey(int grey);

    void grid();

    void bean(const Position &pos);
    void head(const Position &pos);
    void tail(const std::vector<Position> &segments);

  public:
    Graphics();
    ~Graphics();

    void update(const GameState &game);
};

#endif

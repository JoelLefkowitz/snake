#ifndef SNAKE_ENGINE_GRAPHICS_HPP
#define SNAKE_ENGINE_GRAPHICS_HPP

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <string>
#include <vector>

const int SIZE = 10;
const int SIDE = 30;

const int HEIGHT = 300;
const int WIDTH  = 300;

const Uint32 WINDOW_FLAGS   = SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE;
const Uint32 RENDERER_FLAGS = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;

struct RGB {
    int r;
    int g;
    int b;
};

class Position;
class GameState;

class Graphics {
  private:
    std::string title = "Snake";

    SDL_Window   *window   = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Surface  *surface  = nullptr;

    static RGB grey(int shade);

    void draw(const Position &pos, const RGB &rgb);

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

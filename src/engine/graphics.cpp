#include "graphics.hpp"
#include "../models/position.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_hints.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include "state.hpp"
#include <stddef.h>

Graphics::Graphics()
    : window(
          SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, WINDOW_FLAGS)
      )
    , renderer(SDL_CreateRenderer(window, -1, RENDERER_FLAGS))
    , surface(SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0, 0, 0, 0)) {
    SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");
}

Graphics::~Graphics() {
    if (SDL_WasInit(SDL_INIT_VIDEO) != 0) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
    }
}

void Graphics::update(const GameState &game) {
    grid();
    bean(game.bean);
    head(game.head);
    tail(game.tail);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
    }

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Graphics::draw(const Position &pos, const RGB &rgb) {
    SDL_Rect rect = {pos.x * SIDE, pos.y * SIDE, SIDE, SIDE};
    SDL_FillRect(
        surface,
        &rect,
        SDL_MapRGB(surface->format, static_cast<Uint8>(rgb.r), static_cast<Uint8>(rgb.g), static_cast<Uint8>(rgb.b))
    );
}

RGB Graphics::grey(int shade) { return {shade, shade, shade}; }

void Graphics::grid() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            draw({i, j}, grey(120 + 20 * ((j + i) % 2)));
        }
    }
}

void Graphics::bean(const Position &pos) { draw(pos, {0, 50, 180}); }

void Graphics::head(const Position &pos) { draw(pos, {20, 100, 20}); }

void Graphics::tail(const std::vector<Position> &segments) {
    for (Position pos : segments) {
        draw(pos, {20, 120, 20});
    }
}

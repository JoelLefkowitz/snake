#include "headers/draw.hpp"
#include "headers/state.hpp"
#include "headers/colours.hpp"
#include "headers/lifecycle.hpp"

bool init_draw(SDL_Surface** surface) {
    *surface = SDL_CreateRGBSurface(
                   0, init_width, init_height, 32, 0, 0, 0, 0
               );

    if (!*surface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create surface: %s",
                     SDL_GetError());
        return false;
    }

    return true;
}

void paint_texture(SDL_Surface* surface, SDL_Renderer* renderer, GameState game_state) {
    draw_grid(surface);
    draw_head(surface, game_state.head);
    draw_tail(surface, game_state.tail);
    draw_bean(surface, game_state.bean);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(
                               renderer, surface
                           );

    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create texture from surface: %s",
                     SDL_GetError());
    }

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void draw_grid(SDL_Surface* surface) {
    RGB rgb;
    Position pos;

    for (int i = 0; i < n_vertical; ++i) {
        for (int j = 0; j < n_horizontal; ++j) {
            pos.x = i;
            pos.y = j;
            init_greyscale(&rgb, 120 + 20 * ((j + i) % 2));
            draw_rect_at_position(surface, pos, rgb);
        }
    }
}

void draw_head(SDL_Surface* surface, Position head) {
    RGB rgb;
    init_colour(&rgb, 20, 120, 20);
    draw_rect_at_position(surface, head, rgb);
}

void draw_tail(SDL_Surface* surface, std::vector<Position> tail) {
    RGB rgb;
    init_colour(&rgb, 20, 100, 20);

    for (Position tail_piece: tail) {
        draw_rect_at_position(surface, tail_piece, rgb);
    }
}

void draw_bean(SDL_Surface* surface, Position bean) {
    RGB rgb;
    init_colour(&rgb, 0, 50, 180);
    draw_rect_at_position(surface, bean, rgb);
}

void draw_rect_at_position(SDL_Surface* surface, Position pos, RGB rgb) {
    SDL_Rect rect;
    init_rect(&rect, pos.x * side, pos.y * side, side, side);
    SDL_FillRect(surface, &rect,
                 SDL_MapRGB(surface->format, rgb.r, rgb.g, rgb.b));
}

void init_rect(SDL_Rect* rect, int x, int y,
               int w, int h) {
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}

void close_draw(SDL_Surface* surface) {
    SDL_FreeSurface(surface);
}
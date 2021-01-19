#include <iostream>
#include "headers/draw.hpp"

void paint_surface(SDL_Window* window, SDL_Renderer* renderer, GameState game_state) {
    int* width;
    int* height;
    SDL_GetWindowSize(window, width, height);
    SDL_Surface* surface = SDL_CreateRGBSurface(0, *width, *height,
                                                32, 0, 0, 0, 0);
    draw_grid(surface);
    draw_head(surface, game_state.head_x,
              game_state.head_y);
    draw_bean(surface, game_state.bean_x,
              game_state.bean_y);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,
                           surface);

    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create texture from surface: %s",
                     SDL_GetError());
    }

    SDL_FreeSurface(surface);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00,
                           0x00);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void draw_grid(SDL_Surface* surface) {
    SDL_Rect rect;
    SDL_Rect* ptr;
    ptr = &rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = side;
    rect.h = side;

    for (int i = 0; i < n_vertical; i++) {
        for (int j = 0; j < n_horizontal; j++) {
            rect.x = i * side;
            rect.y = j * side;
            int r = 100 * ((j + i + 1) % 2);
            int g = 50;
            int b = 100 * ((j + i) % 2);
            SDL_FillRect(surface, ptr,
                         SDL_MapRGB(surface->format, r, g, b));
        }
    }
}


void draw_head(SDL_Surface* surface, int head_x,
               int head_y) {
    SDL_Rect rect;
    SDL_Rect* ptr;
    ptr = &rect;
    rect.x = head_x * side;
    rect.y = head_y * side;
    rect.w = side;
    rect.h = side;
    SDL_FillRect(surface, ptr,
                 SDL_MapRGB(surface->format, 255, 0, 0));
}

void draw_bean(SDL_Surface* surface, int bean_x,
               int bean_y) {
    SDL_Rect rect;
    SDL_Rect* ptr;
    ptr = &rect;
    rect.x = bean_x * side;
    rect.y = bean_y * side;
    rect.w = side;
    rect.h = side;
    SDL_FillRect(surface, ptr,
                 SDL_MapRGB(surface->format, 0, 255, 0));
}


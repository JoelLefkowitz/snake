#include <iostream>
#include "headers/draw.hpp"

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
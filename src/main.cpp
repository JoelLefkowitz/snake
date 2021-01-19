#include <iostream>
#include "headers/lifecycle.hpp"
#include "headers/inputs.hpp"
#include "headers/state.hpp"
#include "headers/draw.hpp"

int main( int argc, char* args[] ) {
    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool quit = !(init_sdl(&window, &renderer) && init_draw(&surface));

    SDL_Event event;
    KeyEvents keys;
    GameState game_state = random_state();

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }

            if (event.type == SDL_KEYDOWN) {
                keys = handle_keys(event);
            }
        }

        update_state(&game_state, keys);
        paint_texture(surface, renderer, game_state);
        SDL_Delay( 50 );
    }

    close_draw(surface);
    close_sdl(window, renderer);
    return 0;
}


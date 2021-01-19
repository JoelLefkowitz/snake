#include "headers/lifecycle.hpp"
#include "headers/inputs.hpp"
#include "headers/state.hpp"
#include "headers/draw.hpp"

int main( int argc, char* args[] ) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event* event;
    KeyEvents keys;
    GameState game_state = random_state();
    bool quit = !init_sdl(window, renderer);

    while (!quit) {
        SDL_PollEvent(event);

        if (event->type == SDL_QUIT) {
            quit = true;
        }

        if (event->type == SDL_KEYDOWN) {
            keys = handle_keys(*event);
        }

        update_state(&game_state, keys);
        paint_surface(window, renderer, game_state);
        SDL_Delay( 15 );
    }

    close_sdl(window, renderer);
    return 0;
}


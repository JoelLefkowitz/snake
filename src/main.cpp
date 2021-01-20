#include "headers/main.hpp"
#include "headers/lifecycle.hpp"
#include "headers/inputs.hpp"
#include "headers/state.hpp"
#include "headers/draw.hpp"

int main( int argc, char* args[] ) {
    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool quit = !(init_sdl(&window, &renderer) && init_draw(&surface));

    // Put STEP event on a timer
    SDL_AddTimer(step_interval, push_step_event, NULL);

    // Seed rand outside of state functions
    srand (time(NULL));

    SDL_Event event;
    KeyEvents keys;
    GameState game_state = init_state();

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }

            else if (event.type == SDL_KEYDOWN) {
                keys = handle_keys(event);
            }

            else if (event.type == STEP) {
                update_state(&game_state, keys);
                paint_texture(surface, renderer, game_state);

                if (!game_state.game_over) {
                    SDL_AddTimer(step_interval, push_step_event, NULL);
                }
            }
        }
    }

    close_draw(surface);
    close_sdl(window, renderer);
    return 0;
}

Uint32 push_step_event(Uint32 interval, void *param) {
    SDL_Event event;
    event.type = STEP;
    SDL_PushEvent(&event);
    return 0;
}


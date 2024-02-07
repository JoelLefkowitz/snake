#include "main.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_error.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_log.h"
#include "SDL2/SDL_timer.h"
#include "graphics.hpp"
#include "inputs.hpp"
#include "state.hpp"
#include <stdlib.h>
#include <string>
#include <time.h>

const Uint32 STEP = SDL_RegisterEvents(1);

int main(int argc, char *args[]) {
    srand(static_cast<unsigned int>(time(NULL)));

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL could not initialize. %s", SDL_GetError());
    }

    Graphics  graphics;
    GameState game;
    KeyEvents inputs;

    SDL_Event event;
    SDL_AddTimer(FRAMERATE, step, NULL);

    bool quit = false;

    while (!quit) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }

            else if (event.type == SDL_KEYDOWN) {
                inputs = keys(event);
            }

            else if (event.type == STEP) {
                game.update(inputs);
                graphics.update(game);

                if (!game.over) {
                    SDL_AddTimer(FRAMERATE, step, NULL);
                }
            }
        }
    }

    SDL_Quit();

    return std::string(SDL_GetError()).empty() ? 0 : 1;
}

Uint32 step(Uint32 interval, void *param) {
    SDL_Event event;
    event.type = STEP;
    SDL_PushEvent(&event);
    return 0;
}

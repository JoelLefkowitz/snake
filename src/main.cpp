#include "main.hpp"
#include "engine/graphics.hpp"
#include "engine/inputs.hpp"
#include "engine/state.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_timer.h>
#include <cstdlib>
#include <ctime>
#include <string>

const Uint32 STEP = SDL_RegisterEvents(1);

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg,hicpp-vararg)
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL could not initialize. %s", SDL_GetError());
    }

    Graphics  graphics;
    GameState game;

    KeyEvents inputs{};

    SDL_Event event;
    SDL_AddTimer(FRAMERATE, step, nullptr);

    bool quit = false;

    while (!quit) {
        if (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }

            else if (event.type == SDL_KEYDOWN) {
                inputs = keys();
            }

            else if (event.type == STEP) {
                game.update(inputs);
                graphics.update(game);

                if (!game.over) {
                    SDL_AddTimer(FRAMERATE, step, nullptr);
                }
            }
        }
    }

    SDL_Quit();

    return std::string(SDL_GetError()).empty() ? 0 : 1;
}


// NOLINTNEXTLINE(misc-unused-parameters)
Uint32 step(Uint32 _, void *__) {
    SDL_Event event;
    event.type = STEP;
    SDL_PushEvent(&event);
    return 0;
}

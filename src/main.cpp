#include <iostream>
#include "headers/main.hpp"
#include "headers/draw.hpp"
#include "headers/utils.hpp"

int main( int argc, char* args[] ) {
    init_sdl();
    bool quit = false;
    GameState game_state = random_state();
    while (!quit) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            quit = true;
        }
        SDL_Delay( 50 );
        KeyEvents keys = handle_keys(event);
        game_state = update_state(game_state, keys);
        paint(game_state);
    }
    close_sdl();
    return 0;
}

void init_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't initialize SDL: %s", SDL_GetError());
    }
    if (SDL_CreateWindowAndRenderer(320, 240,
                                    SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create window and renderer: %s",
                     SDL_GetError());
    }
}

void paint(GameState game_state) {
    surface = SDL_CreateRGBSurface(0, width, height,
                                   32, 0, 0, 0, 0);
    draw_grid(surface);
    draw_head(surface, game_state.head_x,
              game_state.head_y);
    draw_bean(surface, game_state.bean_x,
              game_state.bean_y);
    texture = SDL_CreateTextureFromSurface(renderer,
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

KeyEvents handle_keys(SDL_Event event) {
    KeyEvents keys;
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    keys.up = state[SDL_SCANCODE_UP];
    keys.right = state[SDL_SCANCODE_RIGHT];
    keys.down = state[SDL_SCANCODE_DOWN];
    keys.left = state[SDL_SCANCODE_LEFT];
    return keys;
}

GameState random_state() {
    srand (time(NULL));
    GameState game_state;
    game_state.head_x = rand() % n_horizontal;
    game_state.head_y = rand() % n_vertical;
    game_state.bean_x = rand() % n_horizontal;
    game_state.bean_y = rand() % n_vertical;
    game_state.heading = (rand() % 4) + 1;
    return game_state;
}

GameState update_state(GameState game_state,
                       KeyEvents keys) {
    if (keys.up) {
        game_state.heading = 1;
    }
    if (keys.right) {
        game_state.heading = 2;
    }
    if (keys.down) {
        game_state.heading = 3;
    }
    if (keys.left) {
        game_state.heading = 4;
    }
    switch (game_state.heading) {
    case 1:
        game_state.head_y = neg_modulo((game_state.head_y
                                        - 1),
                                       n_vertical);
        break;
    case 2:
        game_state.head_x = neg_modulo((game_state.head_x
                                        + 1),
                                       n_horizontal);
        break;
    case 3:
        game_state.head_y = neg_modulo((game_state.head_y
                                        + 1),
                                       n_vertical);
        break;
    case 4:
        game_state.head_x = neg_modulo((game_state.head_x
                                        - 1),
                                       n_horizontal);
        break;
    };
    return game_state;
}

void close_sdl() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

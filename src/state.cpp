#include "headers/state.hpp"
#include "headers/draw.hpp"
#include "headers/utils.hpp"

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

void update_state(GameState* game_state,
                  KeyEvents keys) {
    update_heading(game_state, keys);
    update_head_position(game_state);
}


void update_heading(GameState* game_state, KeyEvents keys) {
    if (keys.up) {
        game_state->heading = 1;
    }

    if (keys.right) {
        game_state->heading = 2;
    }

    if (keys.down) {
        game_state->heading = 3;
    }

    if (keys.left) {
        game_state->heading = 4;
    }
}

void update_head_position(GameState* game_state) {
    switch (game_state->heading) {
        case 1:
            game_state->head_y =
                neg_modulo(
                    (game_state->head_y - 1), n_vertical
                );
            break;

        case 2:
            game_state->head_x =
                neg_modulo((game_state->head_x
                            + 1),
                           n_horizontal);
            break;

        case 3:
            game_state->head_y =
                neg_modulo((game_state->head_y
                            + 1),
                           n_vertical);
            break;

        case 4:
            game_state->head_x =
                neg_modulo((game_state->head_x
                            - 1),
                           n_horizontal);
            break;
    };
}
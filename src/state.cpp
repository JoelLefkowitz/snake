#include "headers/state.hpp"
#include "headers/draw.hpp"
#include "headers/utils.hpp"

Position random_position() {
    Position pos;
    pos.x = rand() % n_horizontal;
    pos.y = rand() % n_vertical;
    return pos;
}

bool operator==(const Position& lhs, const Position& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

GameState init_state() {
    GameState game_state;
    game_state.head = random_position();
    game_state.bean = random_position();
    game_state.heading = Direction((rand() % 4));
    game_state.score = 0;
    game_state.game_over = false;
    return game_state;
}

void update_state(GameState* game_state,
                  KeyEvents keys) {
    update_heading(game_state, keys);
    Position prev_head = game_state->head;
    update_head(game_state);
    update_tail(game_state, prev_head);
    update_bean(game_state);
    check_game_over(game_state);
}


void update_heading(GameState* game_state, KeyEvents keys) {
    if (keys.up && game_state->heading != DOWN) {
        game_state->heading = UP;
    }

    else if (keys.right && game_state->heading != LEFT) {
        game_state->heading = RIGHT;
    }

    else if (keys.down && game_state->heading != UP) {
        game_state->heading = DOWN;
    }

    else if (keys.left && game_state->heading != RIGHT) {
        game_state->heading = LEFT;
    }
}

void update_head(GameState* game_state) {
    switch (game_state->heading) {
        case UP:
            game_state->head.y =
                neg_modulo(
                    (game_state->head.y - 1), n_vertical
                );
            break;

        case RIGHT:
            game_state->head.x =
                neg_modulo((game_state->head.x
                            + 1),
                           n_horizontal);
            break;

        case DOWN:
            game_state->head.y =
                neg_modulo((game_state->head.y
                            + 1),
                           n_vertical);
            break;

        case LEFT:
            game_state->head.x =
                neg_modulo((game_state->head.x
                            - 1),
                           n_horizontal);
            break;
    };
}


void update_tail(GameState* game_state, Position prev_head) {
    if (game_state->head == game_state->bean) {
        (game_state->tail).push_back(prev_head);
        game_state->score++;
    }

    else if (game_state->tail.size() > 0) {
        game_state->tail.erase(game_state->tail.begin());
        game_state->tail.push_back(prev_head);
    }
}

void update_bean(GameState* game_state) {
    if (game_state->head == game_state->bean) {
        game_state->bean = random_position();
    }
}

void check_game_over(GameState* game_state) {
    for (Position tail_piece: game_state->tail) {
        if (game_state->head == tail_piece) {
            game_state->game_over = true;
        }
    }
}
#include "state.hpp"
#include "graphics.hpp"
#include "inputs.hpp"
#include "numbers.hpp"
#include "position.hpp"
#include <algorithm>

GameState::GameState()
    : bean(Position::random_position())
    , head(Position::random_position())
    , tail({})
    , heading(RIGHT)
    , over(false)
    , score(0) {
}

void GameState::update(const KeyEvents &keys) {
    update_heading(keys);

    Position prev_head = head;
    update_head();
    update_tail(prev_head);

    check_game_over();

    update_bean();
}

void GameState::update_heading(const KeyEvents &keys) {
    if (keys.up && heading != DOWN) {
        heading = UP;
    }

    else if (keys.right && heading != LEFT) {
        heading = RIGHT;
    }

    else if (keys.down && heading != UP) {
        heading = DOWN;
    }

    else if (keys.left && heading != RIGHT) {
        heading = LEFT;
    }
}

void GameState::update_head() {
    switch (heading) {
    case UP:
        head.y = neg_modulo((head.y - 1), SIZE);
        break;

    case RIGHT:
        head.x = neg_modulo((head.x + 1), SIZE);
        break;

    case DOWN:
        head.y = neg_modulo((head.y + 1), SIZE);
        break;

    case LEFT:
        head.x = neg_modulo((head.x - 1), SIZE);
        break;
    };
}

void GameState::update_tail(const Position &prev_head) {
    if (head == bean) {
        (tail).push_back(prev_head);
        score++;
    }

    else if (tail.size() > 0) {
        tail.erase(tail.begin());
        tail.push_back(prev_head);
    }
}

void GameState::update_bean() {
    if (head == bean) {
        bean = Position::random_position();
    }
}

void GameState::check_game_over() {
    over = std::any_of(tail.begin(), tail.end(), [&](const Position &piece) { return head == piece; });
}

#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *surface;
SDL_Texture *texture;
SDL_Event event;

struct GameState {
    int head_x;
    int head_y;
    int bean_x;
    int bean_y;
    int heading;
};

struct KeyEvents {
    bool up;
    bool right;
    bool down;
    bool left;
};

void init_sdl();
KeyEvents handle_keys(SDL_Event event);
GameState random_state();
GameState update_state(GameState game_state,
                       KeyEvents keys);
void paint(GameState game_state);
void close_sdl();

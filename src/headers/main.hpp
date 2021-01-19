#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>

int step_interval = 100;
Uint32 STEP = SDL_RegisterEvents(1);
Uint32 push_step_event(Uint32 interval, void *param);

#endif
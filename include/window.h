#ifndef WINDOW
#define WINDOW
#include <SDL2/SDL.h>
#include "defines.h"
#include "render.h"
#include "img_macros.h"

extern SDL_Window *win;
extern SDL_Texture *img;
extern SDL_Texture *img2;


int init();
#endif
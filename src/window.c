#include "window.h"

SDL_Window *win = NULL;
SDL_Texture *img = NULL;
SDL_Texture *img2 = NULL;
SDL_Texture *img3 = NULL;
SDL_Texture *img4 = NULL;

int init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;
    win = SDL_CreateWindow("Image Loading", 100, 100, WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    img = IMG_LoadTexture(renderer, IMG_PATH);
    img2 = IMG_LoadTexture(renderer, WALL_PATH);
    img3 = IMG_LoadTexture(renderer, MENU_PATH);
    img4 = IMG_LoadTexture(renderer, SWORD_PATH);
    library[0] = img;
    library[1] = img2;
    library[2] = img3;
    library[3] = img4;
    return 0;
}
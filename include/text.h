#ifndef TEXT
#define TEXT
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


struct text_header{
    SDL_Texture *texture;
    SDL_Rect *box;
    int event_id;
    uint8_t enabled;
};



typedef struct text_header text;

void modify_enabled(text* t);
#endif
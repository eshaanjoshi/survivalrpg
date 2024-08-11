#ifndef TEXT
#define TEXT
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "triggers.h"

struct text_header{
    SDL_Texture *texture;
    SDL_Rect *box;
    int event_id;
    enum EVENT_TRIGGERS event_name;
    int background;
    uint8_t alpha;
    uint8_t enabled;
};



typedef struct text_header text;

void modify_enabled(text* t);
#endif
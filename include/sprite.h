#ifndef SPRITE
#define SPRITE
#include <SDL2/SDL_image.h>
#include "vector.h"
enum sprite_type_id{
    PLAYER_T,
    WALL_T,
    INTERACTABLE_T,
    NON_INTERACT,
};

struct sprite_t{
    int texture_id;
    enum sprite_type_id sprite_type;
    SDL_Rect *box;
};

typedef struct sprite_t sprite;


SDL_Rect *create_texture(vector *l, vector *dim);
sprite *create_sprite(vector *locat, vector *dim);


#endif

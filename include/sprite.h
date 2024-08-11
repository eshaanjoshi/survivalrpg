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

typedef struct {
    const char *name;
    int i;
} item_t;

typedef struct {
    const char *info;
    item_t item_pickup;
} sprite_items;

struct sprite_t{
    int texture_id;
    enum sprite_type_id sprite_type;
    SDL_Rect *box;
    item_t *t;
};

typedef struct sprite_t sprite;


SDL_Rect *create_texture(vector *l, vector *dim);
sprite *create_sprite(vector *locat, vector *dim);
sprite *create_item(vector *locat, vector *dim, int iid);

#endif

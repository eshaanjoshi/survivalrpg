#include "sprite.h"
#include "defines.h"

SDL_Rect *create_texture(vector *l, vector *dim)
{
    SDL_Rect *t = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    t->x = (l->x + (rand() % WIDTH - (WIDTH/2)))/50 * 50;
    t->y = (l->y + (rand() % HEIGHT - (HEIGHT/2)))/50 * 50;
    t->w = dim->x;
    t->h = dim->y;
    return t;
}

sprite *create_sprite(vector *locat, vector *dim)
{
    SDL_Rect *texr = create_texture(locat, dim);
    sprite *obj = (sprite*)malloc(sizeof(sprite));
    obj->box = texr;
    obj->texture_id = 1;
    obj->sprite_type = WALL_T;
    return obj;
}
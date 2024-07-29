#include "player.h"
#include "defines.h"
static char mv[4];
char keypressed[322];

void set_x_zero()
{
    mv[LEFT] = 0;
    mv[RIGHT] = 0;
}

void set_y_zero()
{
    mv[UP] = 0;
    mv[DOWN] = 0;
}

void set_zero(enum direction D)
{
    mv[D] = 0;
}

void player_handler(sprite *player, vectorf *location)
{
    vectorf change = {mv[RIGHT] - mv[LEFT], mv[DOWN] - mv[UP]};
    norm(&change);
    location->x += STEP * change.x / FRAME_RATE;
    location->y += STEP * change.y / FRAME_RATE;
    vector new_loc;
    float_to_int_vector(&new_loc, location);
    player->box->x = new_loc.x;
    player->box->y = new_loc.y;
}


void player_event_handler(SDL_Event *e)
{
    if (e->type == SDL_QUIT)
    {
        exit(1);
    }
    else if (e->type == SDL_KEYDOWN)
    {
        keypressed[e->key.keysym.scancode] = 1;   
    }
    else if (e->type == SDL_KEYUP){
        keypressed[e->key.keysym.scancode] = 0;
    }
    mv[UP] = keypressed[SDL_SCANCODE_W];
    mv[DOWN] = keypressed[SDL_SCANCODE_S];
    mv[LEFT] = keypressed[SDL_SCANCODE_A];
    mv[RIGHT] = keypressed[SDL_SCANCODE_D];
}

sprite *create_player(vector *locat, vector *dim)
{
    SDL_Rect *texr = create_texture(locat, dim);
    sprite *player = (sprite*)malloc(sizeof(sprite));
    player->texture_id = 0;
    player->box = texr;
    player->sprite_type = PLAYER_T;
    return player;
}
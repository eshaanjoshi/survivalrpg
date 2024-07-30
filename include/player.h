#ifndef PLAYER
#define PLAYER
#include <SDL2/SDL.h>
#include "vector.h"
#include "sprite.h"
#include "event_handler.h"
enum direction
{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
};



void player_handler(sprite *player, vectorf *location);
//void player_event_handler(SDL_Event *e);
void set_zero(enum direction D);
void set_x_zero();
void set_y_zero();
sprite *create_player(vector *locat, vector *dim);
void update_mv();
#endif
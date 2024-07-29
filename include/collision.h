#ifndef COLLISION
#define COLLISION
#include <SDL2/SDL.h>
#include "sprite.h"
#include "data.h"
#include "player.h"
void collide_with_all(sprite *obj, stack_t *s);

void do_collision(stack_t *s);

#endif
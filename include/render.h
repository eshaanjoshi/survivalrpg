
#ifndef RENDER
#define RENDER

#include "data.h"
#include "text.h"
extern SDL_Renderer *renderer;
extern SDL_Texture *library[10];
void handle_types(list *temp, int id);



void render_textures(stack_t *s, int id);

#endif


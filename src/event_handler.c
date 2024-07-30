#include "event_handler.h"
char keypressed[322];
char keytapped[322];
void event_handler(SDL_Event *e)
{
    if (e->type == SDL_QUIT)
    {
        exit(1);
    }
    else if (e->type == SDL_KEYDOWN)
    {
        keypressed[e->key.keysym.scancode] = 1; 
        keytapped[e->key.keysym.scancode] += 1;  
    }
    else if (e->type == SDL_KEYUP){
        keypressed[e->key.keysym.scancode] = 0;
    }
}
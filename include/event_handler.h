#ifndef EVENTS
#define EVENTS
#include <SDL2/SDL.h>
extern char keypressed[322];
extern char keytapped[322];
void event_handler(SDL_Event *e);


#endif
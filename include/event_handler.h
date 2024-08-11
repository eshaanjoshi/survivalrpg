#ifndef EVENTS
#define EVENTS
#include <SDL2/SDL.h>
extern char keypressed[322];
extern char keytapped[322];
void event_handler(SDL_Event *e);
void init_active_buttons();
void init_menu_buttons();
void init_buttons();
#endif
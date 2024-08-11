#include "text.h"
#include "player.h"
#include "event_handler.h"
#include "state_handler.h"
void modify_enabled(text* t){
    // //t->enabled = keypressed[t->event_id];
    // if(event_director[t->event_name] > 0)
    // {
    //     t->enabled = !t->enabled;
    //     event_director[t->event_name] = 0;
    // }
    t->enabled = event_director[t->event_name];
}
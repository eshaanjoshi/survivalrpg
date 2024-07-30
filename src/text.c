#include "text.h"
#include "player.h"
#include "event_handler.h"

void modify_enabled(text* t){
    //t->enabled = keypressed[t->event_id];
    if(keytapped[t->event_id] > 0)
    {
        t->enabled = !t->enabled;
        keytapped[t->event_id] = 0;
    }
}
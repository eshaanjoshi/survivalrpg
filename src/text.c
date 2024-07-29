#include "text.h"
#include "player.h"


void modify_enabled(text* t){
    t->enabled = keypressed[t->event_id];
}
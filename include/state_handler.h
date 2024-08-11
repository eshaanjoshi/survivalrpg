#ifndef STATE_HANDLER
#define STATE_HANDLER

typedef enum {
    ACTIVE_T,
    MENU_T,
} GAME_STATE;

extern GAME_STATE game_state;

#endif
#include "event_handler.h"
#include "state_handler.h"
#include "triggers.h"
#include "defines.h"
#include "inventory_buttons.h"
char keypressed[322];
char keytapped[322];

void init_buttons()
{
    init_menu_buttons();
    init_active_buttons();
}

void init_menu_buttons(){
    init_inventory_buttons();
}

typedef enum {
    NO_ACTIVE_BUTTONS_T,
    GENERAL_MENU_T,
    INVENTORY_T,
} ACTIVE_BUTTON_LAYER_MENU;

ACTIVE_BUTTON_LAYER_MENU active_layer = NO_ACTIVE_BUTTONS_T;

char none_button_menu(int x, int y)
{
    int z = x - (WIDTH / 2 + WIDTH / 4 - 10);
    int w = y - (10 + (HEIGHT / 5) * 3);
    printf("%d %d\n", z/70, w/70);
    return 0x00;
}

char print_inventory(int x, int y)
{
    int z = (x - (WIDTH / 2 + WIDTH / 4 - 10))/70;
    int w = (y - (10 + (HEIGHT / 5) * 3))/70;
    printf("%d %d", z, w);
    printf("Inventory Slot %d\n", (3*z) + w + 1);
    return 0x00;
}

char (*menu_buttons[4][4]) (int x, int y);
char (*active_buttons[4][4]) (int x, int y);

void general_menu_buttons(SDL_MouseButtonEvent *b)
{
    // if(menu_buttons[find_button_x(b->x)][find_button_y(b->y)]==NULL)
    // {
    //     none_button_menu(b->x, b->y);
    //     return;
    // }
    // (*menu_buttons[find_button_x(b->x)][find_button_y(b->y)])(b->x, b->y);
}

void run_menu_buttons(SDL_MouseButtonEvent *b){
    if(event_director[OPEN_UI] > 0)
    {
        active_layer = INVENTORY_T;
    }
    if(active_layer == INVENTORY_T && event_director[OPEN_UI] == 0 ){
        active_layer = NO_ACTIVE_BUTTONS_T;
    }
    switch (active_layer){
        case GENERAL_MENU_T:
            general_menu_buttons(b);
            break;
        case INVENTORY_T:
            inventory_menu_buttons_call(b);
            break;
        default:
            break;
    }
}

void run_active_buttons(SDL_MouseButtonEvent *b){
    // if(active_buttons[find_button_x(b->x)][find_button_y(b->y)]==NULL)
    // {
    //     return;
    // }
    // (*active_buttons[find_button_x(b->x)][find_button_y(b->y)])(b->x, b->y);
}

char top_left_button_menu(int x, int y)
{
    printf("%d %d\n", x, y);
    return 0x00;
}



void init_active_buttons()
{
    
}



void choose_buttons(SDL_Event *e)
{
    switch(game_state)
    {
        case ACTIVE_T:
            run_active_buttons(&e->button);
            break;
        case MENU_T:
            run_menu_buttons(&e->button);
            break;
        default:
            break;
    }
}




void run_active_event(SDL_Scancode S)
{
    switch (S)
    {
    case SDL_SCANCODE_E:
        event_director[OPEN_UI] = 1;
        game_state = MENU_T;
        break;
    
    default:
        break;
    }
}

void run_menu_event(SDL_Scancode S)
{
    switch (S)
    {
    case SDL_SCANCODE_E:
        event_director[OPEN_UI] = 0;
        game_state = ACTIVE_T;
        break;
    
    default:
        break;
    }
}

// void run_mouse_event(SDL_Event *e){
//     (*p[find_button_x(e->button.x)][find_button_y(e->button.y)])(e->button.x, e->button.y);
// }


void run_event(SDL_Scancode S){
    switch (game_state)
    {
        case ACTIVE_T:
            run_active_event(S);
            break;
        case MENU_T:
            run_menu_event(S);
            break;
            
    }
}

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
        run_event(e->key.keysym.scancode); 
    }
    else if (e->type == SDL_KEYUP){
        keypressed[e->key.keysym.scancode] = 0;
    }
    else if(e->type == SDL_MOUSEBUTTONDOWN)
    {
        choose_buttons(e);
    }
}



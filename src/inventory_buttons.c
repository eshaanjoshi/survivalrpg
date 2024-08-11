#include "inventory_buttons.h"


char (*inventory_menu_buttons[4][4]) (int x, int y);
typedef enum{
    NONE_Y,
    TOP_Y,
    BOTTOM_Y,
    LAST_Y
}BUTTON_LOC_Y;

typedef enum{
    NONE_X,
    LEFT_X,
    RIGHT_X,
    LAST_X
}BUTTON_LOC_X;
int find_button_x(int x)
{    
    if(x<100)
    {
        return LEFT_X;
    }
    if(x>WIDTH / 2 + WIDTH / 4 - 10)
    {
        return RIGHT_X;
    }
    return NONE_X;
}

static char none_button_menu(int x, int y)
{
    //return 0x00;
    int z = x - (WIDTH / 2 + WIDTH / 4 - 10);
    int w = y - (10 + (HEIGHT / 5) * 3);
    printf("%d %d\n", z/70, w/70);
    return 0x00;
}

static char print_inventory(int x, int y)
{
    int z = (x - (WIDTH / 2 + WIDTH / 4 - 10))/70;
    int w = (y - (10 + (HEIGHT / 5) * 3))/70;
    printf("%d %d", z, w);
    printf("Inventory Slot %d\n", (3*z) + w + 1);
    return 0x00;
}

int find_button_y(int y)
{
    int w = y - (10 + (HEIGHT / 5) * 3);
    if(y<100)
    {
        return TOP_Y;
    }
    if(y>+ 10 + (HEIGHT / 5) * 3)
    {
        return BOTTOM_Y;
    }
    return NONE_Y;
}



void init_inventory_buttons()
{
    inventory_menu_buttons[TOP_Y][LEFT_X] = &none_button_menu;
    inventory_menu_buttons[NONE_Y][NONE_X] = &none_button_menu;
    inventory_menu_buttons[NONE_Y][LEFT_X] = &none_button_menu;
    inventory_menu_buttons[TOP_Y][NONE_X] = &none_button_menu;
    inventory_menu_buttons[BOTTOM_Y][RIGHT_X] = &print_inventory;
}


void inventory_menu_buttons_call(SDL_MouseButtonEvent *b)
{
    if(find_button_x(b->x) < 0 || find_button_y(b->y) < 0 || find_button_x(b->x) >= LAST_X || find_button_y(b->y) >= LAST_Y){
        return;
    }
    if(inventory_menu_buttons[find_button_x(b->x)][find_button_y(b->y)]==NULL)
    {
        none_button_menu(b->x, b->y);
        return;
    }
    (*inventory_menu_buttons[find_button_x(b->x)][find_button_y(b->y)])(b->x, b->y);
}


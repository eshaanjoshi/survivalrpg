#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "defines.h"
#include "img_macros.h"
#include "data.h"
#include "vector.h"
#include "timer.h"
#include "player.h"
#include "sprite.h"
#include "collision.h"
#include "render.h"
#include "window.h"
#include "event_handler.h"
#include "state_handler.h"

text *create_inventory_slot(TTF_Font *Sans, SDL_Surface *inv_slot, int offsetx, int offsety)
{
    SDL_Color White = {255, 255, 255};
    SDL_Surface *surfaceMessage =
        TTF_RenderText_Solid(Sans, "", White);
    SDL_Rect *slot = (SDL_Rect *)malloc(sizeof(SDL_Rect)); // create a rect
    slot->x = (70 * offsetx) + WIDTH / 2 + WIDTH / 4 - 10; // controls the rect's x coordinate
    slot->y = (70 * offsety) + 10 + (HEIGHT / 5) * 3;      // controls the rect's y coordinte
    slot->w = 60;                                          // controls the width of the rect
    slot->h = 60;                                          // controls the height of the rect
    SDL_Texture *slot_ = SDL_CreateTextureFromSurface(renderer, inv_slot);
    text *inventory = (text *)malloc(sizeof(text));
    inventory->box = slot;
    inventory->texture = slot_;
    inventory->event_name = OPEN_UI;
    inventory->background = 2;
    inventory->event_id = SDL_SCANCODE_E;
    inventory->alpha = 255;
    return inventory;
}

void init_inventory(stack_t *text_stack, TTF_Font *Sans)
{
    
    SDL_Color White = {255, 255, 255};
    SDL_Surface *surfaceMessage =
        TTF_RenderText_Solid(Sans, "", White);
    SDL_Surface *inv_slot_1 =
        TTF_RenderText_Solid(Sans, "Slot 1", White);
    SDL_Surface *inv_slot_2 =
        TTF_RenderText_Solid(Sans, "Slot 2", White);
    SDL_Surface *inv_slot_3 =
        TTF_RenderText_Solid(Sans, "Slot 3", White);
    SDL_Surface *inv_slot_4 =
        TTF_RenderText_Solid(Sans, "Slot 4", White);
    SDL_Surface *inv_slot_5 =
        TTF_RenderText_Solid(Sans, "Slot 5", White);
    SDL_Surface *inv_slot_6 =
        TTF_RenderText_Solid(Sans, "Slot 6", White);
    SDL_Surface *inv_slot_7 =
        TTF_RenderText_Solid(Sans, "Slot 7", White);
    SDL_Surface *inv_slot_8 =
        TTF_RenderText_Solid(Sans, "Slot 8", White);
    SDL_Surface *inv_slot_9 =
        TTF_RenderText_Solid(Sans, "Slot 9", White);
    SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect *Message_rect = (SDL_Rect *)malloc(sizeof(SDL_Rect)); // create a rect
    Message_rect->x = 0;                                           // controls the rect's x coordinate
    Message_rect->y = (HEIGHT / 5) * 3;                      // controls the rect's y coordinte
    Message_rect->w = WIDTH;                                       // controls the width of the rect
    Message_rect->h = 2 * (HEIGHT / 5) + 1;                        // controls the height of the rect
    text *tex = (text *)malloc(sizeof(text));
    tex->box = Message_rect;
    tex->texture = Message;
    tex->enabled = 1;
    tex->event_id = SDL_SCANCODE_E;
    tex->event_name = OPEN_UI;
    tex->background = 2;
    tex->alpha = 128;
    add_text_to_list(create_inventory_slot(Sans, inv_slot_1, 0, 0), text_stack);
    add_text_to_list(create_inventory_slot(Sans, inv_slot_2, 0, 1), text_stack);
    add_text_to_list(create_inventory_slot(Sans, inv_slot_3, 0, 2), text_stack);
    add_text_to_list(create_inventory_slot(Sans, inv_slot_4, 1, 0), text_stack);
    add_text_to_list(create_inventory_slot(Sans, inv_slot_5, 1, 1), text_stack);
    add_text_to_list(create_inventory_slot(Sans, inv_slot_6, 1, 2), text_stack);
    add_text_to_list(create_inventory_slot(Sans, inv_slot_7, 2, 0), text_stack);
    add_text_to_list(create_inventory_slot(Sans, inv_slot_8, 2, 1), text_stack);
    add_text_to_list(create_inventory_slot(Sans, inv_slot_9, 2, 2), text_stack);
    add_text_to_list(tex, text_stack);
}

int main(int argc, char *argv[])
{
    init_buttons();
    stack_t *stack = new_stack();
    stack_t *text_stack = new_stack();
    struct timeval *t = init_time();
    struct timeval *t2 = init_time();
    init();
    vectorf location = {WIDTH / 2, HEIGHT / 2};
    vector locat = {WIDTH / 2, HEIGHT / 2};
    vector dim = {50, 50};
    sprite *player = create_player(&locat, &dim);
    add_sprite_to_list(player, stack);
    for (int i = 0; i < 10; i++)
    {

        add_sprite_to_list(create_sprite(&locat, &dim), stack);
    }
    vector topright = {10, 10};
    add_sprite_to_list(create_item(&locat, &dim, 3), stack);
    //add_sprite_to_list(create_sprite(&locat, &dim), stack);
    int frames = 0;
    TTF_Init();
    TTF_Font *Sans = TTF_OpenFont("/usr/share/fonts/truetype/liberation/LiberationSans-Bold.ttf", 24);
    if (!Sans)
    {
        printf("TTF_OpenFont: %s\n", TTF_GetError());

        // handle error
    }
    SDL_Color White = {255, 255, 255};
    
    init_inventory(text_stack, Sans);
    
    while (1)
    {
        frames++;
        if (frames % 60 == 0)
        {
            printf("%ld\n", time_since(t2) / 1000);
            timer(t2);
            frames = 0;
        }
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            event_handler(&e);
        }
        SDL_RenderClear(renderer);
        if (game_state == ACTIVE_T)
        {
            update_mv();

            do_collision(stack);
            player_handler(player, &location);
        }
        render_textures(stack, 1);
        render_textures(text_stack, 1);
        // this opens a font style and sets a size

        // as TTF_RenderText_Solid could only be used on
        // SDL_Surface then you have to create the surface first

        SDL_RenderPresent(renderer);
        wait_until(t);
        timer(t);
    }
    free_stack(stack);
    SDL_DestroyTexture(img);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    return 0;
}
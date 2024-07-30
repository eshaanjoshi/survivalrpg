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

int main(int argc, char *argv[])
{
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
    int frames = 0;
    TTF_Init();
    TTF_Font *Sans = TTF_OpenFont("/usr/share/fonts/truetype/liberation/LiberationSans-Bold.ttf", 24);
    if (!Sans)
    {
        printf("TTF_OpenFont: %s\n", TTF_GetError());

        // handle error
    }
    SDL_Color White = {255, 255, 255};

    SDL_Surface *surfaceMessage =
        TTF_RenderText_Solid(Sans, "put your text here", White);

    // now you can convert it into a texture
    SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect *Message_rect = (SDL_Rect*)malloc(sizeof(SDL_Rect)); // create a rect
    Message_rect->x = 0;    // controls the rect's x coordinate
    Message_rect->y = 0;    // controls the rect's y coordinte
    Message_rect->w = 100;  // controls the width of the rect
    Message_rect->h = 100;  // controls the height of the rect
    //SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    text *tex = (text*)malloc(sizeof(text));
    tex->box = Message_rect;
    tex->texture = Message;
    tex->enabled = 1;
    tex->event_id = SDL_SCANCODE_E;
    add_text_to_list(tex, text_stack);
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
        update_mv();
        SDL_RenderClear(renderer);
        do_collision(stack);
        player_handler(player, &location);
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
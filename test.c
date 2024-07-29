#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "defines.h"

typedef enum{
    TEXTURE,
} type_t;

struct list_t{
    type_t type;
    void* val;
    struct list_t* next;
};

typedef struct list_t list;

typedef struct{
    struct list_t* head;
} stack_t;

void add_texture_to_list(SDL_Rect *t, stack_t *head)
{
    list* s = (list*)malloc(sizeof(stack_t));
    s->type = TEXTURE;
    s->val = t;
    s->next = head->head;
    head->head = s;
}

stack_t *new_stack()
{
    stack_t *s = (stack_t*)malloc(sizeof(stack_t));
    s->head = NULL;
    return s;
}

void free_stack(stack_t *stack)
{
    while(stack->head != NULL)
    {
        list *temp = stack->head;
        stack->head = stack->head->next;
        free(temp);
    }
    free(stack);
}

struct vector_t
{
    int x;
    int y;
};

typedef struct vector_t vector;

enum direction
{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
};

char mv[4];

SDL_Window *win = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *img = NULL;

int init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;
    win = SDL_CreateWindow("Image Loading", 100, 100, WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    img = IMG_LoadTexture(renderer, IMG_PATH);
    return 0;
}

SDL_Rect *create_texture(vector *l, vector *dim)
{
    SDL_Rect *t = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    t->x = l->x;
    t->y = l->y;
    t->w = dim->x;
    t->h = dim->y;
    return t;
}

void event_handler(SDL_Event *e)
{
    if (e->type == SDL_QUIT)
    {
        exit(1);
    }
    else if (e->type == SDL_KEYDOWN || e->type == SDL_KEYUP)
    {
        switch (e->key.keysym.sym)
        {
        case SDLK_w:
            printf("UP!\n");
            mv[0] = -(e->type - 769);
            break;

        case SDLK_s:
            printf("DOWN!\n");
            mv[1] = -(e->type - 769);
            break;

        case SDLK_a:
            printf("LEFT!\n");
            mv[2] = -(e->type - 769);
            break;

        case SDLK_d:
            printf("RIGHT!\n");
            mv[3] = -(e->type - 769);
            break;
        }
    }
}

void player_handler(SDL_Rect *player, vector *location)
{
    location->x += STEP * (mv[3] - mv[2]);
    location->y += STEP * (mv[1] - mv[0]);
    player->x = location->x;
    player->y = location->y;
}

void render_textures(stack_t *s)
{
    list *temp = s->head;
    while(temp!=NULL)
    {
        SDL_RenderCopy(renderer, img, NULL, (SDL_Rect*)temp->val);
        temp = temp->next;
    }
}

int main(int argc, char *argv[])
{
    stack_t *stack = new_stack();

    init();
    vector location = {WIDTH / 2, HEIGHT / 2};
    vector locat = {WIDTH / 2, HEIGHT / 2};
    vector dim = {50, 50};
    SDL_Rect *texr = create_texture(&locat, &dim);
    SDL_Rect *texr2 = create_texture(&locat, &dim);
    add_texture_to_list(texr, stack);
    add_texture_to_list(texr2, stack);
    while (1)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            event_handler(&e);
        }
        player_handler(texr, &location);

        SDL_RenderClear(renderer);
        render_textures(stack);
        SDL_RenderPresent(renderer);
    }
    free_stack(stack);
    SDL_DestroyTexture(img);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    return 0;
}
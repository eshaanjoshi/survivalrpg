#ifndef DATA
#define DATA
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.h"
#include "text.h"
typedef enum{
    TEXTURE_T,
    SPRITE_T,
    TEXT_T,
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

void add_texture_to_list(SDL_Rect *t, stack_t *head);

void add_sprite_to_list(sprite *t, stack_t *head);

void add_text_to_list(text *t, stack_t *head);

stack_t *new_stack();

void free_stack(stack_t *stack);
#endif
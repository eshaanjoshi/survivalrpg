#include "data.h"
#include "text.h"
void add_texture_to_list(SDL_Rect *t, stack_t *head)
{
    list* s = (list*)malloc(sizeof(stack_t));
    s->type = TEXTURE_T;
    s->val = t;
    s->next = head->head;
    head->head = s;
}

void add_sprite_to_list(sprite *t, stack_t *head)
{
    list* s = (list*)malloc(sizeof(stack_t));
    s->type = SPRITE_T;
    s->val = t;
    s->next = head->head;
    head->head = s;
}

void add_text_to_list(text *t, stack_t *head)
{
    list* s = (list*)malloc(sizeof(stack_t));
    s->type = TEXT_T;
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
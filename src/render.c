#include "render.h"

SDL_Renderer *renderer = NULL;
SDL_Texture *library[10];

void handle_types(list *temp, int id)
{
    switch (temp->type)
    {
        case SPRITE_T:
            SDL_RenderCopy(renderer, library[((sprite*)temp->val)->texture_id], NULL, ((sprite*)temp->val)->box);
            break;
        case TEXTURE_T:
            SDL_RenderCopy(renderer, library[id], NULL, ((SDL_Rect*)temp->val));
            break;
        case TEXT_T:
            modify_enabled(((text*)temp->val));
            if(((text*)temp->val)->enabled == 1)
            {
                SDL_RenderCopy(renderer, ((text*)temp->val)->texture, NULL, ((text*)temp->val)->box);

            }
            break;
        default:
            break;
    }
}



void render_textures(stack_t *s, int id)
{
    list *temp = s->head;
    while(temp!=NULL)
    {
        handle_types(temp, id);
        temp = temp->next;
    }
}
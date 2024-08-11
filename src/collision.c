#include "collision.h"
void collide_with_all(sprite *obj, stack_t *s)
{
    list *temp = s->head;
    while(temp!=NULL)
    {
        if(temp->type!=SPRITE_T || obj == (sprite*)(temp->val))
        {
            temp = temp->next;
            continue;
        }
        if(temp->type==SPRITE_T && ((sprite*)(temp->val))->sprite_type == NON_INTERACT)
        {
            temp = temp->next;
            continue;
        }
        SDL_Rect intersect;
        if(SDL_IntersectRect(obj->box, ((sprite*)(temp->val))->box, &intersect)==SDL_TRUE)
        {
            if(((sprite*)(temp->val))->sprite_type == INTERACTABLE_T)
            {
                temp = temp->next;
                continue;
            }
            if(intersect.w > intersect.h)
            {
                printf("horizontal\n");
                if(obj->box->y > ((sprite*)(temp->val))->box->y)
                {
                    set_zero(UP);
                }
                else{
                    set_zero(DOWN);
                }
            }
            if(intersect.w < intersect.h)
            {
                printf("vertical\n");
                if(obj->box->x > ((sprite*)(temp->val))->box->x)
                {
                    set_zero(LEFT);
                }
                else{
                    set_zero(RIGHT);
                }
            }
        }
        temp = temp->next;
    }
}

void do_collision(stack_t *s)
{
    list *temp = s->head;
    while(temp!=NULL)
    {
        if(temp->type==SPRITE_T && ((sprite*)(temp->val))->sprite_type == PLAYER_T)
        {
            collide_with_all((sprite*)(temp->val), s);
        }
        temp = temp->next;
    }
}
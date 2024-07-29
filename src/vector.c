#include "vector.h"
#include <math.h>

void float_to_int_vector(vector *v_int, vectorf *v)
{
    v_int->x = (int)v->x;
    v_int->y = (int)v->y;
}

void norm(vectorf *v){
    float length = sqrt((v->x * v->x) + (v->y * v->y));
    if(length == 0){
        return;
    }
    v->x = v->x/length;
    v->y = v->y/length;
}
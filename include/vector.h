#ifndef VECTOR
#define VECTOR

struct vector_t
{
    int x;
    int y;
};

struct vectorf_t
{
    float x;
    float y;
};

typedef struct vector_t vector;
typedef struct vectorf_t vectorf;
void float_to_int_vector(vector *v_int, vectorf *v);
void norm(vectorf *v);
#endif
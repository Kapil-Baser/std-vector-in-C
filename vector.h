#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include <stdio.h>

typedef struct vector
{
    size_t size, capacity;
    int *array;
}vector;

vector *construct(vector *self, size_t size, int value);


#endif /* VECTOR_H */
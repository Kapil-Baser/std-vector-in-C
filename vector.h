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
void push_back(vector *self, int value);
size_t size(vector *self);
size_t capacity(vector *self);
int pop(vector *self);
int front(vector *self);
int back(vector *self);

#endif /* VECTOR_H */
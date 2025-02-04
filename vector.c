#include "vector.h"

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

vector *construct(vector *self, size_t size, int value)
{
    self->size = self->capacity = size;
    self->array = malloc(sizeof(int) * self->capacity);
    if (self->array == NULL)
    {
        terminate("Memory allocation failed.");
    }

    for (size_t i = 0; i < self->size; i++)
    {
        self->array[i] = value;
    }
    return (self);
}

void push_back(vector *self, int value)
{
    if (self->size == 0)
    {
        self->size = self->capacity = 1;
        self->array = malloc(sizeof(int) * self->capacity);
        if (self->array == NULL)
        {
            terminate("Memory allocation failed.");
        }
        self->array[0] = value;
    }
    else if (self->size == self->capacity)
    {
        self->capacity *= 2;
        int *new = realloc(self->array, self->capacity);
        if (new == NULL)
        {
            fprintf(stderr, "Reallocation failed.\n");
        }
        self->array = new;
        self->array[self->size++] = value;
    }
    else
    {
        self->array[self->size++] = value;
    }
}

size_t size(vector *self)
{
    return self->size;
}

size_t capacity(vector *self)
{
    return self->capacity;
}

int pop(vector *self)
{
    int temp;
    if (self->array == NULL && self->size == 0)
    {
        return -1;
    }
    temp = self->array[--self->size];
    self->array[self->size] = 0;
    return temp;
}

int front(vector *self)
{
    if (self->array != NULL)
    {
        return self->array[0];
    }
    return -1;
}

int back(vector *self)
{
    if (self->array != NULL)
    {
        return self->array[self->size - 1];
    }
    return -1;
}

void shrink_to_fit(vector *self)
{
    if (self->array == NULL || self->size == self->capacity)
    {
        return;
    }
    int *new = realloc(self->array, self->size);
    if (new == NULL)
    {
        fprintf(stderr, "Shrinking failed.\n");
        return;
    }
    self->array = new;
    self->capacity = self->size;
}

void destuctor(vector *self)
{
    free(self->array);
    self->array = NULL;
    self->size = 0;
    self->capacity = 0;
}
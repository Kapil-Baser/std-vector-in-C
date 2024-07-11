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
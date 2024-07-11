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
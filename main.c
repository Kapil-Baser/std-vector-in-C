#include "vector.h"


int main(void)
{
    vector array;

    construct(&array, 1, 5);
    push_back(&array, 10);
    int t = pop(&array);
    return 0;
}
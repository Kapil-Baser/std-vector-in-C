#include "vector.h"


int main(void)
{
    vector array;

    construct(&array, 0, 0);
    push_back(&array, 10);
    return 0;
}
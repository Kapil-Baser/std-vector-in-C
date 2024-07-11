#include "vector.h"


int main(void)
{
    vector array;

    construct(&array, 1, 5);
    push_back(&array, 10);
    push_back(&array, 15);
    push_back(&array, 20);
    push_back(&array, 21);
    printf("The front of the array is: %d\n", front(&array));
    printf("The back of the array is: %d\n", back(&array));
    printf("The capacity of array is: %ld\n", capacity(&array));
    shrink_to_fit(&array);
    printf("The capacity of array is: %ld\n", capacity(&array));

    destuctor(&array);
    return 0;
}
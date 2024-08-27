#include "../headers/intArray.h"


#define getName(var) #var


int main() {
    const size_t sizeX = 3;
    int array[][sizeX] = {
        {11, 12, 12313},
        {21, 22, 23   }, 
        {31, 32, 33   }, 
        {41, 42, 43   }};
    const size_t sizeY = sizeof(array) / sizeof(array[0]);

    intArray intArray = {
        .sizeX = sizeX,
        .sizeY = sizeY,
        .data  = (int*) array,
        .name  = getName(intArray)
    };
    PrintIntArray(&intArray);

    return 0;
}
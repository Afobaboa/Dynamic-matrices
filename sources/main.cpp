#include <assert.h>
#include <stdio.h>
#include "../headers/matrix.h"


#define getName(var) #var


int main() {
    const size_t sizeX = 3;
    int rectangleArray[][sizeX] = {
        {11, 12, 12313},
        {21, 22, 23   }, 
        {31, 32, 33   }, 
        {41, 42, 43   }};
    const size_t sizeY = sizeof(rectangleArray) / sizeof(rectangleArray[0]);

    rectangleIntArray rectangleIntArray = {
        .sizeX = sizeX,
        .sizeY = sizeY,
        .data  = (int*) rectangleArray,
        .name  = getName(rectangleIntArray)
    };

    PrintRectangleIntArray(&rectangleIntArray);

    puts("");

    const size_t basementSize = 5;
    int triangleArray[] = {
        1,
        2,  3,
        4,  5,  6,
        7,  8,  9,  10,
        11, 12, 13, 14, 15
    };
    assert(sizeof(triangleArray) / sizeof(triangleArray[0]) ==
                        GetTriangleArraySize(basementSize));

    triangleIntArray triangleIntArray = {
        .basementSize = basementSize,
        .data = (int*) triangleArray,
        .name = getName(triangleIntArray)
    };
    PrintTriangleIntArray(&triangleIntArray);

    return 0;
}
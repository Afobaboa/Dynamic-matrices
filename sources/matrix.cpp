#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include "../headers/coloredIO.h"
#include "../headers/matrix.h"


static size_t GetTriangleShift(size_t lineNum);


void PrintMatrix(matrix* matrix) {
    printf("There is %s\n\n", array->name);

    printf("x = %3s", "");
    for (size_t x = 0; x < array->sizeX; x++)
        printf("%6zu ", x);
    puts("");

    for (size_t y = 0; y < array->sizeY; y++) {
        printf("y = %3zu ", y);
        for (size_t x = 0; x < array->sizeX; x++)
            ColoredPrintf(YELLOW, "%6d ", *(array->data + array->sizeX + x));
        puts("");
    }
}


void PrintTriangleIntArray(triangleIntArray* array) {
    for (size_t lineNum = 1; lineNum <= array->basementSize; lineNum++) {
        for (size_t x = 0; x < lineNum; x++) 
            ColoredPrintf(YELLOW, "%6d", *(array->data + GetTriangleShift(lineNum) + x));
        puts("");
    }
}


size_t GetTriangleArraySize(size_t basementSize) {
    return (basementSize+1) * basementSize / 2;
}


static size_t GetTriangleShift(size_t lineNum) {
    return (lineNum-1) * lineNum / 2;
}



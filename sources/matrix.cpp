#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include "../headers/coloredIO.h"
#include "../headers/matrix.h"


/**
 * @param lineNum Number of line 
 * that you processing.
 * 
 * @return Shift for correct 
 * processing lines of 
 * dataTriangle
 */
static size_t GetTriangleShift(size_t lineNum);


void PrintMatrix(matrix* matrix) {
    printf("There is %s\n\n", matrix->name);

    printf("x = %3s", "");
    for (size_t x = 0; x < matrix->sizeX; x++)
        printf("%6zu ", x);
    printf("\n");

    for (size_t y = 0; y < matrix->sizeY; y++) {
        printf("y = %3zu ", y);
        for (size_t x = 0; x < matrix->sizeX; x++)
            ColoredPrintf(YELLOW, "%6d ", *(matrix->data + matrix->sizeX + x));
        printf("\n");
    }
}


void PrintTriangle(dataTriangle* dataTriangle) {
    for (size_t lineNum = 1; lineNum <= dataTriangle->basementSize; lineNum++) {
        for (size_t x = 0; x < lineNum; x++) 
            ColoredPrintf(YELLOW, "%6d", *(dataTriangle->data + GetTriangleShift(lineNum) + x));
        printf("\n");
    }
}


size_t GetTriangleSize(size_t basementSize) {
    return (basementSize+1) * basementSize / 2;
}


static size_t GetTriangleShift(size_t lineNum) {
    return (lineNum-1) * lineNum / 2;
}
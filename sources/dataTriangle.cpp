#include <stdio.h>
#include "../headers/inputHandler.h"
#include "../headers/dataTriangle.h"
#include "../headers/coloredOutput.h"


/**
 * @param lineNum Number of line 
 * that you processing.
 * 
 * @return Shift for correct 
 * processing lines of 
 * dataTriangle
 */
static size_t GetTriangleShift(size_t lineNum);


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
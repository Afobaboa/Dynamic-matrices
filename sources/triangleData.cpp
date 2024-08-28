#include <stdio.h>
#include "../headers/inputHandler.h"
#include "../headers/triangleData.h"
#include "../headers/coloredOutput.h"


/**
 * @param lineNum Number of line 
 * that you processing.
 * 
 * @return Shift for correct 
 * processing lines of 
 * dataTriangle
 */
static size_t TriangleGetShift(const size_t lineNum);


void TrianglePrint(const TriangleData* triangleData) {
    for (size_t lineNum = 1; lineNum <= triangleData->basementSize; lineNum++) {
        for (size_t x = 0; x < lineNum; x++) 
            ColoredPrintf(YELLOW, "%6d", *(triangleData->data + TriangleGetShift(lineNum) + x));
        printf("\n");
    }
}


size_t TriangleGetSize(const size_t basementSize) {
    return (basementSize+1) * basementSize / 2;
}


static size_t TriangleGetShift(const size_t lineNum) {
    return (lineNum-1) * lineNum / 2;
}
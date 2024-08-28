#include <assert.h>
#include <stdio.h>
#include "../headers/matrix.h"


int main() {
    Matrix firstMatrix = { 
        .sizeX = 0,
        .sizeY = 0,
        .data  = NULL
    };
    if (!MatrixSet(&firstMatrix)) {
        printf("# Пока!\n");
        return 0;
    }
    MatrixPrint(&firstMatrix);

    Matrix secondMatrix = {  // FIXME: copypaste
        .sizeX = 0,
        .sizeY = 0,
        .data  = NULL
    };
    if (!MatrixSet(&secondMatrix)) {
        printf("# Пока!\n");
        return 0;
    }
    MatrixPrint(&firstMatrix);

    Matrix sumMatrix = { 
        .sizeX = 0,
        .sizeY = 0,
        .data  = NULL
    };
    if (!MatrixSum(&firstMatrix, &secondMatrix, &sumMatrix)) {
        printf("# Мда, чел...\n");
        return 0;
    }

    printf("Результат сложения матриц:\n");
    MatrixPrint(&sumMatrix);

    MatrixDelete(&firstMatrix);
    MatrixDelete(&secondMatrix);
    MatrixDelete(&sumMatrix);
        
    return 0;
}
#include <assert.h>
#include <stdio.h>
#include "../headers/matrix.h"


int main() {
    Matrix firstMatrix;
    MatrixInit(&firstMatrix);
    if (!MatrixSet(&firstMatrix)) {
        printf("# Пока!\n");
        return 0;
    }
    MatrixPrint(&firstMatrix);

    Matrix secondMatrix;
    MatrixInit(&secondMatrix);
    if (!MatrixSet(&secondMatrix)) {
        printf("# Пока!\n");
        return 0;
    }
    MatrixPrint(&secondMatrix); 

    Matrix sumMatrix;
    MatrixInit(&sumMatrix);
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
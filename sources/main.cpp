#include <assert.h>
#include <stdio.h>
#include "../headers/inputHandler.h"
#include "../headers/jaggedArray.h"
#include "../headers/matrix.h"


static void MatrixSummation();
static void JaggedArrayPrinting();
static void ProcessMode(menuMode_t mode);


int main() {
    puts("# Привет! Эту программу можно использовать как калькулятор матриц или "
         "принтер рваных массивов.\n"
         "# НЕ ЗАБУДЬ: для выхода из программы жми ctrl+D");

    menuMode_t mode = GetMode();
    ProcessMode(mode);

    puts("# Пока");
        
    return 0;
}


static void MatrixSummation() {
    Matrix firstMatrix;
    MatrixInit(&firstMatrix);
    if (!MatrixSet(&firstMatrix)) {
        printf("# Пока!\n");
        MatrixDelete(&firstMatrix);
        return;
    }
    MatrixPrint(&firstMatrix);

    Matrix secondMatrix;
    MatrixInit(&secondMatrix);
    if (!MatrixSet(&secondMatrix)) {
        printf("# Пока!\n");
        MatrixDelete(&firstMatrix);
        MatrixDelete(&secondMatrix);
        return;
    }
    MatrixPrint(&secondMatrix); 

    Matrix sumMatrix;
    MatrixInit(&sumMatrix);
    if (!MatrixSum(&firstMatrix, &secondMatrix, &sumMatrix)) {
        printf("# Мда, чел...\n");
        MatrixDelete(&firstMatrix);
        MatrixDelete(&secondMatrix);
        return;
    }

    printf("Результат сложения матриц:\n");
    MatrixPrint(&sumMatrix);

    MatrixDelete(&firstMatrix);
    MatrixDelete(&secondMatrix);
    MatrixDelete(&sumMatrix);
}


static void JaggedArrayPrinting() {
    JaggedArray array;
    JaggedArrayInit(&array);
    if (!JaggedArraySet(&array))
        return;
    JaggedArrayPrint(&array);
    JaggedArrayDelete(&array);
}


static void ProcessMode(menuMode_t mode) {
    switch (mode) {
    case MATRIX_SUMMATION:
        MatrixSummation();
        break;
    case JAGGED_ARRAY_PRINTING:
        JaggedArrayPrinting();
        break;
    case END_INPUT:
        break;
    default:
        fprintf(stderr, "%s: %s(): ERROR in line %d, mode isn't defined.",
                        __FILE__, __FUNCTION__, __LINE__                  );
        break;
    }
}
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include "../headers/inputHandler.h"
#include "../headers/coloredOutput.h"
#include "../headers/matrix.h"


/**
 * This function print 
 * special message if user
 * close this program.
 */
static void PrintEndMessage() {
    puts("# Пока!");
}


/**
 * This function compare
 * sizes of two matrixes.
 * 
 * @return true if sizeX and
 * sizeY of matrixes are equal.
 * @return false in other
 * situations.
 */
static bool AreMatrixesEqualInSize(matrix* firstMatrix, 
                                   matrix* secondMatrix);


/**
 * This function set size
 * of matrix.
 * 
 * @param matri Matrix, which 
 * size will be set.
 * 
 * @return true if size was set,
 * @return false in other
 * situations.
 */
static bool SetMatrixSize(matrix* matrix);


/**
 * This function set data
 * of matrix. You should 
 * set size of this matrix
 * before using this
 * function.
 * 
 * @param matrix Matrix which 
 * data will be set.
 * 
 * @return true if setting
 * is complete,
 * @return false in other 
 * situations.
 */
static bool SetMatrixData(matrix* matrix);


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


bool matrixSum(matrix* firstMatrix,
               matrix* secondMatrix,
               matrix* answerMatrix) {
    if (!AreMatrixesEqualInSize(firstMatrix, secondMatrix)) {
        fprintf(stderr, "%s: %s(): ERROR in line %d. You can't sum "
                        "different in size matrixes.",
                        __FILE__, __FUNCTION__, __LINE__);
        return false;
    }
    for (int y = 0; y < answerMatrix->sizeY; y++)
        for (int x = 0; x < answerMatrix->sizeX; x++)
            *(answerMatrix->data + y*answerMatrix->sizeX + x) =
            *( firstMatrix->data + y*answerMatrix->sizeX + x) +
            *(secondMatrix->data + y*answerMatrix->sizeX + x);
    return true;
}


static bool AreMatrixesEqualInSize(matrix* firstMatrix,
                                   matrix* secondMatrix) {
    if (firstMatrix->sizeX == secondMatrix->sizeX &&
        firstMatrix->sizeY == secondMatrix->sizeY   )
        return true;
    else 
        return false;
}


bool SetMatrix(matrix* matrix) {
    if (!SetMatrixSize(matrix))
        return false;
    if (!SetMatrixData(matrix)) 
        return false;
    return true;
}


static bool SetMatrixSize(matrix* matrix) {
    puts("# Введите размер матрицы по горизонтали:");
    int value = 0;
    if (!GetIntValue(&value)) {
        PrintEndMessage;
        return false;
    }
    matrix->sizeX = (size_t) value;

    puts("# Введите размер матрицы по вертикали:");
    int value = 0;
    if (!GetIntValue(&value)) {
        PrintEndMessage;
        return false;
    }
    matrix->sizeY = (size_t) value;

    return true;
}
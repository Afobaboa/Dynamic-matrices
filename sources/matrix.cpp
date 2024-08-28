#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include "../headers/inputHandler.h"
#include "../headers/coloredOutput.h"
#include "../headers/matrix.h"

// TODO: matrixMul (2 штуки)
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
static bool AreMatrixesEqualInSize(const Matrix* firstMatrix, 
                                   const Matrix* secondMatrix);


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
static bool SetMatrixSize(Matrix* matrix);


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
static bool MatrixSetData(Matrix* matrix);


void MatrixPrint(const Matrix* matrix) {
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

// FIXME: add function
// int matrixGetElem(matrix, x, y);
// void matrixSetElem(matrix, x, y, value)
//            const
bool MatrixSum(const Matrix* firstMatrix, const Matrix* secondMatrix,
                                                Matrix* answerMatrix ) {
    if (!AreMatrixesEqualInSize(firstMatrix, secondMatrix)) {
        ColoredPrintf(RED, "Нельзя суммировать матрицы разных размеров.\n");
        return false;
    }

    for (int i = 0; i < answerMatrix->sizeX + answerMatrix->sizeY; i++)
        answerMatrix->data[i] = firstMatrix->data[i] + secondMatrix->data[i];
    return true;
}


static bool AreMatricesEqualInSize(const Matrix* firstMatrix,
                                   const Matrix* secondMatrix) {
    if (firstMatrix->sizeX == secondMatrix->sizeX &&
        firstMatrix->sizeY == secondMatrix->sizeY   )
        return true;
    else 
        return false;
}


bool MatrixSet(Matrix* matrix) {
    if (!MatrixSetSize(matrix))
        return false;
    if (!MatrixSetData(matrix)) 
        return false;
    return true;
}


static bool MatrixSetSize(Matrix* matrix) {
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
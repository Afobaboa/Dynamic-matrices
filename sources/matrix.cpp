#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../headers/inputHandler.h"
#include "../headers/coloredOutput.h"
#include "../headers/matrix.h"

// TODO: matrixMul (2 штуки)

/**
 * This function compare
 * sizes of two matrixes.
 * 
 * @return true if sizeX and
 * sizeY of matrixes are equal.
 * @return false in other
 * situations.
 */
static bool AreMatricesEqualInSize(const Matrix* firstMatrix, 
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
static bool MatrixSetSize(Matrix* matrix);


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


/**
 * This function help you
 * to get elems of matrix
 * using their coordinates.
 * 
 * @param matrix Matrix, where will be searching.
 * @param x      x coordinate of elem.
 * @param y      y coordinate of elem.
 * 
 * @return Pointer to (x,y) elem,
 * @return NULL if (x,y) doesn't
 * exist in this matrix.
 */
static int* MatrixGetElem(const Matrix* matrix,
                          const size_t x, const size_t y);


void MatrixPrint(const Matrix* matrix) {
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


bool MatrixSum(const Matrix* firstMatrix, const Matrix* secondMatrix,
                                                Matrix* answerMatrix ) {
    if (!AreMatricesEqualInSize(firstMatrix, secondMatrix)) {
        ColoredPrintf(RED, "Нельзя суммировать матрицы разных размеров.\n");
        return false;
    }

    for (size_t i = 0; i < answerMatrix->sizeX + answerMatrix->sizeY; i++)
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


bool MatrixSetSize(Matrix* matrix) {
    puts("# Введите размер матрицы по горизонтали:");
    int value = 0;
    if (!GetIntValue(&value)) {
        return false;
    }
    matrix->sizeX = (size_t) value;

    puts("# Введите размер матрицы по вертикали:");
    if (!GetIntValue(&value)) {
        return false;
    }
    matrix->sizeY = (size_t) value;

    return true;
}


bool MatrixSetData(Matrix* matrix) {
    assert(!matrix->data);
    matrix->data = (int*) calloc(matrix->sizeX * matrix->sizeY,
                                                   sizeof(int) );
    for (size_t y = 0; y < matrix->sizeY; y++) {
        printf("# Введите %zu строку матрицы: \n", y+1);
        for (size_t x = 0; x < matrix->sizeX; x++) 
            if (!GetIntValue(MatrixGetElem(matrix, x, y)))
                return false;
        printf("\n");
    }
    printf("\n");
    return true;
}


static int* MatrixGetElem(const Matrix* matrix,
                          const size_t x, const size_t y) {
    if (x > matrix->sizeX ||
        y > matrix->sizeY   )
        return NULL;
    return matrix->data + y * matrix->sizeX + x;
}


void MatrixDelete(Matrix* matrix) {
    assert(!matrix->data);
    free(matrix->data);
    matrix->data  = NULL;
    matrix->sizeX = 0;
    matrix->sizeY = 0;
}
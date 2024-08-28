#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../headers/inputHandler.h"
#include "../headers/coloredOutput.h"
#include "../headers/matrix.h"

// TODO:
// ограничить размер матриц и элементов
// проверить нумерацию столбцов и строк везде


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
static int MatrixGetElem(const Matrix* matrix,
                         const size_t x, const size_t y);


/**
 * This function find
 * pointer to first elem
 * of y line.
 * 
 * @param matrix Matrix in
 * wich you want to find line.
 * @param y      Number of 
 * line.
 * 
 * @return Pointer to first
 * elem of choosed line.
 * @return NULL if there
 * isn't choosed line.
 */
static int* GetLinePtr(const Matrix* matrix, const size_t y);


void MatrixPrint(const Matrix* matrix) {
    printf("x = %3s ", "");
    for (size_t x = 0; x < matrix->sizeX; x++)
        printf("%6zu ", x);
    printf("\n");

    for (size_t y = 0; y < matrix->sizeY; y++) {
        printf("y = %3zu ", y);
        for (size_t x = 0; x < matrix->sizeX; x++)
            ColoredPrintf(YELLOW, "%6d ", MatrixGetElem(matrix, x, y)); // FIXME: error handling
        printf("\n");
    }
}


bool MatrixSum(const Matrix* firstMatrix, const Matrix* secondMatrix,
                                                Matrix* answerMatrix ) {
    if (!AreMatricesEqualInSize(firstMatrix, secondMatrix)) {
        ColoredPrintf(RED, "Нельзя суммировать матрицы разных размеров.\n");
        return false;
    }

    answerMatrix->sizeX = firstMatrix->sizeX; // FIXME: this looks strange
    answerMatrix->sizeY = firstMatrix->sizeY;
    answerMatrix->data  = (int*) calloc(answerMatrix->sizeX * answerMatrix->sizeY,
                                                                      sizeof(int) );

    for (size_t i = 0; i < answerMatrix->sizeX * answerMatrix->sizeY; i++)
        (answerMatrix->data)[i] = (firstMatrix->data)[i] + (secondMatrix->data)[i];
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


bool MatrixSet(Matrix* matrix) { // FIXME: bad input, needed to fix
    if (!MatrixSetSize(matrix))
        return false;
    if (!MatrixSetData(matrix)) 
        return false;
    return true;
}


bool MatrixSetSize(Matrix* matrix) {
    printf("# Введите размер матрицы по горизонтали (не больше %zu):\n", MAX_MATRIX_SIZE);
    if (!SetSize(&matrix->sizeX)) {
        return false;
    } 

    printf("# Введите размер матрицы по вертикали (не больше %zu):\n", MAX_MATRIX_SIZE);
    if (!SetSize(&matrix->sizeY)) {
        return false;
    }

    return true;
}


bool MatrixSetData(Matrix* matrix) {
    if (!matrix->data) {
        free(matrix->data);
        matrix->data = NULL;
    }
    matrix->data = (int*) calloc(matrix->sizeX * matrix->sizeY,
                                                   sizeof(int) );
    for (size_t y = 0; y < matrix->sizeY; y++) {
        printf("# Введите %zu строку матрицы: \n", y+1);
        if (!SetLine(GetLinePtr(matrix, y), matrix->sizeX))
                return false;
    }
    printf("\n");
    return true;
}


static int MatrixGetElem(const Matrix* matrix,
                             const size_t x, const size_t y) {
    assert(!(x > matrix->sizeX ||
             y > matrix->sizeY   ));
    return matrix->data[y * matrix->sizeX + x];
}


void MatrixDelete(Matrix* matrix) {
    if (!matrix->data)
        fprintf(stderr, "%s: %s(): ERROR in line %d, data is free.\n",
                        __FILE__, __FUNCTION__, __LINE__);
    free(matrix->data);
    matrix->data  = NULL;
    matrix->sizeX = 0;
    matrix->sizeY = 0;
}


static int* GetLinePtr(const Matrix* matrix, const size_t y) {
    if (y > matrix->sizeY) 
        return NULL;
    return matrix->data + y * matrix->sizeX;
}


void MatrixInit(Matrix* matrix) {
    if (!matrix->data)
        free(matrix->data);
    matrix->data  = NULL;
    matrix->sizeX = 0;
    matrix->sizeY = 0;
}
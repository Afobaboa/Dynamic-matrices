#ifndef ARRAYS_H
#define ARRAYS_H


#include <stddef.h>


/**
 * This struct needed to
 * help user to interact
 * with two-dimensional 
 * arrays matrix[sizeY][sizeX].
 */
struct Matrix {
    size_t      sizeX;    /**< Width (horizon, x) of matrix.       */
    size_t      sizeY;    /**< Height (vertical, y) of matrix.     */
    int*        data;     /**< Pointer to first element of matrix. */
    const char* name;     /**< Name of matrix. Need for printing.  */
};


/**
 * This function prints
 * matrix to stdin.
 * 
 * @param matrix Matrix to print.
 */
void MatrixPrint(const Matrix* matrix);


/**
 * This function sum two matrixes.
 * answerMatrix = firstMatrix + secondMatrix.
 * 
 * @param firstMatrix  First matrix.
 * @param secondMatrix Second matrix.
 * @param answerMatrix There will be 
 * result of sum.
 * 
 * @return true if addition was
 * successful,
 * @return false in other
 * situations.
 */
bool MatrixSum(const Matrix* firstMatrix, const Matrix* secondMatrix,
                                                Matrix* answerMatrix );


/**
 * This function print 
 * hints to stdin for
 * help user to initialize
 * fields of matrix.
 * 
 * @param matrix Matrix that
 * will be set.
 * 
 * @return true if setting 
 * will be complete,
 * @return false in other
 * situations.
 */
bool MatrixSet(Matrix* matrix);


#endif // ARRAYS_H
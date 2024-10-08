#ifndef MATRIX_H
#define MATRIX_H


#include <stddef.h>


/**
 * This struct needed to
 * help user to interact
 * with two-dimensional 
 * arrays matrix[sizeY][sizeX].
 */
struct Matrix {
    size_t sizeX;    /**< Width (horizon, x) of matrix.       */
    size_t sizeY;    /**< Height (vertical, y) of matrix.     */
    int*   data;     /**< Pointer to first element of matrix. */
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


/**
 * This function is clear 
 * memory and set int 
 * parameters of matrix 
 * to zeros and set
 * pointer to data to NULL.
 * 
 * Multiple using is safe
 * but not recomended.
 * 
 * @param matrix Matrix that
 * you want to delete
 */
void MatrixDelete(Matrix* matrix);


/**
 * Init matrix with
 * zeroes and null.
 * 
 * @param matrix Matrix 
 * that you want to init.
 */
void MatrixInit(Matrix* matrix);


#endif // MATRIX_H
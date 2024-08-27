#ifndef ARRAYS_H
#define ARRAYS_H


#include <stddef.h>


/**
 * This struct needed to
 * help user to interact
 * with two-dimensional 
 * arrays matrix[sizeY][sizeX].
 */
struct matrix {
    const size_t sizeX;    /**< Width (horizon, x) of matrix.       */
    const size_t sizeY;    /**< Height (vertical, y) of matrix.     */
          int*   data;     /**< Pointer to first element of matrix. */
    const char*  name;     /**< Name of matrix. Need for printing.  */
};


/**
 * This function prints
 * matrix to stdin.
 * 
 * @param matrix Matrix to print.
 */
void PrintMatrix(matrix* matrix);


/**
 * This function sum two matrixes.
 * answerMatrix = firstMatrix + 
 *                secondMatrix.
 * 
 * @param firstMatrix  First matrix.
 * @param secondMatrix Second matrix.
 * @param answerMatrix There will be 
 * result of sum.
 * 
 * @return true if addition was
 * successful.
 * @return false in other
 * situations.
 */
bool matrixSum(matrix* firstMatrix,
               matrix* secondMatrix,
               matrix* answerMatrix);


#endif // ARRAYS_H
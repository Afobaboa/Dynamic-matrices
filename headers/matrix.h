#ifndef ARRAYS_H
#define ARRAYS_H


#include <stddef.h>


/**
 * This struct needed to
 * help user to interact
 * with two-dimensional 
 * arrays matrix[sizeY][sizeX]
 */
struct matrix {
    const size_t sizeX;    /**< Width (horizon, x) of matrix       */
    const size_t sizeY;    /**< Height (vertical, y) of matrix     */
          int*   data;     /**< pointer to first element of matrix */
    const char*  name;
};


struct dataTriangle {
    const size_t basementSize;
          int*   data;
    const char*  name;
};


void PrintMatrix(matrix* matrix);
void PrintTriangle(dataTriangle* dataTriangle);
size_t GetTriangleSize(size_t basementSize);


#endif // ARRAYS_H
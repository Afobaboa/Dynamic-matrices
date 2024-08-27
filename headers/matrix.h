#ifndef ARRAYS_H
#define ARRAYS_H


#include <stddef.h>


struct matrix {
    const size_t sizeX;
    const size_t sizeY;
          int*   data;
    const char*  name;
};


struct dataTriangle {
    const size_t basementSize;
          int*   data;
    const char*  name;
};


void PrintMatrix(matrix* matrix);
void PrintDataTriangle(dataTriangle* dataTriangle);
size_t GetTriangleArraySize(size_t basementSize);


#endif // ARRAYS_H
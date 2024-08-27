#ifndef ARRAYS_H
#define ARRAYS_H


#include <stddef.h>


struct intArray {
    const size_t sizeX;
    const size_t sizeY;
          int*   data;
    const char*  name;
};


void PrintIntArray(intArray* intArray);


#endif // ARRAYS_H
#ifndef DATA_TRIANGLE_H
#define DATA_TRIANGLE_H


#include <stddef.h>


/**
 * @file
 * This file is don't 
 * used in my project now
 * and you can delete it
 * if you want to use my 
 * program.
 */


/**
 * This struct is like 
 * matrix, but its shape
 * isn't a rectangle. 
 * That's a triangle!
 */
struct TriangleData {
    size_t basementSize;  /**< Count of element at last line.    */
    size_t elemsCount;    /**< Count of elements of data.        */
    int*   data;          /**< Pointer to first element of data. */
};


/**
 * This function prints
 * data of triangle using
 * triangle shape!!!
 * 
 * @param triangleData Triangle to print.
 */
void TrianglePrint(const TriangleData* triangleData);


/**
 * This function needed 
 * for error handling.
 * 
 * @param basementSize Count of
 * triangle basement elements.
 * 
 * @return Count of all elements
 * form data.
 */
size_t TriangleGetSize(const size_t basementSize);


#endif // DATA_TRIANGLE_H
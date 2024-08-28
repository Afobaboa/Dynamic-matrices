#ifndef DATA_TRIANGLE_H
#define DATA_TRIANGLE_H


#include <stddef.h>


/**
 * This struct is like 
 * matrix, but its shape
 * isn't a rectangle. 
 * That's a triangle!
 */
struct TriangleData {
    size_t       basementSize;  /**< Count of element at last line.         */
    int*         data;          /**< Pointer to first element of data.      */
    const char*  name;          /**< Name of triangle. Needed for printing. */
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
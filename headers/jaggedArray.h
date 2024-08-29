#ifndef JAGGED_ARRAY_H
#define JAGGED_ARRAY_H


#include <stddef.h>


/**
 * There is jagged array.
 */
struct JaggedArray {
    size_t  lineCount;   /**< Count of lines.                       */
    int**   lineStart;   /**< Array of pointers to starts of lines. */
    size_t* lineLength;  /**< Array of sizes of lines.              */
};


/**
 * This function prints
 * hints for user to terminal
 * and set all data of struct
 * Jagged Array.
 * 
 * @param array Jagged array
 * which data you want to set.
 * 
 * @return true if setting 
 * was complete,
 * @return false in other
 * situations.
 */
bool JaggedArraySet(JaggedArray* array); 


/**
 * This function prints
 * JaggedArray. Each line
 * is beginning by new
 * line.
 * 
 * @param jaggedArray Array
 * you want to print.
 */
void JaggedArrayPrint(JaggedArray* array);


/**
 * This function init
 * your jagged array 
 * by nulls and zeroes.
 * 
 * USE IT ONLY FOR 
 * INITIALIZATION 
 * YOUR ARRAY BEFORE
 * SETTING.
 * 
 * @param array jagged
 * array you want to init.
 */
void JaggedArrayInit(JaggedArray* array);


/**
 * This function clean
 * memory of your jagged
 * array and sets params 
 * of array to zeroes and
 * nulls.
 * 
 * @param array Jagged
 * array you want to delete.
 */
void JaggedArrayDelete(JaggedArray* array);


#endif // JAGGED_ARRAY_H
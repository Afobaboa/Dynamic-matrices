#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/inputHandler.h"
#include "../headers/jaggedArray.h"


/**
 * This function asks 
 * user how many lines 
 * he want in his array.
 * 
 * @param array Jagged
 * array which count of
 * lines you want to set.
 * 
 * @return true if setting
 * is completed,
 * @return false in other 
 * situations
 */
static bool JaggedArraySetLineCount(JaggedArray* array);


/** 
 * This function asks
 * user how many elements
 * should be in line and
 * help user to set each
 * elem.
 * 
 * @param array Jagged 
 * array which line you
 * want to set.
 * @param lineNum Number
 * of array's line you
 * want to set.
 * 
 * @return true if setting
 * is completed,
 * @return false in other 
 * situations.
 */
static bool JaggedArraySetLine(JaggedArray* array, const size_t lineNum);


bool JaggedArraySet(JaggedArray* array) {
    if (!JaggedArraySetLineCount(array))
        return false;

    for (size_t lineNum = 0; lineNum < array->lineCount; lineNum++) 
        if (!JaggedArraySetLine(array, lineNum))
            return false;
    
    return true;
}


void JaggedArrayPrint(JaggedArray* array) {
    printf("\n");
    for (size_t lineNum = 0; lineNum < array->lineCount; lineNum++) {
        for (size_t elemNum = 0; elemNum < array->lineLength[lineNum]; elemNum++)
            printf("%d ", array->lineStart[lineNum][elemNum]);   // FIXME: make more safe
        printf("\n");
    }
}


void JaggedArrayInit(JaggedArray* array) {
    assert(array->lineStart);
    assert(array->lineStart);

    array->lineCount  = 0;
    array->lineLength = NULL;
    array->lineStart  = NULL;
}


void JaggedArrayDelete(JaggedArray* array) {
    for (size_t lineNum = 0; lineNum < array->lineCount; lineNum++) {
        free(array->lineStart[lineNum]);
        array->lineStart[lineNum] = NULL;
    }
    free(array->lineStart);
    free(array->lineLength);

    array->lineCount = 0;
    array->lineStart = NULL;
    array->lineLength  = NULL; 
}


static bool JaggedArraySetLineCount(JaggedArray* array) {
    puts("# Введите количество строк рваного массива:");

    if (!SetSize(&array->lineCount))
        return false; 
    
    array->lineLength = (size_t*) calloc(array->lineCount, sizeof(size_t));
    array->lineStart  = (int**)   calloc(array->lineCount, sizeof(int*)); // FEXME: NULL handling

    assert(array->lineLength);
    assert(array->lineStart);

    return true;
}


static bool JaggedArraySetLine(JaggedArray* array, const size_t lineNum) {
    printf("# Введите количество элементов в %zu строке.\n", lineNum);

    assert(&(array->lineLength)[lineNum]);
    if (!SetSize(&(array->lineLength)[lineNum]))
        return false;

    array->lineStart[lineNum] = (int*) calloc(array->lineLength[lineNum], sizeof(int)); // FIXME: add null handling
    assert(array->lineStart[lineNum]);

    if (!SetLine(array->lineStart[lineNum], array->lineLength[lineNum]))
        return false;
    
    return true;
}
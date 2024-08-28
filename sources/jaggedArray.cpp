#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/inputHandler.h"
#include "../headers/jaggedArray.h"


bool JaggedArraySet(JaggedArray* jaggedArray) {


    return true;
}


void JaggedArrayInit(JaggedArray* array) {
    assert(array->lineStart);
    assert(array->lineStart);

    array->lineCount = 0;
    array->lineSize  = NULL;
    array->lineStart = NULL;
}


void JaggedArrayDelete(JaggedArray* array) {
    for (size_t lineNum = 0; lineNum < array->lineCount; lineNum++) {
        free(array->lineStart);
        array->lineStart[lineNum] = NULL;
    }
    free(array->lineStart);
    free(array->lineSize);

    array->lineCount = 0;
    array->lineStart = NULL;
    array->lineSize  = NULL; 
    
}
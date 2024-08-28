#include <assert.h>
#include <stdio.h>
#include "../headers/matrix.h"


int main() {
    Matrix matrix = {
        .sizeX = 0,
        .sizeY = 0,
        .data  = NULL
    };
    if (!MatrixSet(&matrix)) {
        printf("# Пока!\n");
        return 0;
    }
    MatrixPrint(&matrix);
        
    return 0;
}
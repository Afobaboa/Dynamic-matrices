#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include "../headers/intArray.h"


/** defines used to set colors 
 * for ColoredPrint() and 
 * PrintColor().
 */
#define COLOR_RED    "\x1b[31m"
#define COLOR_GREEN  "\x1b[32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_WHITE  "\033[1;37m"
#define COLOR_RESET  "\x1b[0m"


/**
 * This colores used for
 * ColoredPrintf() to set
 * needed color.
 */
enum COLORS {
    GREEN,   /**< Green color. */
    RED,     /**< Red color. */
    YELLOW,  /**< Yellow color */
    WHITE    /**< White color */
};
typedef enum COLORS color_t;


/**
 * This function is similary
 * to printf(), but this function
 * can print colored text.
 * 
 * @param color Color of text. You have
 * to use something from enum COLORS.
 * @param format Format of your text.
 * You have to use printf() format
 * 
 * Other arguments used for subtitution
 * to format. You have to use as many
 * arguments as you us in format, like 
 * in printf().
 * 
 * @return Count of used other arguments.
 */
static int ColoredPrintf(color_t color, const char* format, ...);


/** 
 * Print needed color (used defines).
 * 
 * This function used to make 
 * ColoredPrintf() more universal.
 */
static void PrintColor(color_t color);


void PrintIntArray(intArray* intArray) {
    printf("There is %s\n\n", intArray->name);

    printf("x = %3s", "");
    for (size_t x = 0; x < intArray->sizeX; x++)
        printf("%6zu ", x);
    puts("");

    for (size_t y = 0; y < intArray->sizeY; y++) {
        printf("y = %3zu ", y);
        for (size_t x = 0; x < intArray->sizeX; x++)
            ColoredPrintf(YELLOW, "%6d ", *(intArray->data + y*intArray->sizeX + x));
        puts("");
    }
}


int ColoredPrintf(color_t color, const char* format, ...) {
    va_list args;
    va_start(args, format);
    PrintColor(color);
    int result = vprintf(format, args);
    printf(COLOR_RESET);
    va_end(args);
    return result;
}


void PrintColor(color_t color) {
    switch(color) {
    case GREEN:
        printf(COLOR_GREEN);
        break;
    case RED:
        printf(COLOR_RED);
        break;
    case YELLOW:
        printf(COLOR_YELLOW);
        break;
    case WHITE:
        printf(COLOR_WHITE);
        break;
    default: 
        fprintf(stderr, "intArray.cpp: PrintColor(): ERROR, wrong color.");
        break;
    }
}
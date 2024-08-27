#include <stdarg.h>
#include <stdio.h>
#include "../headers/coloredIO.h"


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
 * Print needed color (used defines).
 * 
 * This function used to make 
 * ColoredPrintf() more universal.
 */
static void PrintColor(color_t color);

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
        fprintf(stderr, "%s: %s(%d): %s", __FILE__, __FUNCTION__, __LINE__, "ERROR, wrong color.");
        break;
    }
}
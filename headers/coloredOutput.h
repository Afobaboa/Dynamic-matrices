#ifndef COLORES_IO_H
#define COLORES_IO_H


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
int ColoredPrintf(color_t color, const char* format, ...);


#endif // COLORES_IO_H
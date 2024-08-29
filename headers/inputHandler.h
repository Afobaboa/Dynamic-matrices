#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H


/**
 * This enum contain 
 * main menu modes 
 * which processing 
 * in main.cpp.
 */
enum MODE {
    MATRIX_SUMMATION = 1,    /**< Summation of two costom matrices. */
    JAGGED_ARRAY_PRINTING,   /**< Printig costom jagged arrray.     */
    END_INPUT                /**< End of unput.                     */
};
typedef enum MODE menuMode_t;


/** 
 * This function print 
 * some hints for user
 * to terminal and get 
 * choosed mode of program
 * from stdin.
 * 
 * @return Mode status.
 * You should process 
 * this mode yourself.
 */
menuMode_t GetMode();


/**
 * This function trying
 * to get size_t value from 
 * stdin until value will be 
 * getted or EOF is getted.
 * 
 * @param buffer       There will be getted  value.
 * @param maxBuferSize Max size user can enter.
 * 
 * @return true if value was get,
 * @return false in other situations.
 */
bool SetSize(size_t* buffer, const size_t maxBufferSize);


/**
 * This function init 
 * line with int values
 * from stdin.
 * 
 * @param linePtr     Pointer to start of line.
 * @param elemCount   Count of element in line.
 * @param maxElemSize Max elem's value user can enter.
 * 
 * @return true if line is
 * setted, 
 * @return false in other 
 * situations.
 */
bool SetLine(int* const linePtr, const size_t elemCount, const int maxElemSize);


#endif // INPUT_HANDLER_H
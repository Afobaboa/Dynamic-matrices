#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H


/**
 * @file
 * This file is don't 
 * used in my project now
 * and you can delete it
 * if you want to use my 
 * program.
 */


/**
 * This function trying
 * to get size_t value from 
 * stdin until value will be 
 * getted or EOF is getted.
 * 
 * @param buffer There will be getted  value.
 * 
 * @return true if value was get,
 * @return false in other situations.
 */
bool SetSize(size_t* buffer);


/**
 * This function init 
 * line with int values
 * from stdin.
 * 
 * @param linePtr   Pointer to 
 * start of line.
 * @param elemCount Count
 * of element in line.
 * 
 * @return true if line is
 * setted, 
 * @return false in other 
 * situations.
 */
bool SetLine(int* const linePtr, const size_t elemCount);


#endif // INPUT_HANDLER_H
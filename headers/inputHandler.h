#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H


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
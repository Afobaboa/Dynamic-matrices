#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H


/**
 * This function trying
 * to get int value from 
 * stdin until it will be 
 * getted or EOF is getted.
 * 
 * @param buffer There will be getted int value.
 * 
 * @return true if value was get,
 * @return false in other situations.
 */
bool GetIntValue(int* buffer);


#endif // INPUT_HANDLER_H
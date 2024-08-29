#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "../headers/inputHandler.h"
#include "../headers/matrix.h"


// TODO:
// Заменить GetIntValue() на
// GetIntLine() и GetSize()


/**
 * Check is stdin clear until
 * EOF or '\n' (until nearest 
 * symbol).
 * 
 * @return true if there are only 
 * spaces between begin of stdin 
 * and nearest '\n' or EOF,
 * @return false in other situations.
 */
static bool IsInputClear();


/**
 * This functions chek if
 * next char in stdin is EOF.
 * 
 * @return true if there is EOF,
 * @return false in other situations.
 */
static bool IsEOF();


/**
 * Clear all chars from stdin 
 * until '\n' or EOF isn't here
 */
static void ClearInput();


/**
 * This function trying
 * to get int value from 
 * stdin until value will be 
 * getted or EOF is getted.
 * 
 * @param buffer There will be getted int value.
 * 
 * @return true if value was get,
 * @return false in other situations.
 */
bool GetIntValue(int* buffer);


static void ClearInput() {
    int c = getchar();
    while (c != '\n' && c != EOF) 
        c = getchar();
}


static bool IsInputClear() {
    int c = 0;
    do {
        c = getchar();
        if (c == EOF || c == '\n') {
            return true;
        }
    } while (isspace(c));
    return false;
}


static bool IsEOF() {
    int c = getchar();
    if (c == EOF)
        return true;
    return false;
}


bool SetSize(size_t* buffer, const size_t maxBufferSize) {
    while (scanf("%zu", buffer) != 1 || 
             *buffer > maxBufferSize ||
                     !IsInputClear()   ) {
        if (IsEOF())
            return false;
        puts("# Неверный формат ввода. Возможно, вы ввели "
              "слишком большой размер или лишние символы.\n"
              "# Попробуйте еще раз.");
        ClearInput();
    }
    return true;
}


bool SetLine(int* const linePtr, const size_t elemCount, const int maxElemValue) {
    printf("# Введите значения элементов следующей строки. Они не должны "
           "превышать %d\n", maxElemValue);
    for (size_t i = 0; i < elemCount; i++) {
        int* elem = &linePtr[i];
        while(scanf("%d", elem) != 1 || *elem > maxElemValue) {
            if (IsEOF())
                return false;
            printf("# Не получилось получить значение %zu элемента, "
                   "Весь остальной ввод был проигнорирован.\n"
                   "# Попробуйте еще раз его ввести.\n", i);
            ClearInput();
        }
    }
    if (!IsInputClear()) {
        puts("Строка была заполнена, но вы ввели слишком много "
             "значений. Лишние элементы были очищены.");
        ClearInput();
    }

    return true;
}
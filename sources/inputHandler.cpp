#include <assert.h>
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
    assert(buffer);
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


bool SetLine(int* const linePtr, const size_t lineLength, const int maxElemValue) {
    printf("# Введите значения элементов следующей строки. Они не должны "
           "превышать %d\n", maxElemValue);
    for (size_t elemNum = 0; elemNum < lineLength; elemNum++) {
        while(scanf("%d", &linePtr[elemNum]) != 1 || linePtr[elemNum] > maxElemValue) {
            if (IsEOF())
                return false;
            printf("# Не получилось получить значение %zu элемента, "
                   "Весь остальной ввод был проигнорирован.\n"
                   "# Попробуйте еще раз его ввести.\n", elemNum);
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


menuMode_t GetMode() {
    menuMode_t mode;
    printf("Выберите действие:\n"
           "%d - суммирование матриц.\n"
           "%d - вывод рваного массива.\n",
           MATRIX_SUMMATION, JAGGED_ARRAY_PRINTING);
    while (scanf("%d", &mode) != 1 || 
                   !IsInputClear()   ) {
        if (IsEOF())
            return END_INPUT;
        puts("# Неверный формат ввода."
             "# Попробуйте еще раз."   );
        ClearInput();
    }
    return mode;
}
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "../headers/inputHandler.h"


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
 * Print special message if user 
 * write input in wrong format.
 */
static void PrintWrongInputMessage();


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


static void PrintWrongInputMessage() {
    puts("# Неверный ввод. Попробуйте ввести все сначала.");
}


static bool IsEOF() {
    int c = getchar();
    if (c == EOF)
        return true;
    return false;
}


bool GetIntValue(int* buffer) {
    while (   scanf("%d", buffer) != 1 || 
                       !IsInputClear()   ) {

        if (IsEOF())
            return false;
        PrintWrongInputMessage();
        ClearInput();
    }
    return true;
}
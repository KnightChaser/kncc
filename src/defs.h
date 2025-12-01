// src/defs.h
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    T_PLUS,  // +
    T_MINUS, // -
    T_STAR,  // *
    T_SLASH, // /
    T_INTLIT // integer literal (decimal whole number which have 1 or more
             // digits of 0-9)
};

struct token {
    int token;
    int intvalue;
};

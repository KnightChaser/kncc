// src/defs.h
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
enum {
    T_PLUS,   // +
    T_MINUS,  // -
    T_STAR,   // *
    T_SLASH,  // /
    T_INTLIT, // integer literal (decimal whole number which have 1 or more
              // digits of 0-9)
    T_EOF     // end of file
};

// Token structure
struct token {
    int token;    // Token type
    int intvalue; // Integer value if token is T_INTLIT
};

// AST node types
enum {
    A_ADD,      // Addition
    A_SUBTRACT, // Subtraction
    A_MULTIPLY, // Multiplication
    A_DIVIDE,   // Division
    A_INTLIT    // Integer literal
};

// AST node structure
struct ASTnode {
    int op; // operation to be performed on this tree
    struct ASTnode *left;
    struct ASTnode *right;
    int intvalue; // used if op == A_INTLIT
};

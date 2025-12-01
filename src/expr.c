// src/expr.c

#include "data.h"
#include "decl.h"
#include "defs.h"

/**
 * Parse a primary expression.
 * e.g., integer literals.
 *
 * @return ASTnode* The AST node representing the primary expression.
 */
static struct ASTnode *primary(void) {
    struct ASTnode *n;

    // For an INTLIT token, make a leaf AST node for it
    // and scan in the next token. Otherwise, a syntax error
    // for any other token type.
    switch (Token.token) {
    case T_INTLIT:
        n = mkastleaf(A_INTLIT, Token.intvalue);
        scan(&Token);
        return n;
    default:
        fprintf(stderr, "Syntax error, line: %d\n", Line);
        exit(1);
    }
}

/**
 * Map a token to its corresponding arithmetic operator.
 *
 * @param token The token to map.
 * @return int The corresponding arithmetic operator.
 */
int arithmeticOperator(int token) {
    switch (token) {
    case T_PLUS:
        return (A_ADD);
    case T_MINUS:
        return (A_SUBTRACT);
    case T_STAR:
        return (A_MULTIPLY);
    case T_SLASH:
        return (A_DIVIDE);
    default:
        fprintf(stderr, "Unknown arithmetic operator: %d, line: %d\n", token,
                Line);
        exit(1);
    }
}

/**
 * Parse a binary expression.
 *
 * @return ASTnode* The AST node representing the binary expression.
 */
struct ASTnode *binexpr(void) {
    struct ASTnode *node, *left, *right;
    int nodetype;

    // Get the integer literal on the left.
    // Fetch the next token at the same time.
    left = primary();

    // If no tokens left, return the left node to avoid further processing.
    if (Token.token == T_EOF) {
        return left;
    }

    // Convert the token to an arithmetic operator.
    nodetype = arithmeticOperator(Token.token);

    // Fetch the next token.
    scan(&Token);

    // Get the integer literal on the right, recursively.
    right = binexpr();

    // Create a new AST node for the binary expression.
    node = mkastnode(nodetype, left, right, 0);

    return node;
}

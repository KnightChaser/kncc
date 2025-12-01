// src/tree.c

#include "data.h"
#include "decl.h"
#include "defs.h"

/**
 * mkastnode - create an AST node
 *
 * @param op       the operator
 * @param left     pointer to left subtree
 * @param right    pointer to right subtree
 * @param intvalue integer value (for leaf nodes)
 *
 * @return pointer to the newly created AST node
 */
struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right,
                          int intvalue) {
    struct ASTnode *n;

    n = (struct ASTnode *)malloc(sizeof(struct ASTnode));
    if (n == NULL) {
        fprintf(stderr, "out of memory in mkastnode()\n");
        exit(1);
    }

    n->op = op;
    n->left = left;
    n->right = right;
    n->intvalue = intvalue;

    return n;
}

/**
 * mkastleaf - create a leaf AST node
 *
 * @param op       the operator
 * @param intvalue integer value
 *
 * @return pointer to the newly created leaf AST node
 */
struct ASTnode *mkastleaf(int op, int intvalue) {
    return mkastnode(op, NULL, NULL, intvalue);
}

/**
 * mkastunary - create a unary AST node
 *
 * @param op       the operator
 * @param left     pointer to left subtree
 * @param intvalue integer value
 *
 * @return pointer to the newly created unary AST node
 */
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue) {
    return mkastnode(op, left, NULL, intvalue);
}

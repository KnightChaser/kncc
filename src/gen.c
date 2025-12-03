// src/gen.c

// Generic code generator

#include "data.h"
#include "decl.h"
#include "defs.h"

/**
 * genAST - Generates code for the given AST node and its subtrees.
 *
 * @n: The AST node to generate code for.
 * @return int The register index where the result is stored.
 */
int genAST(struct ASTnode *n) {
    int leftRegister, rightRegister;

    // Generate code for left and right subtrees recursively
    if (n->left) {
        leftRegister = genAST(n->left);
    }
    if (n->right) {
        rightRegister = genAST(n->right);
    }

    switch (n->op) {
    case A_ADD:
        return cgadd(leftRegister, rightRegister);
    case A_SUBTRACT:
        return cgsub(leftRegister, rightRegister);
    case A_MULTIPLY:
        return cgmul(leftRegister, rightRegister);
    case A_DIVIDE:
        return cgdiv(leftRegister, rightRegister);
    case A_INTLIT:
        return cgload(n->intvalue);
    default:
        // Should not reach here; unsupported operation
        fprintf(stderr, "Error: Unknown AST node operation %d\n", n->op);
        exit(1);
    }
}

/**
 * genpreamble - Wraps CPU-specific preamble generation.
 */
void genpreamble() { cgpreamble(); }

/**
 * genpostamble - Wraps CPU-specific postamble generation.
 */
void genpostamble() { cgpostamble(); }

/**
 * genfreeregs - Frees all registers used during code generation.
 */
void genfreeregs() { freeAllRegisters(); }

/**
 * genprintint - Wraps CPU-specific integer printing.
 *
 * @reg: The register index containing the integer to print.
 */
void genprintint(int reg) { cgprintint(reg); }

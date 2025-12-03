// src/stmt.c

#include "data.h"
#include "decl.h"
#include "defs.h"

#include <stdbool.h>

/**
 *
 * statements: statement | statements statement;
 * statement: 'print' expression ';'
 *
 */

void statements(void) {
    struct ASTnode *tree;
    int reg;

    while (true) {
        match(T_PRINT, "print");

        // Parse the following expression and generate the assembly code
        tree = binexpr(0);  // get the expression tree
        reg = genAST(tree); // get result
        genprintint(reg);   // print that result
        genfreeregs();      // free all registers

        // Match the semicolon at the end of the statement
        semicolon();
        if (Token.token == T_EOF) {
            return;
        }
    }
}

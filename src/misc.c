// src/misc.c

#include "data.h"
#include "decl.h"
#include "defs.h"

/**
 * match - Matches the current token with the expected token.
 *         If they match, it scans the next token.
 *         If they don't match, it prints an error message and exits.
 *
 * @t: The expected token type.
 * @what: A string description of the expected token (for error messages).
 */
void match(int t, char *what) {
    if (Token.token == t) {
        scan(&Token);
    } else {
        fprintf(stderr, "Expected %s, got token %d, line %d\n", what,
                Token.token, Line);
        exit(1);
    }
}

/**
 * semicolon - Matches a semicolon token.
 */
void semicolon(void) { match(T_SEMICOLON, ";"); }

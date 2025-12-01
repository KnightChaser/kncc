#include "decl.h"
#include "defs.h"
#include "errno.h"

#define extern_

#include "data.h"
#undef extern_

static void init() {
    Line = 1;
    Putback = '\n';
}

static void usage(char *prog) {
    fprintf(stderr, "Usage: %s infile\n", prog);
    exit(1);
}

// List of printable tokens
char *tokstr[] = {"+", "-", "*", "/", "intilt"};

static void scanfile() {
    struct token T;

    while (scan(&T)) {
        printf("Toekn %s", tokstr[T.token]);
        if (T.token == T_INTLIT) {
            printf(", value %d", T.intvalue);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        usage(argv[0]);
    }

    init();

    Infile = fopen(argv[1], "r");
    if (Infile == NULL) {
        fprintf(stderr, "Cannot open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    scanfile();

    fclose(Infile);
    exit(0);
}

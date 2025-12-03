// src/decl.h

// Declarations for scanner, parser, AST, interpreter, and code generator
// Used in various source files

struct token;

// NOTE: scan.c
int scan(struct token *t);

// NOTE: tree.c
struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right,
                          int intvalue);
struct ASTnode *mkastleaf(int op, int intvalue);
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue);

// NOTE: gen.c
int genAST(struct ASTnode *n);
void genpreamble();
void genpostamble();
void genfreeregs();
void genprintint(int reg);

// NOTE: cgn.c
// Code generation utilities (NASM x86-64)
void freeAllRegisters(void);
void cgpreamble();
void cgpostamble();
int cgload(int value);
int cgadd(int r1, int r2);
int cgsub(int r1, int r2);
int cgmul(int r1, int r2);
int cgdiv(int r1, int r2);
void cgprintint(int r);

// NOTE: expr.c
struct ASTnode *binexpr(int rbp);

// NOTE: stmt.c
void statements(void);

// NOTE: misc.c
void match(int t, char *what);
void semicolon(void);

// NOTE: interpret.c
int interpretAST(struct ASTnode *n);

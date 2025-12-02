// src/decl.h

// Declarations for scanner, parser, AST, interpreter, and code generator
// Used in various source files

struct token;

int scan(struct token *t);

// Abstract Syntax Tree utilities
struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right,
                          int intvalue);
struct ASTnode *mkastleaf(int op, int intvalue);
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue);
struct ASTnode *binexpr(int rbp);

// AST interpretation and code generation
int interpretAST(struct ASTnode *n);
void generateAsmCode(struct ASTnode *n);

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

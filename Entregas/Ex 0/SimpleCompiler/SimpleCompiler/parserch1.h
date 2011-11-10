typedef int Operator;

typedef struct _expression {
    char type;                        /* 'D' or 'P' */
    int value;                        /* for 'D' */
    struct _expression *left, *right; /* for 'P' */
    Operator oper;                    /* for 'P' */
} Expression;

typedef Expression AST_node;          /* the top node is an Expression */

extern int Parse_program(AST_node **);

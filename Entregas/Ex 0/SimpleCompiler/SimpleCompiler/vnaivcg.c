#include    "parser.h"      /* for types AST_node and Expression */
#include    "thread.h"      /* for Thread_AST() and Thread_start */
#include    "backend.h"     /* for self check */
                                        /* PRIVATE */
static AST_node *Active_node_pointer;

static void Trivial_code_generation(void) {
    printf("#include    \"stack.h\"\nint main(void) {\n");
    while (Active_node_pointer != 0) {
        /* there is only one node type, Expression: */
        Expression *expr = Active_node_pointer;
        switch (expr->type) {
        case 'D':
            printf("Push(%d);\n", expr->value);
            break;
        case 'P':
            printf("{\n\
                int e_left = Pop(); int e_right = Pop();\n\
                switch (%d) {\n\
                case '+': Push(e_left + e_right); break;\n\
                case '*': Push(e_left * e_right); break;\n\
                }}\n",
                expr->oper
            );
            break;
        }
        Active_node_pointer = Active_node_pointer->successor;
    }
    printf("printf(\"%%d\\n\", Pop()); /* print the result */\n");
    printf("return 0;}\n");
}
                                        /* PUBLIC */
void Process(AST_node *icode) {
    Thread_AST(icode); Active_node_pointer = Thread_start;
    Trivial_code_generation();
}

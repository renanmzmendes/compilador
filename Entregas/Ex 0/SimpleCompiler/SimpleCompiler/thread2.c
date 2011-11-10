#include    "parser.h"      /* for types AST_node and Expression */
#include    "thread.h"      /* for self check */

                                        /* PRIVATE */
static AST_node *Thread_expression(Expression *expr, AST_node *succ) {
    switch (expr->type) {
    case 'D':
        expr->successor = succ; return expr;
        break;
    case 'P':
        expr->successor = succ;
        return
            Thread_expression(expr->left,
                Thread_expression(expr->right, expr)
            );
        break;
    }
}
                                        /* PUBLIC */
AST_node *Thread_start;

void Thread_AST(AST_node *icode) {
    Thread_start = Thread_expression(icode, 0);
}

#include    "lex.h"         /* for self check */
                                        /* PRIVATE */
static int Layout_char(int ch) {
    switch (ch) {
    case ' ': case '\t': case '\n': return 1;
    default:                        return 0;
    }
}
                                        /* PUBLIC */
Token_type Token;

void get_next_token(void) {
    int ch;

    /* get a non-layout character: */
    do {
        ch = getchar();
        if (ch < 0) {
            Token.class = EoF; Token.repr = '#';
            return;
        }
    } while (Layout_char(ch));

    /* classify it: */
    if ('0' <= ch && ch <= '9') {Token.class = DIGIT;}
    else {Token.class = ch;}

    Token.repr = ch;
}

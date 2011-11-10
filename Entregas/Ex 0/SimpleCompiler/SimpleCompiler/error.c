#include    "error.h"       /* for self check */

void
Error(char *msg) {
    printf("Error from demo compiler: %s\n", msg);
    exit (1);
}

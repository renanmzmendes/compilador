extern int stack[100];
extern int sp;
#define Push(v)     (stack[sp++] = (v))
#define Pop()       (stack[--sp])

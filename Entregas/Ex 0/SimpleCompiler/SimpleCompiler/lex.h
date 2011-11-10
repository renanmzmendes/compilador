/* Define class constants */
/* Values 0-255 are reserved for ASCII characters */
#define    EoF      256
#define    DIGIT    257

typedef struct {int class; char repr;} Token_type;

extern Token_type Token;
extern void get_next_token(void);

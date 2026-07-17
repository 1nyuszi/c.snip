#include <stdio.h>
#include <stdlib.h>

char *dectobin(unsigned char dec);

int main(int argc, char *argv[]) {
    int i;
    unsigned char c;
    
    if (argc < 2) {
        printf("The arguments should be at least one number between 0 and 255.");
        return 0;
    }

    for(i=1;i<argc;i++) {
        c = atoi(argv[i]);
        printf("%3d: %s\n", c, dectobin(c));
    }

    return 0;
}

/* Returns binary representation in form of a string, e.g. 73 -> "01001001" */
char *dectobin(unsigned char dec) {
    static char binrep[9];

    for (int i = 7; i >= 0; i--) {
        binrep[i] = (dec & 1) ? '1' : '0';
        dec >>= 1;
    }

    return binrep;
}
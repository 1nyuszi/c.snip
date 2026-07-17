#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *dectobin(uint16_t dec);

int main(int argc, char *argv[]) {
    int i;
    uint16_t c;
    
    if (argc < 2) {
        printf("The arguments should be at least one number between 0 and 65535.");
        return 0;
    }

    for(i=1;i<argc;i++) {
        c = atoi(argv[i]);
        printf("%5d: %s\n", c, dectobin(c));
    }

    return 0;
}

/* Returns binary representation in form of a string, e.g. 73 -> "01001001" */
char *dectobin(uint16_t dec) {
    static char binrep[17];

    for (int i = 15; i >= 0; i--) {
        binrep[i] = (dec & 1) ? '1' : '0';
        dec >>= 1;
    }

    binrep[17] = '\0';

    return binrep;
}
#include <stdio.h>
#include <string.h>

#define DELIMITER "\\"

int main(int argc, char *argv[]) {
    printf("Count of arguments: %d\n\n", argc);

    if (argc <= 1) {
        return 0;
    }

    for(int i=0;i<argc;i=i+1) {
        printf("%d: %s\n", i, argv[i]);
    }
    printf("\n");

    char *tok_ptr = strtok(argv[0], DELIMITER);
    while (tok_ptr != NULL) {
        printf("%s\n", tok_ptr);
        tok_ptr = strtok(NULL, DELIMITER);
    }

    return 0;
}

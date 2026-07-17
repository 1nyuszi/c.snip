#include <stdio.h>
#include <string.h>

#define DELIMITER "\\"

void substring(char *substr, char *str, int start, int length);

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
    printf("\n");

    char *str = "My String And I Know It";
    char substr[6];
    strncpy(substr, str + 3, 6);
    substr[6] = '\0';
    printf("%s\n", substr); // "String"
    printf("\n");

    char substr2[8];
    substring(substr2, "Hello, my name is Amanpour, and this is my apartment.", 18, 8);
    printf("%s\n\n", substr2);

    return 0;
}

void substring(char *substr, char *str, int start, int length) {
    strncpy(substr, str + start, length);
    substr[length] = '\0';
}

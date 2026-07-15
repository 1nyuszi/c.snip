#include <stdio.h>
#include <string.h>

int main() {
    int ct_lines = 0;
    int ct_chars = 0;
    char line[256];
    FILE *fptr;

    fptr = fopen(".\\in_data\\numbers.dat", "r");
    if(fptr == NULL) {
        printf("Not able to open the file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fptr)) {
        ct_lines = ct_lines + 1;
        ct_chars = ct_chars + strlen(line);
    }

    printf("Number of lines in the file: %d\n", ct_lines);
    printf("Number of characters in the file: %d\n", ct_chars);

    fclose(fptr);

    return 0;
}
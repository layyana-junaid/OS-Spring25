#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[256];
    FILE *file;
    int count = 0;
    char ch;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    fclose(file);
    printf("Total number of lines in %s: %d\n", filename, count);
    
    return 0;
}

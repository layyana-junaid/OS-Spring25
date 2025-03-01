#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[256];
    int count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i] != '\0'; i++) {
        char ch = tolower(sentence[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    printf("Number of vowels: %d\n", count);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    while (fscanf(file, "%s", word) == 1) {
        // Remove punctuation from the word
        int len = strlen(word);
        if (len > 0 && ispunct(word[len - 1])) {
            word[len - 1] = '\0';
        }

        // Convert word to lowercase for case-insensitive comparison
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }

        // Count the word
        if (strlen(word) > 0) {
            wordCount++;
        }
    }

    fclose(file);

    printf("Total words: %d\n", wordCount);

    return 0;
}

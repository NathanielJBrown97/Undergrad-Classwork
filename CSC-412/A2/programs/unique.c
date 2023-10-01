#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDuplicateLine(char* line, char** lines, int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        if (strcmp(line, lines[i]) == 0) {
            return 1; // The line is a duplicate
        }
    }
    return 0; // The line is not a duplicate
}

int main() {
    char buffer[1024];
    char* lines[1024]; // array for the lines
    int lineCount = 0; // counter for later iteration

    // Read data from stdin and write it to stdout (standard output)
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Check if the line is a duplicate
        if (!isDuplicateLine(buffer, lines, lineCount)) {
            // If not a duplicate, print it and add it to the array of unique lines
            fputs(buffer, stdout);
            lines[lineCount] = strdup(buffer); // Store a copy of the line
            lineCount++;
        }
    }

    // Free the memory allocated for unique lines
    for (int i = 0; i < lineCount; i++) {
        free(lines[i]);
    }

    return 0;
}

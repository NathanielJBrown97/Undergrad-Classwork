#include "../fio/fio.h"
#include "../fio/fio.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added for string functions

int main() {
    FILE *file;
    char filename[] = "unix_sentence.text"; 
    char buffer[1024]; // buffer to store data

    // open the file using the local fio library
    file = openFile(filename);

    // Read and print the contents of the file
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Remove newline character if it exists
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Replace '\n' with '\0'
        }

        // put file contents (buffer) into stdout
        fputs(buffer, stdout);
        putchar('\n'); // Add a newline after each line
    }

    // Close the file
    fclose(file);

    return 0;
}

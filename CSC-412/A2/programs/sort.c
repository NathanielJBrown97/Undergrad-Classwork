#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(char* array[], int size) {
    for (int cur_word = 0; cur_word < size - 1; cur_word++) {
        for (int cur_compare = 0; cur_compare < size - cur_word - 1; cur_compare++) {
            if (strcmp(array[cur_compare], array[cur_compare + 1]) > 0) {
                char* temp_word = array[cur_compare];
                array[cur_compare] = array[cur_compare + 1];
                array[cur_compare + 1] = temp_word;
            }
        }
    }
}

int main() {
    char buffer[1024];
    char* lines[1024]; // Array to store the lines
    int line_count = 0; // Counter for later iteration

    // Read data from stdin and write it to stdout (standard output)
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        lines[line_count] = strdup(buffer);
        line_count++;
    }

    // Sort the lines using bubble sort
    bubble_sort(lines, line_count);

    // Print the sorted lines to stdout
    for (int cur_line = 0; cur_line < line_count; cur_line++) {
        fputs(lines[cur_line], stdout);
        free(lines[cur_line]); // Free memory from lines array
    }

    return 0;
}

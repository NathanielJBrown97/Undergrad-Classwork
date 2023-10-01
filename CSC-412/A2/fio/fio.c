#include <stdio.h>
#include "fio.h"

// open an existing file for reading
FILE* openFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
    }
    return file;
}

/* implement the two function below */

// create a new file for writing
FILE* createFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
    }
    return file;
}

// write data to an open file
void writeToFile(FILE* file, const char* data) {
    if (file == NULL) {
        perror("Error writing to file");
        return;
    }
    fprintf(file, "%s", data);
}





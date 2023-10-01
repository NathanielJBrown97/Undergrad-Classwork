#ifndef FIO_H
#define FIO_H

#include <stdio.h>

// open an existing file for reading
FILE* openFile(const char* filename);

// create a new file for writing
//FILE* createFile(const char* filename);
FILE* createFile(const char* filename);
// write data to an open file
//void writeToFile(FILE* file, const char* data);
void writeToFile(FILE* file, const char* data);


#endif /* FIO_H */

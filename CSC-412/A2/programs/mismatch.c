#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../fio/fio.h"
#include "../fio/fio.c"


int main() {
    FILE* dictionary = openFile("unix_dict.text"); //open file using fio library
    
    char buffer[1024]; // creates a 1024 byte buffer to store data
    char word[1024]; //array for the word being checked

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) { 
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character from the input
        char* token = strtok(buffer, " "); // Tokenize the input into words seperated by spaces
        while (token != NULL) {
            strcpy(word, token);
            // Check if the word is in the dictionary file
            int found = 0;
            rewind(dictionary); // Rewind the file to the beginning - how useful!
            while (fgets(buffer, sizeof(buffer), dictionary) != NULL) {
                buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
                if (strcmp(buffer, word) == 0) { //compare two strings if returns true swap found flag
                    found = 1;
                    break;
                }
            }
            // if word NOT found stdout
            if (!found) {
                printf("%s\n", word);
            }
            token = strtok(NULL, " ");
        }
    }
    
    fclose(dictionary); // Close the dictionary file

    return 0;
}

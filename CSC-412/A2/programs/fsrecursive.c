#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursive_directory_traversal(const char *folder_name, FILE *output_file) {
    // Print the directory name to stdout and save it to the output file
    printf("%s\n", folder_name);
    fprintf(output_file, "%s\n", folder_name);

    // Open the directory for reading
    DIR *dir = opendir(folder_name);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Check if the entry is a directory
        if (entry->d_type == DT_DIR) {
            // Recursively traverse the directory
            char next_folder[1024];
            snprintf(next_folder, sizeof(next_folder), "%s/%s", folder_name, entry->d_name);
            recursive_directory_traversal(next_folder, output_file);
        }
    }

    closedir(dir);
}

int main() {
    // Open the starting file for reading
    FILE *start_file = fopen("fsrecursion_start.txt", "r");
    if (start_file == NULL) {
        perror("Error opening starting file");
        return 1;
    }

    // Create the output file for writing
    FILE *output_file = fopen("fsrecursion_output.txt", "w");
    if (output_file == NULL) {
        perror("Error creating output file");
        fclose(start_file);
        return 1;
    }

    char folder_name[1024];
    if (fgets(folder_name, sizeof(folder_name), start_file) != NULL) {
        // Remove the newline character at the end of the folder name
        size_t len = strlen(folder_name);
        if (len > 0 && folder_name[len - 1] == '\n') {
            folder_name[len - 1] = '\0';
        }

        // Start the recursive directory traversal
        recursive_directory_traversal(folder_name, output_file);
    }

    // Close files
    fclose(start_file);
    fclose(output_file);

    return 0;
}

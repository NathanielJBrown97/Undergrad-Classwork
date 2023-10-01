#include <stdio.h>
#include <stdlib.h>
// Factorial Function: Multiplies a number 1 * i; until i is == n
// Arguments 1: receieves integer
// Returns 1: result variable of int type
unsigned long long int factorial(int n) {
    unsigned long long int result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

// Validity Check Function: Checks if a passed character is within the range of 0-20
// Arguments 1: Pointer to a constant character that needs to be validated
// Returns 1: Returns true if the endptr is a null and the number is 0 >= num <= 20
int check_if_valid_integer(const char *check_me) {
    char *endptr;
    long num = strtol(check_me, &endptr, 10); // convert the checked into a long int

    return (*endptr == '\0' && num >= 0 && num <= 20);
}

int main(int argc, char *argv[]) {
    // IF - Not enough arguments
    if (argc < 2) {
        printf("Usage: %s <num> [NUMS]\n", argv[0]);
        return 1;
    }
    
    // Iterate through arguments
    for (int i = 1; i < argc; i++) {

        // if valid integer
        if (!check_if_valid_integer(argv[i])) {
            // Handle first, second, third argument separately
            if (i <= 3) {
                switch (i) {
                    case 1:
                        fprintf(stderr, "[C] Error: The first argument is not an integer between 0 and 20.\n");
                        break;
                    case 2:
                        fprintf(stderr, "[C] Error: The second argument is not an integer between 0 and 20.\n");
                        break;
                    case 3:
                        fprintf(stderr, "[C] Error: The third argument is not an integer between 0 and 20.\n");
                        break;
                }
            // Otherwise handle in #%d format    
            } else {
                fprintf(stderr, "[C] Error: Argument #%d is not an integer between 0 and 20.\n", i);
            }
            return 1;
        }
    }

    
    int arguments[argc - 1]; //empty array to hold arguments
    unsigned long long factorials[argc - 1]; //empty array to hold factorials long long, because... well... they're long.
    int valid_count = 0; //validity counter
    
    //iterate through the arguments; fill argument and factorial arrays.
    for (int i = 1; i < argc; i++) {
        //if valid integer
        if (check_if_valid_integer(argv[i])) {
            int current_argument = atoi(argv[i]);
            unsigned long long current_factorial = factorial(current_argument);
            arguments[valid_count] = current_argument;
            factorials[valid_count] = current_factorial;
            valid_count++;
        }
    }

    // Bubble sort the arrays based on arguments
    for (int i = 0; i < valid_count - 1; i++) {
        for (int j = 0; j < valid_count - i - 1; j++) {
            if (arguments[j] > arguments[j + 1]) {
                // Swap arguments
                int temp_arg = arguments[j];
                arguments[j] = arguments[j + 1];
                arguments[j + 1] = temp_arg;
                // Swap factorials accordingly
                unsigned long long temp_fact = factorials[j];
                factorials[j] = factorials[j + 1];
                factorials[j + 1] = temp_fact;
            }
        }
    }

    //loop through sorted arrays to print output.
    for (int i = 0; i < valid_count; i++) {
        printf("%d! = %llu\n", arguments[i], factorials[i]);
    }

    return 0;
}






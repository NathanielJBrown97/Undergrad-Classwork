#include <iostream>
#include <fstream>
#include <string>

//void helper function passed istream of input to eval, and given filename
void countAndPrint(std::istream& input, const std::string& filename) {
    //counters for line, word, byte
    int lineCount = 0;
    int wordCount = 0;
    int byteCount = 0;
    bool inWord = false; //boolean to determine if inside word

    char c; //char to eval
    while (input.get(c)) { //loop through each char
        byteCount++; //increment byte each iteration
        if (c == '\n') { //if new line, increment line counter
            lineCount++;
        }
        if (std::isspace(c)) { // if character is a whitespace
            inWord = false; //flip word flag
        } else if (!inWord) {  //if not a whitespace && not in a word
            wordCount++; //increment word count
            inWord = true; //flip flag, we are in a word
        }
    }
    //output the goods
    std::cout << lineCount << " " << wordCount << " " << byteCount << " " << filename << std::endl;
}

int main(int argc, char* argv[]) {
    // total counts for final output
    int totalLineCount = 0;
    int totalWordCount = 0;
    int totalByteCount = 0;

    if (argc < 2) {
        // No arguments provided, read from stdin
        countAndPrint(std::cin, "(stdin)");
    } else { //otherwise

        //loop through the CLAs 
        for (int i = 1; i < argc; i++) {
            std::ifstream file(argv[i]); // set current file name
            if (file.is_open()) { //open it and count/print
                countAndPrint(file, argv[i]);
                //add each count to the total counts.
                totalLineCount += totalLineCount;
                totalWordCount += totalWordCount;
                totalByteCount += totalByteCount;
                file.close(); //close it for nice boy points
            } else { //otherwise error its not there?
                std::cerr << "/autograder/student/wc: " << argv[i] << ": No such file or directory" << std::endl;
            }
        }
    }
    if (argc > 2) { // if multiple files; output totals.
            std::cout << totalLineCount << " " << totalWordCount << " " << totalByteCount << " total" << std::endl;
    }
    return 0;
}

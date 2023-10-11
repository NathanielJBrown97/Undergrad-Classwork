#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    std::vector<std::string> filenames; //vector containing filenames 

    // loop through argv and push to vector
    for (int i = 1; i < argc; ++i) {
        filenames.push_back(argv[i]);
    }

    // open each the output files
    std::vector<std::ofstream> output_files;
    for (const std::string& filename : filenames) {
        output_files.emplace_back(filename);
        if (!output_files.back()) { //if cant open, error and exit1
            std::cerr << "Error: Could not open file " << filename << "." << std::endl;
            exit(1);
        }
    }

    //take input from stdin
    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << line << std::endl; //write to stdout
        //iterate through each file in vec
        for (std::ofstream& file : output_files) {
            file << line << std::endl; //write to given file
        }
    }

    // Close output files
    for (std::ofstream& file : output_files) {
        file.close(); //bc we're nice.
    }

    return 0;
}

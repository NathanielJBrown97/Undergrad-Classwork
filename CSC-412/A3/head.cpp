#include <iostream>
#include <fstream> //fstream library to open file like a sane human, fio is dead to me.
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<std::string> files; //vector to contain all of our CLA file names
    
    // for loop - pushes each CLA into vector
    for (int i = 1; i < argc; ++i) {
        files.push_back(argv[i]);
    }

  

    // for each file in our files vector
    for (const std::string& file : files) {
        std::ifstream input(file); //set current filename
        if (!input.is_open()) { //stderr for gradescope
            std::cerr << "head: cannot open '" << file << "' for reading: No such file or directory" << std::endl;
            continue;
        }
        int line_count = 0; 
        std::string line; //string to hold line content
        
        // read first 10 lines of file; or until completion
        while (std::getline(input, line) && line_count < 10) {
            std::cout << line << std::endl;
            // if (line_count < 9){ //only print new lines for first 9 lines.
            //     std::cout << std::endl; 
            // }
            ++line_count;
        }
        
        input.close(); //close file
    }

    // if all files are processed and line count is < 10
    if (argc == 1){
        int line_count = 0; 
        while (line_count < 10) {
            std::string line;
            if (std::getline(std::cin, line)) {
                std::cout << line << std::endl;
                ++line_count;
            } else {
                // No more input from stdin, exit the loop
                break;
            }
        }
    }

    return 0;
}
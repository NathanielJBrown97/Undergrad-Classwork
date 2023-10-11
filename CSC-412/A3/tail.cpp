
#include <iostream>
#include <fstream> //fstream library to open file like a sane human, fio is dead to me.
#include <vector>
#include <deque> // Use deque to store the last 10 lines

int main(int argc, char* argv[]) {
    std::vector<std::string> files; //vec to contain the file names in argv

    for (int i = 1; i < argc; ++i) { //loop to fill the above vec
        files.push_back(argv[i]);
    }

    // for each file in our vector of file names
    for (const std::string& file : files) {
        std::deque<std::string> lastLines; // deque of type string to store the last 10 lines
        std::ifstream input(file); //set current file
        if (!input.is_open()) { //if not opened; error
            std::cerr << "tail: cannot open '" << file << "' for reading: No such file or directory" << std::endl;
            continue;
        }

        std::string line; //set current line
        while (std::getline(input, line)) { //loop thorugh lines in file
            lastLines.push_back(line); // push into string
            if (lastLines.size() > 10) { //as we hit size 10; pop the front of queue.
                lastLines.pop_front();
            }
        }

        input.close(); //close file bc polite

        // loop through for output displays
        //std::cout << "==> " << file << " <==" << std::endl; //gradescope wants this?
        std::size_t start = lastLines.size() > 10 ? lastLines.size() - 10 : 0;
        for (std::size_t i = start; i < lastLines.size(); ++i) {
            std::cout << lastLines[i] << std::endl;
        }

    }


    // if argument count is 1 i.e. no text files to read
    if (argc == 1) {
        std::vector<std::string> inputLines; 
        std::string line;

        // Read lines from standard input
        while (std::getline(std::cin, line)) {
            inputLines.push_back(line);
        }

        // Display the last 10 lines or lines from the end
        std::size_t start = std::max<std::size_t>(0, inputLines.size() - 10);
        for (std::size_t i = start; i < inputLines.size(); ++i) {
            std::cout << inputLines[i] << std::endl;
        }
    }
    return 0;
}

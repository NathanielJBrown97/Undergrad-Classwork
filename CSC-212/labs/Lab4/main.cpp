//// TODO - A real world example of a queue could be utilized in large online multiplayer games. Where players fill up a server. After a point; the server will be at capacity - or nearing - and a queue puts players in a line to access the game.

#include "queue.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]) {

    Queue *que;
    std::string file_name(argv[1]);

    std::vector<int> file_data;
    std::string line;

    std::ifstream file(file_name);

    // Read the first line from the file & store into vector
    std::getline(file, line);

    std::stringstream ss(line);

    int temp_int;
    while (ss >> temp_int) {
        file_data.push_back(temp_int);
    }
//    std::cout<< "WOO" << std::endl;
    // Create a linked_list based on what was in the first line of the file
    if (file_data.size() == 0) {
        que = new Queue();
    } else if (file_data.size() == 1) {
        que = new Queue(file_data[0]);
    } else {
        que = new Queue(file_data);
    }

    std::cout << que->to_string() << std::endl;


    // Read the rest of the file
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::istringstream iss(line);
        std::string instruction;
        iss >> instruction;
//        std::cout <<instruction << "\n";

        if (instruction == "-") {
//            std::cout << "are we here?";
            que->dequeue() ;
            std::cout << que->to_string() << "\n";
        } else if (instruction == "?") {
            int peek = que->peek();
            std::cout << peek << "\n";
        } else {
            int num = std::stoi(instruction);
            if (num >= -99 && num <= 99) {
                que->enqueue(num);
            }
            std::cout << que->to_string() << "\n";
        }


    }

}
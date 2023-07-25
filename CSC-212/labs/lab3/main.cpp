#include "linked_list.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
/// use strign for extract
// break string down to determine what conditional
// -1 checks for ?
// 1 checks for neg


//// read each line
//// series of conditionals
//// if position -1 of string == ?
////        do contains
//// if position 1 of string == -
////        do remove
//// if position is in string
////

//std::vector<int> fill_temporary_intake(const std::string& file_name) {
//    std::ifstream file(file_name);
//    std::vector<int> intake;
//
//    if (file.is_open()) {
//        std::string line;
//        if (std::getline(file, line)) {
//            std::istringstream extract(line);
//            int number;
//            while (extract >> number) {
//                intake.push_back(number);
//            }
//        }
//        file.close();
//    }
//    return intake;
//}

int main(int argc, char* argv[]) {
    // file name set by CLA 1
    std::string file_name = std::string(argv[1]);
    // vector to be filled with first line
    std::vector<int> temporary_intake;
    // pointer to our linkedList instantiation
    LinkedList* linkedList;
    std::string current_line; // string to hold current_line
    std::ifstream file(file_name); //ifstream for file

    std::getline(file, current_line); // read first line
    std::stringstream extract(current_line); // extract current line stringstream

    int data;
    while(extract >> data){
        temporary_intake.push_back(data);
    }



    //// depending upon size of vector - create different linked lists
    //empty
    if(temporary_intake.size() == 0){
        //use default constructor
        linkedList = new LinkedList();
    }
    //1 data parameter
    else if (temporary_intake.size() == 1){
        //use int param -- i.e. passed first element of vector (also only element)
        linkedList = new LinkedList(temporary_intake[0]);
    }
    // pass full vector
    else{
        linkedList = new LinkedList(temporary_intake);
    }
    // Output our current linked list.
    std::cout << linkedList->to_string() << std::endl;

    //// TODO: Read Rest of File --
    //// extract line, string for temporary line value, vector of strings to hold values from line
    while(std::getline(file,current_line)){
        std::stringstream extract(current_line);// extract of current line
        std::vector<std::string> characters_of_line; // container that will reset each iteration - will hold collection of characters from string
        std::string temporary_string; // temporary string to fill with each character

        //extract characters of the current_line being evaluated
        while (extract >> temporary_string){
            characters_of_line.push_back(temporary_string);
        }
        //// TODO: After characters have been extracted; examine via the vector.
        // if 2 elements in vector... it must be pair
        if(characters_of_line.size() == 2){
            int data = std::stoi(characters_of_line[0]);
            int index = std::stoi(characters_of_line[1]);

            linkedList->insert(data, index);
            // Output our current linked list.
            std::cout << linkedList->to_string() << std::endl;
        }
        else{
            //there is only 1 element in vector... need to examine punctuation THEN odd/even
            if(characters_of_line[0][characters_of_line[0].size()-1] == '?'){
                int number_without_question = std::stoi(characters_of_line[0].substr(0, characters_of_line[0].size()-1));
                std::cout << linkedList->contains(number_without_question) << "\n";
                continue; // move on to next line
            }
            else {
                int number_on_line = std::stoi(characters_of_line[0]);
                //// if negative
                if (number_on_line < 0){
                    //convert vect of type string to to a single string for int conversion
                    std::string StrForConversion;
                    for (std::string letter : characters_of_line){
                        StrForConversion += letter;
                    }
                    int integer_value = std::stoi(StrForConversion);
                    int absolute_value = std::abs(integer_value);

                    // Output our current linked list.
                    //conditional to stop if not in linked list
                    if (linkedList->contains(absolute_value)) {
                        linkedList->remove(absolute_value);
                        std::cout << linkedList->to_string() << std::endl;
                    }
                }
                ////if even pushback
                else if (number_on_line % 2 == 0){
                    linkedList->push_back(number_on_line);
                    // Output our current linked list.
                    std::cout << linkedList->to_string() << std::endl;
                }
                //if odd pushfront
                else if (number_on_line % 2 != 0){
                    linkedList->push_front(number_on_line);
                    // Output our current linked list.
                    std::cout << linkedList->to_string() << std::endl;
                }

            }
        }
    }




}





















////    linkedList.insert(10,4);
////    std::cout <<linkedList.to_string() << std::endl;
////    std::cout << "^^^^ Proof Insert works ^^^^ " << std::endl;
////    std::cout << "-------------------- Start Actual Output - ignore the 10 at index 4 --------------- \n\n\n";
////    linkedList.remove(37);
////    std::cout << linkedList.to_string() <<std::endl;
//
//    std::ifstream inputFile(file_name);
//    std::string line;
//    bool firstLine = true; // Flag to skip the first line
//
//    while (std::getline(inputFile, line)) {
//        if (firstLine) {
//            firstLine = false;
//            continue; // Skip the first line
//        }
//
//        std::istringstream extract(line);
//
//
//        int value;
//
//            if (extract >> value) {
//                char nextChar;
//                //if line is ?delete
//                if (extract >> nextChar) {
//                    if (nextChar == '?') {
//                        std::cout << linkedList.contains(value) << " <--- works correctly; might be off bc pairs are not read right, nor is remove.\n";
//                    }
//                }
//                else if (line.find(space) != std::string::npos) {
//                    int insertValue, indexValue;
//                    extract >> insertValue;
//                    extract >> indexValue;
//                    std::cout << "insert " << insertValue << " at index " << indexValue << std::endl;
//                }
//                else {
//                    // if negative convert to absolute, remove value.
//                    if (value < 0) {
//                        int absoluteValue = std::abs(value);
//                        linkedList.remove(absoluteValue);
//                        std::cout << linkedList.to_string() << "\n";
//                    // if even, pushback
//                    } else if (value % 2 == 0) {
//                        linkedList.push_back(value);
//                        std::cout << linkedList.to_string() << "\n";
//                    // if odd, pushfront
//                    } else if (value % 2 != 0) {
//                        linkedList.push_front(value);
//                        std::cout << linkedList.to_string() << "\n";
//                    }
//                }
//            }
//        }
//    }

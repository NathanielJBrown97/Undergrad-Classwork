 //#include <iostream>
//
//int main(int argc, *argv[]){
//
//}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "DynamicArray.h" // Include the header file for the DynamicArray class
 std::vector<int> readIntegersFromFile(const std::string& filename) {
     std::vector<int> integers;
     std::ifstream file(filename);

     if (file.is_open()) {
         std::string line;
         while (std::getline(file, line)) {
             std::istringstream iss(line);
             int num;
             while (iss >> num) {
                 integers.push_back(num);
             }
         }
         file.close();
     } else {
         std::cout << "Failed to open the file: " << filename << std::endl;
     }

     return integers;
 }

 int main(int argc, char* argv[]) {
     std::string file_name = std::string(argv[1]);
     //vector for intake
     std::vector<int> unknownInt = readIntegersFromFile(file_name);

    DynamicArray param; //default constructor
     if (argc >= 4) {
         double scaling_factor = std::stod(argv[2]);
         unsigned int capacity = std::stoul(argv[3]);

         if (argc == 4) {
             //// DEFAULT WITH SCALE / CAP=CAP
             param = DynamicArray(scaling_factor, capacity);
         }
         else if (argc == 5) {
             unsigned int default_value = std::stoul(argv[4]);
             //// FILL CONSTRUCT / CAP=LENGTH  --- VALS SET DEFAULT
             param = DynamicArray(scaling_factor, capacity, default_value);
         }
     }
     //append first half
     for (int curElem = 0; curElem < unknownInt.size() / 2; curElem++) {
         param.append(unknownInt[curElem]);

     }
     param.to_string();//output marker

     //prepend 2nd half
     for (int curElm = unknownInt.size()/2; curElm < unknownInt.size(); curElm++) {
         param.prepend(unknownInt[curElm]);
     }

     param.to_string(); //output marker
     //find first and last
     unsigned int indexValue = unknownInt.size() / 3;
     int firstThirdValue = unknownInt[unknownInt.size() / 3];
     std::cout << param.find_first_of(firstThirdValue, &indexValue) << "\t" << indexValue <<"\n"; //output marker
     std::cout << param.find_last_of(firstThirdValue, &indexValue) << "\t" << indexValue<< "\n"; //output marker
     //delete last
     param.remove_last();
     param.to_string();
     //delete first
     param.remove_first();
     param.to_string();
     //clear
     param.clear();
     param.to_string();

 }
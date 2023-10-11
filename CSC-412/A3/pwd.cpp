#include <iostream>
#include <cstring>
#include <unistd.h> //library for get current working directory function

int main() {
    char buffer[1024];
    
    //if the currentworking directory passed our character array and the size of buffer is not a nullptr
    if (getcwd(buffer, sizeof(buffer)) != nullptr) {
        std::cout << buffer << std::endl; //stdout the path
    } else { //otherwise 
        std::cerr << "/autograder/student/pwd: error: No such file or directory" << std::endl;
        return 1;
    }

    return 0;
}

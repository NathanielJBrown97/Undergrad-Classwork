
#include <iostream>
#include <stack>
#include <string>

// Function to check if a character is an operator
bool check_if_operator(char character) {
    //returns true if one of these characters
    return (character == '+' || character == '-' || character == '*' || character == '/' || character == '^');
}

// Function to get the precedence of an operator
int check_priority(char passed_operator) {
    //if pos or minus return 1
    if (passed_operator == '+' || passed_operator == '-')
        return 1;
        //if multiply or divide return 2
    else if (passed_operator == '*' || passed_operator == '/')
        return 2;
        //if ^ operator return 3
    else if (passed_operator == '^')
        return 3;
        // otherwise return 0
    else
        return 0;
}

std::string convert_infix_to_postfix(const std::string& infix) {
    //// Iterate through infix to ignore whitespace.
    std::string infixNOSPACE;

    // for each character in infix
    for (char character : infix) {
        // if not whitespace add to infix no space
        if (character != ' ') {
            infixNOSPACE += character;
        }
    }

//    std::cout << "infix " << infix << "no whitespace " << infixNOSPACE << "\n";
    //character stack to store our operators
    std::stack<char> operator_storage;
    //string to store the postfix
    std::string postfix;
    // iterate through characters of infix string
    for (size_t character = 0; character < infix.length(); ++character) {
        //in each iteration set current character to the current iteration of loop through infix
        char current_character = infixNOSPACE[character];
        // if the character is left parentheses
        if (current_character == '(') {
            // push current character onto our stack
            operator_storage.push(current_character);
        }
            // if the current character IS an operator (+ - * /)
        else if (check_if_operator(current_character)) {
            // Check if the operator is unary minus
            if (current_character == '-' && (character == 0 || infixNOSPACE[character - 1] == '(')) {

                // Append the negative number as a whole to the postfix string
                postfix += current_character;


            }
            else {

                // while stack is not empty AND top is not left parenthesis AND while top priority > current priorty or the top priority is equal to priority and the current character is not ^
                while (!operator_storage.empty() && operator_storage.top() != '(' &&
                       (check_priority(operator_storage.top()) > check_priority(current_character) ||
                        (check_priority(operator_storage.top()) == check_priority(current_character) && current_character != '^'))) {
                    // add top of stack to postfix
                    postfix += operator_storage.top();

                    //pop stack
                    operator_storage.pop();

                }
                // push current character to stack
                operator_storage.push(current_character);
                operator_storage.push(' ');


            }
        }
            // if current character is right paranthesis
        else if (current_character == ')') {
            // while stack is not empty and the top is not left parenthesis
            while (!operator_storage.empty() && operator_storage.top() != '(') {
                // add top to postfix
                postfix += operator_storage.top();
                // pop stack
                operator_storage.pop();
            }
            // if not empty and is left parenthesis
            if (!operator_storage.empty() && operator_storage.top() == '(')
                // just pop from stack
                operator_storage.pop();
        }
            // if current character is ad igit
        else if (isdigit(current_character)) {
            std::string temp_number;
            //add current character to string
            temp_number += current_character;
            //while next character is a digit; add to the string
            while (character + 1 < infix.length() && isdigit(infixNOSPACE[character + 1])){
                temp_number += infixNOSPACE[character+1];
                character++;
            }
            // add to postfix
            postfix += temp_number;
            // add whitespace inbetween characters
            postfix += " ";
        }
    }
    // while stack is not empty
    while (!operator_storage.empty()) {
        // add top
        postfix += operator_storage.top();
        // pop from stack
        operator_storage.pop();
    }
    // return for output
    return postfix;
}
std::string reallyDumbSolutions(const std::string& postfix){
    std::string peskyWhitespaceBeGone = postfix;
    //iterate through elements of the string
    for(size_t current_element = 0; current_element < peskyWhitespaceBeGone.length(); current_element++){
        //if current element is a space; and the previous element was a space...
        if (peskyWhitespaceBeGone[current_element] == ' ' && peskyWhitespaceBeGone[current_element-1] == ' '){
            //erase this element.
            peskyWhitespaceBeGone.erase(current_element, 1);
        }
    }
    return peskyWhitespaceBeGone;
}
int main(int argc, char *argv[]) {
    // CLA string for infix
    std::string infix = argv[1];
    // string variable that stores return from convert function passed infix
    std::string postfix = convert_infix_to_postfix(infix);

    std::string postfixFIXED = reallyDumbSolutions(postfix);
    // output for gradescope
    std::cout << postfixFIXED << "\n";

    return 0;
}

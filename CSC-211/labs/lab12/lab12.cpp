#include <iostream>
#include "lab12.h"
#include <vector>

//-------------------------------------
// Constructors
//-------------------------------------

// Default Constructor
MyString::MyString()
{
    std::vector<char> stringVector;
}

// Copy constructor; Copy the contents of the input string into the class's data member.
MyString::MyString(const char *string)
{
    // set string size to 0
    size_t size_of_string = 0;
    // while the current size of string does not equal the null terminator
    while (string[size_of_string] != '\0')
    {
        // increment one.
        ++size_of_string;
    }
    // set size of the vector to hold our string length.
    stringVector.resize(size_of_string);

    // iterate through each character; while less than our size. Add that character to our vector.
    for (size_t cur_char = 0; cur_char < size_of_string; ++cur_char)
    {
        stringVector[cur_char] = string[cur_char];
    }
}

// Destructor; Should deallocate any dynamically allocated memory that the class uses.
MyString::~MyString()
{
    stringVector.clear();
}

//-------------------------------------
// Setters and Getters
//-------------------------------------

// Sets the character at the given index to the character provided
void MyString::set(int index, char character)
{
    stringVector[index] = character;
}

// Returns the character at the given index.
char MyString::get(int index)
{
    return stringVector[index];
}

//-------------------------------------
// Methods
//-------------------------------------

// Public Methods

// Returns the length of string. This is the number of characters in the string,
// excluding the null terminator.
unsigned int MyString::len()
{
    // length is = to size of our vector
    return stringVector.size();
}

// Returns a pointer to a character array of the object's string.
const char *MyString::c_str()
{
    // add null terminator to end of vector
    stringVector.push_back('\0');

    // return pointer to the first element of the vector
    return stringVector.data();
}

// Reverse the string. "hello" should turn into "olleh".
// If you would like a challenge try to do it in-place (cannot create another array).
void MyString::reverse()
{
    // length
    size_t len = stringVector.size();

    for (size_t i = len; i >= 0; i--)
    {
    }
}

// Find the first occurrence of this character, and return the index.
// Return `-1` if it can't be found.
int MyString::find_first(char character)
{
    size_t len = stringVector.size();
    for (size_t i = 0; i < len / 2; ++i)
    {
        char temp = stringVector[i];
        stringVector[i] = stringVector[len - 1 - i];
        stringVector[len - 1 - i] = temp;
    }
}
// Find the first occurrence of the input string.
// Return the index of the starting character.
// Return the `-1` if it can't be found.
int MyString::find_first(const char *string)
{
    // Get the length of the input string
    size_t size_of_string = 0;
    while (string[size_of_string] != '\0')
    {
        ++size_of_string;
    }

    // Search for the input string in our string vector
    for (size_t i = 0; i <= stringVector.size() - size_of_string; ++i)
    {
        bool match = true;
        for (size_t j = 0; j < size_of_string; ++j)
        {
            if (stringVector[i + j] != string[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            return i;
        }
    }

    // If the input string is not found, return -1
    return -1;
}

// Find the last occurrence of this character, and return the index.
// Return the `-1` if it can't be found.
int MyString::find_last(char c)
{
    for (int i = stringVector.size() - 1; i >= 0; i--)
    {
        if (stringVector[i] == c)
        {
            return i;
        }
    }
    return -1;
}

// Find the last occurrence of the input string.
// Return the index of the starting character.
// Return the `-1` if it can't be found.
int MyString::find_last(char character)
{
    int last_index = -1;
    for (size_t i = 0; i < stringVector.size(); ++i)
    {
        if (stringVector[i] == character)
        {
            last_index = i;
        }
    }
    return last_index;
}

// Return true if the str stored is equivalent to the given string
// Return false if they are not the same
bool MyString::compare(const char *)
{
    return 0;
}

// Append a single character onto the end of the string.
void MyString::append(char)
{
    return;
}

// Concatenate the input string to the object's string.
void MyString::append(const char *)
{
    return;
}

//-------------------------------------
// Operator Overloading
//-------------------------------------

// Overload the '[]' operator to fuction as we expect
//  Ex. MyString("Hello")[2] == 'l'
char MyString::operator[](const unsigned int index) const
{
    return 'a';
}

// Overload the '+' operator to concatenate the two strings together
MyString MyString::operator+(const MyString str2) const
{
    MyString temp;
    return temp;
}

// Overload the '*' operator to return the string concatenated on itself x times
// Ex. "Hello" * 3 == "HelloHelloHello"
MyString MyString::operator*(const int x) const
{
    MyString temp;
    return temp;
}

//////////////////////////////////////////////////////////
/// group members shit ///

// #include <iostream>
// #include <cstring>

// class MyString {
//     private:
//         char* m_str; // The pointer to the dynamic character array that holds the string.
//         unsigned int m_length; // The length of the string.

//     public:
//         // Default constructor; Should store an empty string.
//         MyString() {
//             m_str = new char[1];
//             m_str[0] = '\0';
//             m_length = 0;
//         }

//         // Copy constructor; Copy the contents of the input string into the class's data member.
//         MyString(const char* str) {
//             m_length = strlen(str);
//             m_str = new char[m_length + 1];
//             std::strcpy(m_str, str);
//         }

//         // Destructor; Should deallocate any dynamically allocated memory that the class uses.
//         ~MyString() {
//             delete[] m_str;
//         }

//         // Returns the length of string. This is the number of characters in the string,
//         // excluding the null terminator.
//         unsigned int len() {
//             return m_length;
//         }

//         // Sets the character at the given index to the character provided
//         void set(int index, char c) {
//             if (index >= 0 && index < m_length) {
//                 m_str[index] = c;
//             }
//         }

//         // Returns the character at the given index.
//         char get(int index) {
//             if (index >= 0 && index < m_length) {
//                 return m_str[index];
//             }
//             return '\0'; // return null character if the index is out of bounds.
//         }

//         // Returns a pointer to a character array of the object's string.
//         const char* c_str() {
//             return m_str;
//         }

//         // Reverse the string. "hello" should turn into "olleh".
//         // If you would like a challenge try to do it in-place (cannot create another array).
//         void reverse() {
//             for (int i = 0; i < m_length / 2; ++i) {
//                 char temp = m_str[i];
//                 m_str[i] = m_str[m_length - i - 1];
//                 m_str[m_length - i - 1] = temp;
//             }
//         }

//         // Find the first occurrence of this character, and return the index.
//         // Return `-1` if it can't be found.
//         int find_first(char c) {
//             for (int i = 0; i < m_length; ++i) {
//                 if (m_str[i] == c) {
//                     return i;
//                 }
//             }
//             return -1;
//         }

//         // Find the first occurrence of the input string.
//         // Return the index of the starting character.
//         // Return the `-1` if it can't be found.
//         int find_first(const char* str) {
//             int str_length = strlen(str);
//             for (int i = 0; i <= m_length - str_length; ++i) {
//                 int j;
//                 for (j = 0; j < str_length; ++j) {
//                     if (m_str[i + j] != str[j]) {
//                         break;
//                     }
//                 }
//                 if (j == str_length) {
//                     return i;
//                 }
//             }
//             return -1;
//         }

//         // Find the last occurrence of this character, and return the index.
//         // Return the `-1` if it can't be found.
//         int find_last(char c) {
//             for (int i = m_length - 1; i >= 0; --i)
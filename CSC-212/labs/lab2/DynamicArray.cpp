#include "DynamicArray.h"
#include <cstring>
#include <iostream>

// "Fancy" way to write a default constructor.
// Note: The other constructors can *NOT* be written this way!
DynamicArray::DynamicArray()
        : m_length(0), m_capacity(1), m_scaling_factor(2.0), m_data(new int[1]) {
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    //// TODONE
    this->m_scaling_factor = scaling_factor; //set SF
    this->m_capacity = capacity; //set capacity
    this->m_length = 0;
    this->m_data = new int[m_capacity]; // memory space for array set to capacity.
}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    //// TODONE
    this->m_scaling_factor = scaling_factor;
    this->m_capacity = length; // set to length as per instructions
    this->m_length = m_capacity;
    this->m_data = new int[this->m_capacity]; // mem space set to capacity.

    for (unsigned int currentElement = 0; currentElement < this->m_capacity; currentElement++){
        this->m_data[currentElement] = default_value;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other;
}
//// TEST LINE FOR ME
void DynamicArray::displayMemberStatus(){
//    std::cout << "Capacity = " << m_capacity << "\nScaling Factor = " << m_scaling_factor << "\n";
//    if (m_data != nullptr){
//        std::cout << "Mem Allocation Success. \n";
//    } else {
//        std::cout << "Mem Allocation Failed. \n";
//    }
    for (unsigned int currentElement = 0; currentElement < m_length; currentElement++){
        std::cout << m_data[currentElement] << " ";
    }
    std::cout << "\n";
}
//// END TEST LINE FOR ME
// Destructor: destroys the dynamically allocated array on the heap
DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::get_length() {
    return m_length;
}

unsigned int DynamicArray::get_capacity() {
    return m_capacity;
}

double DynamicArray::get_scaling_factor() {
    return m_scaling_factor;
}

void DynamicArray::set_scaling_factor(double value) {
    m_scaling_factor = value;
}

std::string DynamicArray::to_string() {
    // Initialize an empty string
    std::string str("");
    //// TODO-ing
    for (unsigned int currentElement = 0; currentElement < m_length; currentElement++){
        std::cout << m_data[currentElement] << " ";
    }
    std::cout << "\n";
    return str;
}

bool DynamicArray::find_first_of(int value, unsigned int *index) {
    bool found = false;
    // TODONE

    for (unsigned int curElm = 0; curElm < m_length; curElm++ ){
        if (m_data[curElm] == value){
            found = true;
            *index = curElm;
            return found;
            break; // it's found? why continue...
        }
    }

    return found;
}

bool DynamicArray::find_last_of(int value, unsigned int *index) {
    bool found = false;
    // TODO
    for(unsigned int curElm = m_length - 1; curElm >= 0; curElm--){
        if(m_data[curElm] == value){
            found = true;
            *index = curElm;
            return found;
            break; //first time we find it we are done; that is the last element of value.
        }
    }
    return found;
}

void DynamicArray::append(int value) {

//    std::cout << "length = " << m_length << " capacity = " << m_capacity << "\n";
//    std::cout << "This is value in append: " << value << "\n";
//    std::cout << "m_data at start --- \n";

    //// TODONE
//    std::cout << m_length << "\n";
    // if array's length is at or above capacity
    if (m_length >= m_capacity){
        //set newCapacity based on scaling factor
        unsigned int new_capacity = static_cast<unsigned int>(m_capacity * m_scaling_factor);
        // new data with new cap
        int *new_data = new int[new_capacity];

        //move elements from old -> new
        for (unsigned int curElem = 0; curElem < m_length; curElem++){
            new_data[curElem] = m_data[curElem];
        }
        //delete old data - chck if nullptr first
        if (m_data != nullptr) {
            delete[] m_data;
        }

        // update arry ptr and capacity
        m_data = new_data;
        m_capacity = new_capacity;
    }
    //finally... append the value to end of data array
    m_data[m_length] = value;
    //increment length for accuracy
    m_length++;
//    std::cout << "m_data at end --- \n";
//    for (unsigned int currentElement = 0; currentElement < m_capacity; currentElement++){
//        std::cout << m_data[currentElement] << " ";
//    }
//    std::cout << "\n";
}

void DynamicArray::prepend(int value) {
    //// TODONE
    //if length will exceed capacity
    if (m_length >= m_capacity){
        //set newCapacity based on scaling factor
        unsigned int new_capacity = static_cast<unsigned int>(m_capacity * m_scaling_factor);
        // new data with new cap
        int *new_data = new int[new_capacity];

        //move elements over 1 position -- into new data
        for (unsigned int curElm = 1; curElm <= m_length; curElm++){
            new_data[curElm] = m_data[curElm - 1];
        }
        //delete old data - chck if nullptr first
        if (m_data != nullptr) {
            delete[] m_data;
        }

        // update arry ptr and capacity
        m_data = new_data;
        m_capacity = new_capacity;
    }
    //otherwise just shift
    else {
        // move elems in data to make space for value
        for (unsigned int curElm = m_length; curElm > 0; curElm--){
            m_data[curElm] = m_data[curElm -1];
        }
    }

    // now actually prepend the value...
    m_data[0] = value;
    m_length++;

}

void DynamicArray::remove_last() {
    //// TODONE
    if(m_length > 0){
        m_length--; //remove 1 from length == of deleting last element.
    }
}

void DynamicArray::remove_first() {
    //// TODONE
    if (m_length > 0) {
        // Shift elements to the left by one position
        for (unsigned int i = 0; i < m_length - 1; i++) {
            m_data[i] = m_data[i + 1];
        }
        m_length--; // Decrement the length to exclude the first element
    }
}

void DynamicArray::clear() {
    // TODONE
    delete[] m_data;
    m_data = nullptr;
    m_length =0;
    m_capacity = 0;
}

// Examples of "operator overloading"
int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);
    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this);
}
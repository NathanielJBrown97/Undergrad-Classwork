#include "hash_table.h"
#include <iostream>
/// Fills vector and sets mode / size
HashTable::HashTable(int mode){
    this->mode = mode; // set mode for direction of constructor
    this->max_size = 1; // set standard max_size of vector to 4
    this->size = 0; // set initial contained size to 0. Nothing is in here yet.
    ///Depending on mode value; conditionally direct constructor.
    /// Linear Probing
    if (this->mode == 0){
        for(int cur_elem = 0; cur_elem < this->max_size; cur_elem++){
            this->table.push_back(0); // Fill starting vector with 0s. DO NOT ADJUST SIZE 0 represents empty vector.
        }
    }

}
/// Hash 1 k % max_size
int HashTable::h1(int k){
    return k % this->max_size;
}
/// Hash 2 k^2 % max_size
int HashTable::h2(int k){
    return (k*k) % this->max_size;
}

/// Resize function; needs to store original vector data... then re-insert original data...
void HashTable::resize(){
//    std::cout << "this->table BEFORE RESIZE \n";
//    print_table();
//    for(int i = 0; i < order_t.size(); i++){
//        std::cout << order_t[i] << "\n";
//    }
//    std::cout << "The size of temp vect is " << order_t.size() << "\n";
    this->max_size *= 2; // multiply max size by 2
    this->size = 0; //reset the current size to 0. (This will increment below in insert)

    /// Linear Probing
    if (this->mode == 0){

    this->table.resize(this->max_size); // resizes element to new size and fills with 0s vector function
    //// TODO: This creates segmentation fault --- STILL DOES IT
//    std::cout << "The value of max size at this point is: " << this->max_size << "\n";
        for(int cur_elem = 0; cur_elem < 16; cur_elem++){
            table[cur_elem] = 0; // Fill starting vector with 0s. DO NOT ADJUST SIZE 0 represents empty vector.
        }
//    std::cout << "DURING RESIZE -> BEFORE RE-INSERT: \n";
//    for(int i = 0; i < table.size(); i++){
//        std::cout << "Index: " << i << " " << table[i] << "\n";
//    }

    // re-insert elements...
    for(int cur_elem = 0; cur_elem < this->order_t.size(); cur_elem++){
        insert(order_t[cur_elem]);
    }
//    std::cout << "this->table AFTER RESIZE \n";
//    print_table();
//    std::cout << "ORDER T Elements \n";
//    for (int i = 0; i < order_t.size(); i++){
//        std::cout << order_t[i] << " ";
//    }
//    std::cout << "\n";
    }

}
/// is it in this->table?
bool HashTable::withinHashTable(int value){
//    std::cout << "Is bool function being ran? \n";
    for (int cur_element = 0; cur_element < this->table.size(); cur_element++){
//        std::cout << "Is " << this->table[cur_element] << " == " << value << "\n";
        if (this->table[cur_element] == value){
            return true;
        }
    }
    return false;
}


/// Insert function; passed element... inserts into the vector...
void HashTable::insert(int value_in_file){
//    std::cout << ">>>>>>>> Number TO INSERT <<<<<<<<<<<<<< " << value_in_file <<"\n";
    for(int i = 0; i < this->table.size(); i++){
//        std::cout << "Is " << this->table[i] << " == " << value_in_file <<"\n";
        if(this->table[i] == value_in_file){
            return;
        }
    }
    if (withinHashTable(value_in_file) == true){
//        std::cout << " Are we running this? \n";
        return; // exit this function if we're evaluating a number twice...
    }

//    std::cout << "cur size: " << this->size << "max size: " << this->max_size << "\n";
    if (this->size+1 >= 0.7 * table.size()){ //if current size is greater than or equal to 70% of max size
        resize(); //call resize before we insert current value_in_file.
    }
    if (this->mode == 0){
        int position_to_insert = h1(value_in_file); // pass value in file to hash1 to determine index for insert
        if (this->table[position_to_insert] == 0) { //if the position currently holds a 0, its empty.
            this->table[position_to_insert] = value_in_file; // replace index with the value
            this->size ++; //increment size on insert
        }
        else{ //otherwise positions is != 0 and we must do linear probing
            for(int i = 0; i < this->table.size(); i++){
//                std::cout << "Is " << this->table[i] << " == " << value_in_file <<"\n";
                if(this->table[i] == value_in_file){
                    return;
                }
            }
//            print_table();
//            std::cout << "Else is triggered... i.e. +1 collision\n";
//            std::cout << "collision occured on index : " <<position_to_insert << "\n";
            this->collisions = this->collisions + 1; // if we enter this else... there is a collision to be counted
            int next_available_position;
            bool flag_for_break = false;
            for (int cur_position = position_to_insert; cur_position <= max_size; cur_position++){

                if(this->table[cur_position] == 0 && flag_for_break == false){
                    next_available_position = cur_position;
                    flag_for_break = true;
//                    std::cout << "next available position i.e. where we place it = " << next_available_position << "\n";
                }
            }
            this->table[next_available_position] = value_in_file;
            this->size ++; //increment size on insert
        }
//        std::cout << position_to_insert << "<--- is the position to insert... " << value_in_file << "\n";

        //// TODO: SHIT NO COUNT RIGHT
    }
}

void HashTable::fill_order_t(int value_in_file){
    order_t.push_back(value_in_file);
}

/// Outputs collisions
int HashTable::get_num_collisions() {
    return this->collisions; //return collision counter
}
/// Outputs this->table
void HashTable::print_table() {
    for (int cur_elem = 0; cur_elem < max_size; cur_elem++) {
        std::cout << "Index " << cur_elem << ": " << this->table[cur_elem] << "\n";
    }
}
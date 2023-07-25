#include <vector>
#include <string>

class HashTable {
private:
    std::vector<int> table;
    std::vector<int> order_t; //intended order of table
    int size;
    int max_size;
    int mode;

    int collisions = 0;

public:
    HashTable(int mode); //constructor fills with 0s and sets mode
    int get_num_collisions(); // returns collisions

    int h1(int k); // hash 1 k % max_size
    int h2(int k); // hash 2 k^2 % max_size

    bool withinHashTable(int value); //return boolean if value is within table
    void insert(int value_in_file); // insert function; given an element from the txt to insert into the size...

    void resize(); // function to resize table...

    void print_table(); //prints table for checking / gradescope

    void fill_order_t(int value_in_file); //fills the order table...
};



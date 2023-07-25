#include "node.h"
#include <vector>
#include <string>

class PriorityQueue {
private:
    Node* head; // track front
    Node* tail; // track back
    Node* priority;
    unsigned int size;
public:
    PriorityQueue(); // this - > head
    PriorityQueue(int data);
    PriorityQueue(std::vector<int>);
    ~PriorityQueue();

    void enPriorityQueue(int data); //push ele to back
    void dePriorityQueue(); //remove ele from front

    int peek(); // return element at front of PriorityQueue
    std::string to_string(); // cout
};




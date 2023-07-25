#include "node.h"
#include <vector>
#include <string>

class Queue {
private:
    Node* head; // track front
    Node* tail; // track back
    unsigned int size;
public:
    Queue(); // this - > head
    Queue(int data);
    Queue(std::vector<int>);
    ~Queue();

    void enqueue(int data); //push ele to back
    void dequeue(); //remove ele from front

    int peek(); // return element at front of queue
    std::string to_string(); // cout
};




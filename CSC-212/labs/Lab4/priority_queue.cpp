#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}
PriorityQueue::PriorityQueue(int data){
    this->head = new Node(data);
    this->tail = this->head; // since size 1; tail is head, head is tail. circle of life
    this->size = 1;
}
PriorityQueue::PriorityQueue(std::vector<int> vec){
    if (vec.size() == 0){
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    else {
        this->head = new Node(vec[0]);
        Node* temp = this->head;

        for(int i = 1; i < vec.size(); i++){
            temp->next = new Node(vec[i]);
            temp = temp->next;
        }
        this->tail = temp;
    }
    this->size = vec.size();
}
PriorityQueue::~PriorityQueue(){
    delete this->head;
    delete this->tail;
    this->head = nullptr;
    this->tail = nullptr;
}
//push ele to back - should only require tail to be modified.
void PriorityQueue::enPriorityQueue(int data){
    Node* enPriorityQueueNode = new Node(data);
    if(this->head == nullptr){
        this->head = enPriorityQueueNode;
        this->tail = enPriorityQueueNode;
    }
    else{
        this->tail->next = enPriorityQueueNode;
        this->tail = enPriorityQueueNode;
    }
    this->size++;
}
//remove ele from front
void PriorityQueue::dePriorityQueue() {
//    std::cout << "made it to dePriorityQueue";
    //std::cout << "head and next data; before dePriorityQueue " << this->head->data << " " << this->head->next->data << "\n";
    if (this->size == 0) {
//        std::cout << "Size is wrong?";
        this->head = nullptr;
        this->tail = nullptr;
    } else {
//        std::cout << "Else being read";
        Node *tmpHead = this->head;
        this->head = this->head->next;
        // std::cout << "head and next data; after moving them... " << this->head->data << " " << this->head->next->data << "\n";

        //std::cout << "Proof tmpHead is being deleted: " << tmpHead->data;
        this->size--;
        if (this->size == 0) {
            this->tail = nullptr;
        }

    }
}
// return element at front of PriorityQueue
int PriorityQueue::peek(){
    if(this->size == 0){
        return -1;
    }
    else{
        return this->head->data;
    }
}

//cout
std::string PriorityQueue::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while (tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }
    return stringified;
}
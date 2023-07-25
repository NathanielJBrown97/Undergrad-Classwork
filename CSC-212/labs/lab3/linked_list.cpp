#include "linked_list.h"
#include <iostream>


LinkedList::LinkedList(){
    this->head = nullptr;
    this->size = 0;
}


LinkedList::LinkedList(int data){
    this->head = new Node(data);
    this->size = 1;

}


LinkedList::LinkedList(std::vector<int> vec){
    this->head = nullptr;
    this->size = 0;

    if (!vec.empty()){
        this->head = new Node(vec[0]);
        Node* current = this->head;

        for (std::size_t current_index = 1; current_index < vec.size(); current_index++){
            Node* newNode = new Node(vec[current_index]);
            current->next = newNode;
            current = newNode;
        }
        current->next = nullptr;
        this->size = vec.size();
    }
}

LinkedList::~LinkedList() {
    delete this->head;

    this->head = nullptr;
}


void LinkedList::push_front(int data){
    // test case for push_front onto an empty list
    if (this->size == 0){
        Node* frontNode = new Node(data);
        frontNode->next = nullptr;
        this->head = frontNode;
        this->size += 1;
    }
    else {
        Node* frontNode = new Node(data);
        frontNode->next = head;

        this->head = frontNode;
    }
}

void LinkedList::push_back(int data){
    if (this->size == 0){
        Node* backNode = new Node(data);
        this->head = backNode;
        this->size += 1;
    }
    else{
        Node* backNode = new Node(data);
        Node* tempFindEnd = new Node();

        tempFindEnd = this->head;

        while (tempFindEnd->next != nullptr){
            tempFindEnd = tempFindEnd->next;
        }
        tempFindEnd->next = backNode;

    }
    this->size += 1;
}

void LinkedList::insert(int data, int idx) {
    ///// For any `idx` > `size`, append the value

    if (this->head == nullptr){
        this->head = new Node(data);   // if empty list; make new node with the data; set it as head
    }
    else if (idx == 0){
        push_front(data);
    }
    else if (this->size < idx){
        push_back(data);
    }
    else {
        Node* insertNode = new Node(data);
        Node* current = head;
        int currentIndex = 0;

        while (currentIndex < idx -1 ){
            current = current->next;
            currentIndex++;
        }
        insertNode->next = current->next;
        current->next = insertNode;

    }
    size++;
}

void LinkedList::remove(int data) {
    Node* curr = this->head;
    Node* prev = nullptr;

    // Search for the element in our list
    while(curr != nullptr && curr->data != data){
        prev = curr;
        curr = curr->next;
    }

    // We found the element
    if(curr != nullptr){
        // Special case: deleting the head
        if(curr == this->head){
            this->head = curr->next;
        }else{
            prev->next = curr->next;
        }

        // Without this, the Node destructor will delete
        // every element in the list after 'temp'
        curr->next = nullptr;
        delete curr;

        this->size--;
    }
}












bool LinkedList::contains(int data){
    Node* current = head;

    while (current != nullptr){
        if (current->data == data){
            return true;
        }
        current = current -> next;
    }
    return false;

}


int LinkedList::get_size(){
    return this->size;
}


// O(n)
std::string LinkedList::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}
#include <stdexcept>
struct Node {
  Node(int val) : value(val), next(nullptr) {}
  int value;
  Node *next;
};


class LinkedList{
    Node* head;

public:
    int at(size_t index) const{
        unsigned int count = 0;
        Node* current = head;
        while(current){
            if(count == index){
                return current->value;
            }
            count++;
        }
        if(index > count){
            throw std::out_of_range("Given index is out of range of linked list");
        }
    }
    void insert(size_t index, int value){
        unsigned int count = 0;
        Node* current = head;
        Node* newNode = new Node(value);
        if(index == 0){
            Node* temp = head;
            head = newNode;
            newNode->next = temp;
            return;
        }
        //returns count of list
        while(current){
            count++;
            current = current->next;
        }
        //dealing with out of bounds before checking for index
        if(index > count){
            throw std::out_of_range("Given index is out of range of linked list");
        }
        unsigned int totalCount = count;
        count = 0;
        while(current){
            if(count == index-1 && totalCount == index){
                current->next = newNode;
                return;
                //newNode next already equals nullptr in constructor
            }
            count++;
            current = current->next;
        }
        count = 0;
        while(current){
            if(count == index-1 && totalCount != index){
                Node* temp = current->next;
                current->next = newNode;
                newNode->next = temp;
                return;
            }
            count++;
            current = current->next;
        }
    }
    void merge (const LinkedList& other){
        unsigned int thisCounter = 0;
        unsigned int otherCounter = 0;
        Node* thisCurrent = head;
        Node* otherCurrent = other.head;
        while(thisCurrent){
            thisCounter++;
            thisCurrent = thisCurrent->next;
        }
        while(otherCurrent){
            otherCounter++;
            otherCurrent = otherCurrent->next;
        }

        if(otherCounter > 0 && thisCounter > 0){
            Node* temp = head;
            Node* newNode = new Node(other.head->value);
            head = newNode;
            newNode->next = temp;
        }
        unsigned int totalCount1 = thisCounter;
        unsigned int totalCount2 = otherCounter;
        thisCounter = 1;
        otherCounter = 1;
        thisCurrent = head->next;
        otherCurrent = other.head;
        while(thisCurrent){
            if(thisCounter%3 == 0){
                Node* temp = thisCurrent->next;
                Node* newNode = new Node(otherCurrent->value);
                thisCurrent->next = newNode;
                newNode->next = temp;
            }
            thisCurrent = thisCurrent->next;
            thisCounter++;
            otherCurrent = otherCurrent->next;
            otherCounter++;
            if(thisCounter == totalCount1 -1){
                while(otherCurrent){
                    Node* newNode = new Node(otherCurrent->value);
                    thisCurrent->next = newNode;
                    otherCurrent = otherCurrent->next;
                    thisCurrent = thisCurrent->next;
                }
            }
        }
    }
};
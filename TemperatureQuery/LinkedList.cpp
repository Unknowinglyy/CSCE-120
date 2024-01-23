#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList():head(nullptr),tail(nullptr){
}

LinkedList::~LinkedList() {
	clear();
}

LinkedList::LinkedList(const LinkedList& source):head(source.head),tail(source.tail){
	Node* curr = source.head;
	Node* path = nullptr;
	while(curr != nullptr){
		Node* newNode = new Node(*curr);
		if(head == nullptr){
			head = newNode;
		}
		if(path != nullptr){
			path->next = newNode;
		}
		path = newNode;
		curr = curr->next;
	}
	tail = path;
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	if(this != &source){
		clear();
		Node* curr = source.head;
		Node* path = nullptr;
		while(curr != nullptr){
			Node* newNode = new Node(*curr);
			if(head == nullptr){
				head = newNode;
			}
			if(path != nullptr){
				path->next = newNode;
			}
			path = newNode;
			curr = curr->next;
		}
		tail = path;
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	Node* newNode = new Node(location,year,month,temperature);
	if(head == nullptr){
		head = newNode;
	}
	else{
		Node* curr = head;
		Node* path = nullptr;
		while(curr != nullptr){
			if( curr->data.getID() > newNode->data.getID()){
				break;
			}
			else if(curr->data.getID() == newNode->data.getID() && curr->data.getYear() > newNode->data.getYear()){
				break;
			}
			else if(curr->data.getYear() == newNode->data.getYear() && curr->data.getMonth() >= newNode->data.getMonth()){
				break;
			}
			else{
				path = curr;
				curr = curr->next;
			}
		}
		if(curr == head){
			newNode->next = head;
			head = newNode;
		}
		else{
			newNode->next = curr;
			path->next = newNode;
		}
	}
}

void LinkedList::clear() {
	Node* nextN = nullptr;
	while(head != nullptr){
		nextN = head->next;
		delete head;
		head = nextN;
	}
	head = nullptr;
	tail = nullptr;
}

Node* LinkedList::getHead() const {
	return this->head;
}

string LinkedList::print() const {
	string outputString = "";
	Node* curr;
	curr = head;
	while(curr != nullptr){
		stringstream input;
		input << curr->data.getYear() << " " << curr->data.getMonth() << " " << curr->data.getTemp();
		string string1 = input.str();
		outputString += curr->data.getID() + " " + string1 + "\n";
		curr = curr->next;
	}
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}

#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node():data(),next(nullptr) {} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature):data(id,year,month,temperature),next(nullptr) {}
// remember to initialize next to nullptr

bool Node::operator<(const Node& b) {
	return this->data < b.data;
}

Node::Node(const Node& source):data(source.data),next(source.next){
	Node* newNode = new Node();
	newNode->next = source.next;
	newNode->data = source.data;
}

Node& Node::operator=(const Node& other){
	if(this != &other){
		data = other.data;
		next = other.next;
	}
	return *this;
}


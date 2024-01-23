#include <iostream>
#include <stdexcept>
struct Node {
  int value;
  Node* next;
  Node(): value(0), next(nullptr){}
  Node(int num = 0) : value{num}, next{nullptr} {}
};

class LinkedList {
  Node* head;

 public:
  LinkedList() : head{nullptr} {}
  ~LinkedList(){
      Node*current = head;
      while(current != nullptr){
          Node* temp = current->next;
          delete current;
          current = temp;
      }
  }

  // other member functions

  double getAverage(Node* head){
      Node* curr = head;
      double sum = 0.0;
      unsigned int count = 0;
      while(curr){
          sum+= curr->value;
          count++;
          curr->next;
      }
      if(count == 0){
          throw std::invalid_argument("List is empty");
      }
      return (sum/count);
  }

  void removeMax (){
      Node* curr = head->next;
      int max = head->value;
      Node* temp;
      while(curr){
          if(curr->value > max){
              max = curr->value;
          }
          curr = curr->next;
      }
      curr = head;
      while(curr){
          //if head has a max value
          if(curr->value == max && curr == head){
              temp = curr->next;
              curr->value = -1;
              curr = nullptr;
              head = temp;
          }
          //if the last node has a max value
          if(curr->value == max && curr->next == nullptr){
              curr->value = -1;
              curr = nullptr;
          }
          if(curr != nullptr){
              curr = curr->next;
          }
      }
  }
  void insert(int val){
      Node* newNode = new Node(val);

      if(head == nullptr){
          head = newNode;
          head->next = nullptr;
          return;
      }
      if(head != nullptr){
        Node* current = head;
        while(current){
            if(current->next == nullptr){
                current->next = newNode;
                return;
            }
            current = current->next;
        }
  }
  }
  void Print(){
      Node* current = head;
      while(current != nullptr){
          std::cout << current->value << std::endl;
          current = current->next;
      }
  }
};

using namespace std;
int main(){
    LinkedList ll;
    ll.insert(18);
    ll.insert(7);
    ll.insert(15);
    ll.insert(27);

    ll.removeMax();
    cout << "test" << endl;
    ll.Print();
    return 0;
}

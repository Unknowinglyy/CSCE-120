#include <iostream>

struct Node {
  Node(int val) : value(val), m_pNext(nullptr), m_pPrev(nullptr) {}

  int value;
  Node *m_pNext;
  Node *m_pPrev;
};

class LinkedList {

public:
  LinkedList() : m_pHead(nullptr), m_pTail(nullptr) {}

  ~LinkedList() {
    Node *pCurrent = m_pHead;
    while (pCurrent != nullptr) {
      Node *pTemp = pCurrent->m_pNext; // nullptr
      delete pCurrent;
      pCurrent = pTemp;
    }
  }

  void Insert(int val) {
    Node *pNode = new Node(val);

    // Check if the list is empty
    if (m_pHead == nullptr) {
      m_pHead = pNode;
      m_pTail = pNode;
      return;
    }

    // Node 3
    // Node 1 -> Node 2 -> Node 3
    m_pTail->m_pNext = pNode;
    m_pTail = pNode;
  }

  void Print() {
    Node *pCurrent = m_pHead;
    while (pCurrent != nullptr) {
      std::cout << pCurrent->value << ", ";
      pCurrent = pCurrent->m_pNext;
    }
    std::cout << std::endl;
  }

private:
  Node *m_pHead;
  Node *m_pTail;
};

int main() {
  LinkedList ll;
  ll.Insert(10);
  ll.Insert(20);

  ll.Insert(30);
  ll.Insert(40);

  ll.Print();

  return 0;
}
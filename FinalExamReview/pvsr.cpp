#include <iostream>

#include "functions.h"

#include "functions.h"

void PrintByPtr(int *pVal) {
  if (pVal) {
    (*pVal) *= 2;
    std::cout << "Ptr val: " << (*pVal) << std::endl;
  }
}

void PrintByRef(int &val) {
  val *= 2;
  std::cout << "Ref val: " << val << std::endl;
}

int main() {
  int val = 10;
  PrintByPtr(&val);

  PrintByRef(val);

  std::cout << "Main val: " << val << std::endl;

  SomeFunction();

  return 0;
}
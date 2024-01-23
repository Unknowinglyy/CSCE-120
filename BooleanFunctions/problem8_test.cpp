#include <iostream>
#include "problem8.h"

using std::cin, std::cout, std::endl;

bool f(bool x, bool y, bool z) {
  bool value = (!x && !y && z) || (!x && y && !z) || (!x && y && z) || (x && !y && !z) || (x && y && z);
  return value;
}

int main(){
	cout << "(0,0,0)" << f(0,0,0) << endl;
	cout << "(0,0,1)" << f(0,0,1) << endl;
	cout << "(0,1,0)" << f(0,1,0) << endl;
	cout << "(0,1,1)" << f(0,1,1) << endl;
	cout << "(1,0,0)" << f(1,0,0) << endl;
	cout << "(1,0,1)" << f(1,0,1) << endl;
	cout << "(1,1,0)" << f(1,1,0) << endl;
	cout << "(1,1,1)" << f(1,1,1) << endl;
}
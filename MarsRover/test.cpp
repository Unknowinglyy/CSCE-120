#include <iostream>
#include <fstream>
#include "Rover.h"
#include "MyString.h"
using std::cin, std::cout, std::endl, std::ifstream, std::istream;

// helper function "stoi" to converts MyString to int, works a lot like number slicing in reverse
int stoi(const MyString& str, size_t* pos = nullptr, int base = 10) { // just doing base 10 here
	int result = 0;
	for (unsigned int i = 0; i < str.size(); i++) { // MyString: size()
		if (str.at(i) >= '0' && str.at(i) <= '9') { // MyString: at()
			result *= 10; // increase digit (reverse of number slicing)
			result += str.at(i) - 48; // using ascii for conversion
		}
	}
	return result;
}

// helper function for insertion allows reading from input stream to MyString
istream& operator>>(istream& is, MyString& str) {
	str.clear();
	while (!is.eof()) {
		char c;
		is >> std::noskipws >> c; // use the noskipws manipulator
        cout << "Current Character: " << c << endl;
        cout << "First String: " << str << endl;
		if (isspace(c) || is.fail()) break; // if whitespace, can stop adding to string
		const char* newstr = new char[2] {c, '\0'};
        cout << "Checkpoint 1" << endl;
		MyString newc = MyString(newstr); // MyString: copy constructor
        cout << "Checkpoint 2" << endl;
		delete[] newstr;
		str += newc; // MyString: operator+=()
        cout << "2nd String: " << str << endl;
	}
    cout << "Checkpoint 3" << endl;
	return is;
}
int main () {
    cout << "Test started" << endl;
    const char array[] = {'l','l','\0'};
    const char array2[] = {'a','l','l','\0'};
    MyString filename(array2);
    MyString filename2(array);
    MyString filename3 = filename2;
    cout << "Filename: " << endl;
    cout << filename3.data() << endl;
    cout << filename3.size() << endl;
    cout << "Test completed" << endl;
}
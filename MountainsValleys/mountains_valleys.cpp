#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
	// TODO(student): print prompt for input
	cout << "Enter numbers 10 <= a <= b < 10000: ";
	// TODO(student): read the numbers from standard input
	int firstNumber;
	int lastNumber;
	cin >> firstNumber >> lastNumber;
	// TODO(student): validate input (and reprompt on invalid input)
	while (!(is_valid_range(firstNumber, lastNumber))) {
		cout << "Invalid Input" << endl;
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> firstNumber >> lastNumber;

	}
	// TODO(student): compute and display solution
	count_valid_mv_numbers(firstNumber, lastNumber);
	return 0;
}
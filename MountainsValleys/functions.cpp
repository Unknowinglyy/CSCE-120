#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if (a >= 10 && a <= b && b < 10000) {
		return true;
	}
	else {
		return false;
	}
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	int numLength = 0;
	for (int i = number; i != 0; i/= 10) {
		numLength++;
	}
	if (numLength == 1) {
	    return 'N';
	}
	int digit1;
	int digit2;
	int increasing = 0;
	int decreasing = 0;
	int newNumLength = numLength;
	char lastRate = 'N';
	char prevRate = 'N';
	while(number >= 10){
		digit1 = number % 10;
		number /= 10;
		newNumLength--;
		digit2 = number % 10;
		if(digit1 > digit2){
			increasing++;
			if(prevRate == 'N' || prevRate == 'D'){
				prevRate = 'I';
			}
			else if(prevRate == 'I'){
				return 'N';
			}
		}
		else if(digit1 < digit2){
			decreasing++;
			if(prevRate == 'N' || prevRate == 'I'){
				prevRate = 'D';
			}
			else if(prevRate == 'D'){
				return 'N';
			}
		}
		else if(digit1 == digit2){
			return 'N';
		}
		if(newNumLength == 2){
			digit1 = number % 10;
			digit2 = number / 10 % 10;
			if(digit1 > digit2){
				lastRate = 'I';
			}
			else if(digit1 < digit2){
				lastRate = 'D';
			}
			else if (digit1 == digit2){
			    return 'N';
			}
			}
		if(numLength == 2){
			if(digit1 > digit2){
				lastRate = 'I';
			}
			else if(digit1 < digit2){
				lastRate = 'D';
			}
			else if (digit1 == digit2){
			    return 'N';
			}
		}
		}
	if((increasing == decreasing && lastRate == 'D') || (increasing+1 == decreasing && lastRate == 'D') || (increasing == decreasing+1 && lastRate == 'D')){
		return 'V';
	}
	else if((increasing == decreasing && lastRate == 'I') || (increasing+1 == decreasing && lastRate == 'I') || (increasing == decreasing+1 && lastRate == 'I')){
		return 'M';
	}
	return 'N';
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	int mountainsCounter = 0;
	int valleyCounter = 0;
		for (int i = a; i <= b; i++) {
			if (classify_mv_range_type(i) == 'M') {
				mountainsCounter++;
			}
			else if (classify_mv_range_type(i) == 'V') {
				valleyCounter++;
			}
			else if(classify_mv_range_type(i) == 'N'){
				continue;
			}
		}
	cout << "There are " << mountainsCounter << " mountain ranges and " << valleyCounter << " valley ranges between " << a << " and " << b << "." << endl;
}
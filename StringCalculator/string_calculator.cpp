#include <iostream>
#include <string>
#include "./string_calculator.h"
#include <sstream>
using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    if(digit == '0' || digit == '1' || digit == '2' || digit == '3' ||  digit == '4' || digit == '5' || digit == '6' || digit == '7' || digit == '8' || digit == '9'){
		return digit - '0';
	}
	else{
		throw std::invalid_argument("Invalid Argument");
	}
    return 0;
}

char decimal_to_digit(unsigned int decimal) {
    if(decimal == 0 || decimal == 1 || decimal == 2 || decimal == 3 ||  decimal == 4 || decimal == 5 || decimal == 6 || decimal == 7 || decimal == 8 || decimal == 9){
		return decimal + '0';
	}
	else{
		throw std::invalid_argument("Invalid Argument");
	}
    return '\0';
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
	bool negativeSign = false;
	if(num == "0" || num.find("0") == string::npos || num.size() == 0){
		return num;
	}
	if(num.find("1") == string::npos && num.find("2") == string::npos && num.find("3") == string::npos && num.find("4") == string::npos && num.find("5") == string::npos && num.find("6") == string::npos && num.find("7") == string::npos && num.find("8") == string::npos && num.find("9") == string::npos){
		return "0";
	}
	if(num.at(0) == '-'){
		negativeSign = true;
	}
	if(negativeSign){
		while(num.at(1) == '0'){
			num = "-" + num.substr(2,num.size()-1);
	}
	}
	else{
		while(num.at(0) == '0'){
			num = num.substr(1,num.size()-1);
		}
	}
	//make sure you implement a solution for a negative sign followed by a zero (trim the zero but keep the sign)
	//use string at to look at the first index of the string (if 0, delete it) (if a non-zero number, leave it alone) (if negative sign then 0, get rid of 0 and keep sign
	return num;	
}

string add(string lhs, string rhs) {
    // TODO(student): implement
	lhs = trim_leading_zeros(lhs);
	rhs = trim_leading_zeros(rhs);
	int placeValue = 0;
	int carry = 0;
	int result = 0;
	int leftNum = 0;
	int rightNum = 0;
	bool negativeSign = false;
	string answer = "";
	if(lhs.at(0) == '-' && rhs.at(0) == '-'){
		negativeSign = true;
	}
	if(negativeSign){
		lhs.erase(0,1);
		rhs.erase(0,1);
	}
	if(lhs.size() > rhs.size()){
		while(rhs.size() != lhs.size()){
			rhs = '0' + rhs;
		}
	}
	else if(lhs.size() < rhs.size()){
		while(lhs.size() != rhs.size()){
			lhs = '0' + lhs;
		}
	}
	placeValue = lhs.size()-1;
	while(placeValue >= 0){
		leftNum = digit_to_decimal(lhs.at(placeValue));
		rightNum = digit_to_decimal(rhs.at(placeValue));
		result = leftNum + rightNum + carry;
		carry = 0;
		if(result > 9){
			carry = result/10;
		}
		result = result % 10;
		answer.insert(0,std::to_string(result));
		placeValue--;
	}
	if(carry != 0){
		answer.insert(0,std::to_string(carry));
	}
	if(negativeSign){
		return "-" + answer;
	}
	return answer;
}

string multiply(string lhs, string rhs) {
	lhs = trim_leading_zeros(lhs);
	rhs = trim_leading_zeros(rhs);
	int leftPlaceValue = lhs.size()-1;
	int rightPlaceValue = rhs.size()-1;
	int carry = 0;
	int result = 0;
	int leftNum = 0;
	int rightNum = 0;
	int counter = 0;
	bool leftNegative = false;
	bool rightNegative = false;
	bool bothNegative = false;
	string answer = "";
	string answer1 = "";
	string answer2 = "";
	string answer3 = "0";
	string temp = "";
	if(lhs.at(0) == '-' && rhs.at(0) == '-'){
		bothNegative = true;
	}
	if(lhs.at(0) == '-' && rhs.at(0) != '-'){
		leftNegative = true;
	}
	if(lhs.at(0) != '-' && rhs.at(0) == '-'){
		rightNegative = true;
	}
	if(bothNegative){
		lhs.erase(0,1);
		leftPlaceValue = lhs.size()-1;
		rhs.erase(0,1);
		rightPlaceValue = rhs.size()-1;
	}
	if(leftNegative){
		lhs.erase(0,1);
		leftPlaceValue = lhs.size()-1;
	}
	if(rightNegative){
		rhs.erase(0,1);
		rightPlaceValue = rhs.size()-1;
	}
	if(lhs.size() < rhs.size()){
		temp = lhs;
		lhs = rhs;
		rhs = temp;
		leftPlaceValue = lhs.size()-1;
		rightPlaceValue = rhs.size()-1;
		lhs = trim_leading_zeros(lhs);
		rhs = trim_leading_zeros(rhs);
	}
	while(leftPlaceValue >= 0){
		leftNum = digit_to_decimal(lhs.at(leftPlaceValue));
		rightNum = digit_to_decimal(rhs.at(rightPlaceValue));
		result = (leftNum * rightNum) + carry;
		carry = 0;
		if(result > 9){
			carry = result / 10;
		}
		result = result % 10;
		answer1.insert(0,std::to_string(result));
		leftPlaceValue--;
	}
	if(carry != 0){
		answer1.insert(0,std::to_string(carry));
	}
	leftPlaceValue = lhs.size()-1;
	rightPlaceValue--;
	carry = 0;
	while(rightPlaceValue >= 0 && leftPlaceValue >= 0){
		leftNum = digit_to_decimal(lhs.at(leftPlaceValue));
		rightNum = digit_to_decimal(rhs.at(rightPlaceValue));
		result = (leftNum * rightNum) + carry;
		carry = 0;
		if(result > 9){
			carry = result / 10;
		}
		result = result % 10;
		answer2.insert(0,std::to_string(result));
		if(leftPlaceValue == 0){
			counter++;
			rightPlaceValue--;
			leftPlaceValue = lhs.size()-1;
			for(int i = 0; i < counter; i++){
				answer2.append("0");
			}
			if(carry != 0){
				answer2.insert(0,std::to_string(carry));
			}
			carry = 0;
			answer3 = add(answer3, answer2);
			answer2 = "";
		}
		else{
			leftPlaceValue--;
		}
	}
	answer = add(answer1,answer3);
	if(leftNegative && !rightNegative){
		return "-" + answer;
	}
	if(rightNegative && !leftNegative){
		return "-" + answer;
	}
	if(bothNegative){
		return answer;
	}
	return answer;
}

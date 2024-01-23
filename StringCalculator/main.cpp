#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"
#include <sstream>

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
	string input = "";
	string ans = "";
	string num1 = "";
	string num2 = "";
	while(input != "quit" && input != "q"){
		cout << ">> ";
		getline(cin,input);
		if(input.find("+") != string::npos){
			num1 = input.substr(0,input.find("+")-1);			
			num2 = input.substr(input.find("+")+2,input.find("\n"));			
			ans = add(num1,num2);
		}
		else if(input.find("*") != string::npos){
			num1 = input.substr(0,input.find("*")-1);
			num2 = input.substr(input.find("*")+2,input.find("\n"));
			ans = multiply(num1,num2);
		}
		if(input !=  "quit" && input != "q"){
			cout << endl << "ans =" << endl << endl << "    " << ans << endl << endl;
		}
	}
	cout << endl << "farvel!" << endl << endl;
    
    // TODO(student): implement the UI
}


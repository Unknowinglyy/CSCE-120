#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
	string sentence;
	string details;
	unsigned long WordIndex = 0;
	unsigned long DetailsIndex = 0;
	cout << "Please enter obfuscated sentence: ";
	cin >> sentence;
	cout << "Please enter deobfuscation details: ";
	cin >> details;
	cout << "Deobfuscated sentence: ";
	while(WordIndex < sentence.size()){
		if(DetailsIndex != details.size()-1){
			cout << sentence.substr(WordIndex, details.at(DetailsIndex) - '0') << " ";
		}
		else{
			cout << sentence.substr(WordIndex, details.at(DetailsIndex) - '0');
		}
		WordIndex += details.at(DetailsIndex) - '0';
		DetailsIndex++;
	}

    return 0;
}

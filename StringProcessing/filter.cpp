#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
    string userInp;
    cout << "Please enter the sentence: ";
    getline(cin, userInp);

    string filterWord;
    cout << "Please enter the filter word: ";
    cin >> filterWord;
    
    int item = userInp.find(filterWord);
    int filterSize = filterWord.size();
    string filter;
    for (int i = 0; i < filterSize; i++){
        filter += "#";
    }

    while (item >= 0){
        userInp.replace(item, filterSize, filter);
        item = userInp.find(filterWord);

    }
    cout << "Filtered sentence: " << userInp;

    return 0;
}

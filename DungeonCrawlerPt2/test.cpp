#include <iostream>
#include <fstream>
#include <string>
#include "helper.h"
#include "logic.h"

using std::cin, std::cout, std::endl, std::string, std::ifstream;
int main(){
    char** map = nullptr;
    int row = 1;
    int col = 5;
    Player player;
    map = loadLevel("test1.txt",row,col,player);
    if(map == nullptr){
        cout << "map is a nullptr." << endl;
        cout << "Original Row Count: " << row << endl;
        cout << "Original Col Count: " << col << endl;
        map = resizeMap(map,row,col);
        cout << "Row Count: " << row << endl;
        cout << "Col Count: " << col << endl;
    }
    else{
        cout << "Original Map: " << endl;
        cout << "Original Row Count: " << row << endl;
        cout << "Original Col Count: " << col << endl;
        outputMap(map,row,col);
        map = resizeMap(map,row,col);
        outputMap(map,row,col);
        cout << "Row Count: " << row << endl;
        cout << "Col Count: " << col << endl;
    }
    deleteMap(map,row);
    return 0;
}

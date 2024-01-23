#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>
#include <stdexcept>
#include "MyString.h"
#include "Rover.h"

//default constructor
MyString::MyString(): size_(0), capacity_(1), word(new char[1]){
    *word = '\0';
}

//copy constructor
MyString::MyString(const MyString& str)
: size_(str.size_), capacity_(str.capacity_), word(new char[str.size_+1]){
    for(unsigned int i = 0; str.word[i] != '\0'; i++){
        word[i] = str.word[i];
    }
    word[size_] = '\0';
}
//copying from a c-string
MyString::MyString(const char* s): size_(0), capacity_(0), word(nullptr){
    unsigned int count = 0;
    for(unsigned int i = 0; s[i] != '\0'; i++){
        count++;
    }
    size_ = count;
    word = new char[size_ + 1];
    capacity_ = size_ + 1;
    for(unsigned int i = 0; s[i] != '\0'; i++){
        word[i] = s[i];
    }
    word[size_] = '\0';
}

MyString::~MyString(){
    delete[] word;
}
//resizing function
//make a new instance of MyString
//update the size
void MyString::resize(size_t n){
    char* newWord = new char[n+1];
    newWord[n] = '\0';
    //copying word contents to newWord
    for(unsigned int i = 0; word[i] != '\0'; i++){
        newWord[i] = word[i];
    }
    //populating the rest of newWord with periods
    for(unsigned int i = size_; newWord[i] != '\0'; i++){
        newWord[i] = ' ';
    }
    delete[] word;
    word = new char[n+1];
    word[n] = '\0';
    //copying back the contents of newWord to word
    for(unsigned int i = 0; i < n; i++){
        word[i] = newWord[i];
    }
    delete[] newWord;
    size_ = n;
    capacity_ = n+1;
}
//getter for the content in the word
const char* MyString::data() const{
    return word;
}
//
const char& MyString::front() const{
    return word[0];
}

const char& MyString::at (size_t pos) const{
    if(size_ == 0){
        throw std::out_of_range("at function can't be called on an empty string");
    }
    if(pos >= size_){
        throw std::out_of_range("Position in at function is greater than size");
    }
    return word[pos];
}

void MyString::clear(){
    size_ = 0;
    capacity_ = 0;
    *word = '\0';
}

size_t MyString::find(const MyString& str, size_t pos) const{
    const char* target = str.word;
     int startIndex = -1;
    //if the target is the empty string
    if(str.size_ == 0){
        return -1;
    }
    //looking for where the first char of the target is found in the word
    for(unsigned int i = pos; word[i] != '\0'; i++){
        if(word[i] == target[0]){
            startIndex = i;
            break;
        }
    }
    //if no start index was assigned, return that nothing was found
    if(startIndex == -1){
        return -1;
    }
    //if a start index was assigned and the target is only one char long, then return the start index
    if(str.size() == 1){
        return startIndex;
    }
    //starting from the second index of the target, make sure all of target can be matched to word
    for(unsigned int j = 1; word[startIndex+j] == target[j] && j < str.size_; j++){
        if(j == str.size_-1){
            return startIndex;
        }
    }
    return -1;
}

MyString& MyString::operator=(const MyString& str){
    if(this != &str){
        delete[] word;
        word = new char[str.size_+1];
        size_ = str.size_;
        capacity_ = size_+1;
        for(unsigned int i = 0; str.data()[i] != '\0'; i++){
            word[i] = str.data()[i];
        }
        word[size_] = '\0';
    }
    return *this;
}

MyString& MyString::operator+=(const MyString& str){
    int newCapacity = size_ + str.size();
    const char* rightWord = str.data();
    char* newWord = new char[newCapacity+1];

    //copying left word
    for(unsigned int i = 0; word[i] != '\0'; i++){
        newWord[i] = word[i];
    }
    //copying right word
    for(unsigned int i = 0; rightWord[i] != '\0'; i++){
        newWord[i+size_] = rightWord[i];
    }

    newWord[newCapacity] = '\0';
    delete[] word;
    word = newWord;
    size_ = newCapacity;
    capacity_ = newCapacity+1;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& str){
    os << str.data();
    return os;
}

bool operator==(const MyString& lhs, const MyString& rhs){
    if(lhs.size() == rhs.size()){
        for(unsigned int i = 0; i < lhs.size(); i++){
            if(lhs.data()[i] != rhs.data()[i]){
                return false;
            }
            else{
                continue;
            }
        }
    }
    else{
        return false;
    }
    return true;
}

MyString operator+(const MyString& lhs, const MyString& rhs){
    int newCapacity = lhs.size() + rhs.size();
    const char* leftWord = lhs.data();
    const char* rightWord = rhs.data();
    char* newWord = new char[newCapacity+1];
    //copying left word
    for(unsigned int i = 0; leftWord[i] != '\0'; i++){
        newWord[i] = leftWord[i];
    }
    //copying right word
    for(unsigned int i = 0; rightWord[i] != '\0'; i++){
        newWord[i+lhs.size()] = rightWord[i];
    }
    newWord[newCapacity] = '\0';
    MyString combined(newWord);
    delete[] newWord;
    return combined;
}

bool MyString::empty() const{
    if(size_ == 0){
        return true;
    }
    else{
        return false;
    }
}
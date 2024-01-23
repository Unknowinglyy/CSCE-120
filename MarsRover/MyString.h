#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>

class MyString{
    private:
        size_t size_;
        size_t capacity_;
        char* word;
    public:
        //default constructor
        MyString();

        //copy constructor
        MyString(const MyString& str);

        //constructor that is copying from a c-string
        MyString(const char* s);

        ~MyString();

        void resize(size_t n);

        size_t size() const {return size_;}//DONE

        size_t length() const {return size_;}//DONE

        size_t capacity() const {return capacity_;}//DONE

        //data getter (actual word)
        const char* data()const;

        bool empty() const;//DONE
        
        //returns a reference to the first character of the word
        const char& front() const;

        //returns a reference to the character at position pos in word
        const char& at (size_t pos) const;

        void clear();

        //searches for the first occurence of str at position pos
        size_t find (const MyString& str, size_t pos = 0) const;

        //replaces the contents of the lhs to the rhs
        MyString& operator=(const MyString& str);

        //appendings the contents of str to the lhs
        MyString& operator+= (const MyString& str);



};
//inserts the word into the outstream
std::ostream& operator<<(std::ostream& os, const MyString& str);

//checks for equality
bool operator==(const MyString& lhs, const MyString& rhs);

MyString operator+(const MyString& lhs, const MyString& rhs);

#endif
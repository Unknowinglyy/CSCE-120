#include <iostream>
#include <string>
using std::cin,std::cout,std::endl,std::string;

int main(){
  cout<<"Please enter your text input: ";
  string password;
  cin>>password;
  cout<<"input: "<<password<<endl;
  
  string new_password="";
  for(unsigned long i=0;i<password.length();i++){
    char c=password.at(i);
    if(c=='a'){
      new_password+='@';
    }else if(c=='e'){
      new_password+='3';
    }else if(c=='i'){
      new_password+='!';
    }else if(c=='o'){
      new_password+='0';
    }else if(c=='u'){
      new_password+='^';
    }else{
      new_password+=c;
    }
  }
  for(unsigned long i=0;i<password.length();i++){
    new_password+=new_password.at(password.length()-i-1);
  }
  cout<<"output: "<<new_password<<endl;

  return 0;
}

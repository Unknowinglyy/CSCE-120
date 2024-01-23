/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Network.h"

using std::cout, std::cin, std::endl;
using std::string, std::vector;

void printMenu() {
  cout << "Welcome to CPPeers" << endl;
  cout << "The options are: " << endl;
  cout << "1. load data file and add information" << endl;
  cout << "2. show posts by user" << endl;
  cout << "3. show posts with hashtag" << endl;
  cout << "4. show most popular hashtag" << endl;
  cout << "9. quit" << endl;
  cout << "--------> Enter your option: ";
}

void processLoad(Network& cppeers) {
  string fileName = "";
  cout << "Enter filename: ";
  cin >> fileName;
  cppeers.loadFromFile(fileName);
}

void processPostsByUser(Network& cppeers) {
  string userName = "";
  cout << "Enter username: ";
  cin >> userName;
  vector<Post*> usersPosts = cppeers.getPostsByUser(userName);
  for(unsigned int i = 0; i < usersPosts.size(); i++){
    cout << usersPosts.at(i)->getPostText() << endl;
  }
}

void processPostsWithHashtags(Network& cppeers) {
  // TODO(student): implement
  string tagName = "";
  cout << "Enter tagname: ";
  cin >> tagName;
  vector<Post*> postsByTag = cppeers.getPostsWithTag(tagName);
  for(unsigned int i = 0; i < postsByTag.size(); i++){
    cout << postsByTag.at(i)->getPostText() << endl;
  }
}

void processMostPopularHashtag(Network& cppeers) {
  // TODO(student): implement
  vector<string> mostPopTag = cppeers.getMostPopularHashtag();
  for(unsigned int i = 0; i < mostPopTag.size(); i++){
    cout << mostPopTag.at(i) << endl;
  }
}

int main() {

  try {
    Network cppeers;

    int choice = 0;

    // present menu
    do {
      printMenu();
      cin >> choice;
      switch(choice) {
        case 1: {
          processLoad(cppeers);
          break;
        }
        case 2: {
          processPostsByUser(cppeers);
          break;
        }
        case 3: {
          processPostsWithHashtags(cppeers);
          break;
        }
        case 4: {
          processMostPopularHashtag(cppeers);
          break;
        }
      }
    } while (choice != 9);
  } catch (std::exception& exc) {
    std::cout << exc.what() << endl;
  }

  return 0;
}

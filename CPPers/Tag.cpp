/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "Tag.h"

using std::string;
using std::vector;

Tag::Tag(string tagName): tagName(tagName), tagPosts({}){
  if(tagName.empty()){
    throw std::invalid_argument("Invalid constuctor for the Tag class");
  }
  for(size_t i = 0; i < tagName.length(); i++){
    if(isupper(tagName.at(i))){
      throw std::invalid_argument("Invalid constuctor for the Tag class");
    }
  }
  char puntuations [4] = {'!', ',', '.', '?'};
  if(tagName.at(tagName.length()-1) == puntuations[0] || tagName.at(tagName.length()-1) == puntuations[1] || tagName.at(tagName.length()-1) == puntuations[2] ||tagName.at(tagName.length()-1) == puntuations[3]){
    throw std::invalid_argument("Invalid constuctor for the Tag class");
  }
  if(tagName.length() < 2 || tagName.at(0) != '#' || !(isalpha(tagName.at(1)))){
    throw std::invalid_argument("Invalid constuctor for the Tag class");
  }
}

string Tag::getTagName() {
  // TODO(student): implement getter
  return tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
  return tagPosts;
}

void Tag::addTagPost(Post* post) {
  // TODO(student): add post to tag posts
  if(post == nullptr){
    throw std::invalid_argument("Couldn't add a tagged post because post is nullptr");
  }
  tagPosts.push_back(post);
}

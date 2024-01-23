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
#include <sstream>
#include <stdexcept>
#include "Post.h"

using std::string;
using std::vector;

Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
  // TODO(student): extracts candidate tags based on occurrences of # in the post
  std::vector<string> tags;
  std::stringstream input;
  string temp = "";
  string posts = getPostText();
  char puntuations [4] = {'!', ',', '.', '?'};

  input.str(posts);
  //getting a candiate tag after each space of new line
  while(input >> temp){
    //checking for hashtag
    if(temp.at(0) == '#'){
      for(unsigned int i = 1; i < temp.length(); i++){
        //converting possible tag to all lower case
        temp.at(i) = tolower(temp.at(i));
      }
      //checking for punctuations at the end of the tag and removing if so
      while(temp.at(temp.length()-1) == puntuations[0] || temp.at(temp.length()-1) == puntuations[1] ||temp.at(temp.length()-1) == puntuations[2] ||temp.at(temp.length()-1) == puntuations[3]){
        temp.pop_back();
      }
      //tag is finally inputted into the vector
      tags.push_back(temp);
    }
  }
  return tags;
}

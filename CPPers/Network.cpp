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
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "Network.h"

using std::string;
using std::vector;

Network::Network(): users({}), posts({}), tags({}){
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
  std::ifstream input(fileName);

  if(!input.is_open()){
    throw std::invalid_argument("Could not load from file");
  }
  try {
    string line = "";
    while(getline(input,line)){
    std::stringstream str;
    string type;
    string userName;
    unsigned int postID;
    string postText;
    string temp;
      str << line;
      str >> type;
      if(type != "User" && type != "Post"){
        throw std::invalid_argument("Could not load from file because of invalid post type");
      }
      if(type == "User"){
        str >> userName;
        addUser(userName);
      }
      if(type == "Post"){
        str >> postID;
        str >> userName;
        getline(str,temp);
        postText = temp.substr(1,temp.length()-1);
        addPost(postID,userName,postText);
      }
    }
  }
  catch(std::exception& exc){
    std::cout << exc.what() << std::endl;
    throw std::runtime_error("File's content does not match specified format");
  }
}

void Network::addUser(string userName) {
  // TODO(student): create user and add it to network
  string temp = userName;
  for(size_t i = 0; i < temp.length(); i++){
    temp.at(i) = tolower(temp.at(i));
  }
  for(unsigned int i = 0; i < users.size(); i++){
      if(users.at(i)->getUserName() == temp){
        throw std::invalid_argument("Can't add user to user vector because username already exists");
      }
  }
  User* newUser = new User(userName);
  users.push_back(newUser);
  std::cout << "Added User " << userName << std::endl;
}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
  bool isUserName = false;
  unsigned int userIndex = 0;
  vector<string> tagsVector;
  bool sameTag = false;

  for(unsigned int i = 0; i < posts.size(); i++){
    if(posts.at(i)->getPostId() == postId){
      throw std::invalid_argument("Can't add post to post vector");
    }
  }
  for(unsigned int i = 0; i < users.size(); i++){
    if(users.at(i)->getUserName() == userName){
      isUserName = true;
      userIndex = i;
      break;
    }
  }
  if(!(isUserName)){
    throw std::invalid_argument("Can't add post to post vector");
  }
  //creating new post
  Post* newPost = new Post(postId,userName,postText);
  //adding new post to network data member
  posts.push_back(newPost);
  //adding the new post to the user that was given in the constructor
  users.at(userIndex)->addUserPost(newPost);
  //creating a vector of tags from the new post and findTags function
  tagsVector = newPost->findTags();

  for(unsigned int i = 0; i < tagsVector.size(); i++){
    sameTag = false;
    for(unsigned int j = 0; j < tags.size(); j++){
      if(tagsVector[i] == tags[j]->getTagName()){
        sameTag = true;
        tags[j]->addTagPost(newPost);
      }
    }
    try{
      if(!sameTag){
        Tag* newTag = new Tag(tagsVector.at(i));
        //adding new tag to the network data member
        tags.push_back(newTag);
        //since this new tag is at the last element in the tags vector, use that index to add the new post to the tag that was added
        tags.at(tags.size()-1)->addTagPost(newPost);
      }
    }
    catch (...){
    }
  }
  std::cout << "Added Post " << postId << " by " << userName << std::endl;
}

vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user
  bool foundUser = false;
  int userIndex = 0;
  if(userName.empty()){
    throw std::invalid_argument("Can't get the posts of specified user");
  }
  for(unsigned int i = 0; i < users.size(); i++){
    if(users.at(i)->getUserName() == userName){
      foundUser = true;
      userIndex = i;
      break;
    }
  }
  if(!foundUser){
    throw std::invalid_argument("Can't get the posts of specified user");
  }
  vector<Post*> postsVector;
  postsVector = users.at(userIndex)->getUserPosts();
  return postsVector;
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
  bool foundTag = false;
  int tagIndex = 0;
  if(tagName.empty()){
    throw std::invalid_argument("Can't get posts with specified tag");
  }
  //checking if the tag exists
  for(unsigned int i = 0; i < tags.size(); i++){
    if(tags.at(i)->getTagName() == tagName){
      foundTag = true;
      tagIndex = i;
      break;
    }
  }
  if(!foundTag){
    throw std::invalid_argument("Can't get posts with specified tag");
  }
  //initialzing a vector with posts and giving it the value of a vector of posts with a specified tag
  vector<Post*> postsVector;
  postsVector = tags.at(tagIndex)->getTagPosts();
  return postsVector;
}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
  vector<string> mostPopular;
  long unsigned int tagNumber = 0;

  for(unsigned int i = 0; i < tags.size(); i++){
    //finding the number of posts that use a certain tag
    if(tags.at(i)->getTagPosts().size() > tagNumber){
      //if this number of posts is greater than the tagNumber, then tagNumber is updated
      tagNumber = tags.at(i)->getTagPosts().size();
    }
  }
  for(unsigned int i = 0; i < tags.size(); i++){
    //for any posts that equal the tag number (takes care of ties), each tag name is appended to the mostPopular vector
    if(tags.at(i)->getTagPosts().size() == tagNumber){
      mostPopular.push_back(tags.at(i)->getTagName());
    }
  }
  return mostPopular;
}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}

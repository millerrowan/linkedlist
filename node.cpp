#include <iostream>
#include "node.h"
#include <cstring>
#include <vector>
#include "student.h"

using namespace std;

Node::Node(Student* myStudent) {
  student = myStudent; 
  next = NULL;
  cout << "constucting" << endl;
}

Node::~Node() {
  delete student;
  next = NULL;
  cout << "destructing" << endl; 
}

Node* Node::getNext() {
  cout << "getting next" << endl; 
  return next;
}

void Node::setNext(Node* nextNode) {
  next = nextNode;
  cout << "setting next" << endl; 
}

Student* Node::getStudent() {
  cout << "getting student" << endl; 
  return student; 
}



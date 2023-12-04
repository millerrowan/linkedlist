#include <iostream>
#include <vector>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

//main

int main() {
  Student* myStudent = new Student();
  Node* myNode = new Node(myStudent);
  Node* nextNode = new Node(myStudent); 
  myNode->setNext(nextNode);
  myNode->getNext();
  myNode->getStudent();
  delete myNode; 
  
  


}

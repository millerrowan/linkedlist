#include <iostream>
#include <vector>
#include <cstring>
#include "node.h"
#include "student.h"

/* Linked List creates a student list but uses linked lists instead of vectors
   Author: Rowan Miller
   12/4/23
 */

using namespace std;


int main() {
  Student* myStudent = new Student();
  Node* myNode = new Node(myStudent);
  Node* nextNode = new Node(myStudent); 
  myNode->setNext(nextNode);
  myNode->getNext();
  myNode->getStudent();
  delete myNode; 
  
  


}

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

  Node* head = NULL;

  char input[10]; 
  
  cout << "Enter 'ADD', 'PRINT', or 'DELETE" << endl;

  cin >> input;

  if(strcmp(input, "ADD")==0) {
    Student* s = new Student();
    add();
  }

  if(strcmp(input, "PRINT")==0) {
    print():
  }

  if(strcmp(input, "DELETE")==0) {
    Delete();
  }
}

void add(Node* &head, Node* prev, Student* s) {
  //use recursion
  Node* current = head;
  if(current == NULL) {
    current = new Node(s); 
  }
  else if(current->getNext() == NULL) {
    if(s->getID() < current->getStudent()->getID()) {
      Node* temp = new Node(s);
      prev->setNext(temp);
      temp->setNext(current);
    }
    else {
      Node* temp = new Node(s); 
      current->setNext(temp); 
    }
  }
  else{
    Node* prev = head;
    Node* current = head->getNext(); 
    while(current->getNext() != NULL) {
      current = current->getNext(); 
    }
    current->setNext(new Node());
    current->getNext()->getStudent(//pass in variables from node.cpp); 
  }
  
}

void print() {
  //use recursion

}

void Delete() {
  //make sure to confirm the deletion

}

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

void add(Node* &head, Node* prev, Student* s, Node* nextNode);
void print();
void Delete();

int main() {
  
  bool stillPlaying = true; 
  
  Node* head = NULL;
  Node* prev = head;

  char input[10]; 

  while(stillPlaying == true) {
    cout << "Enter 'ADD', 'PRINT', 'DELETE', or 'QUIT'" << endl;
    
    cin >> input;
    
    if(strcmp(input, "ADD")==0) {
      Student* s = new Student();
      Node* nextNode = new Node(s); 
      add(head, prev, s, nextNode);
    }
    
    if(strcmp(input, "PRINT")==0) {
      print();
    }
    
    if(strcmp(input, "DELETE")==0) {
      Delete();
    }
    
    if(strcmp(input, "QUIT")==0) {
      stillPlaying = false; 
    }
  }
}

void add(Node* &head, Node* prev, Student* s, Node* nextNode) {
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
    current->setNext(nextNode);//will have to change this variable name
    current->getNext()->getStudent();//pass in variables from node.cpp 
  }
}

				   
void print() {
  //use recursion
  

}

void Delete() {
  //make sure to confirm the deletion

}


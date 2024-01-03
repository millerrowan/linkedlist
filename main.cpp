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
void print(Node* head);
void Delete();
void average();

int main() {
  
  bool stillPlaying = true; 
  
  Node* head = NULL;
  Node* prev = head;

  char input[10]; 

  while(stillPlaying == true) {
    cout << "Enter 'ADD', 'PRINT', 'DELETE', 'AVERAGE', or 'QUIT'" << endl;
    
    cin >> input;
    
    if(strcmp(input, "ADD")==0) {
      Student* s = new Student();
      Node* nextNode = new Node(s); 
      add(head, head, s, head);
    }
    
    if(strcmp(input, "PRINT")==0) {
      print(head);
    }
    
    if(strcmp(input, "DELETE")==0) {
      Delete();
    }

    if(strcmp(input, "AVERAGE")==0) {
      average();
    }
    
    if(strcmp(input, "QUIT")==0) {
      stillPlaying = false; 
    }
  }
}

void add(Node* &head, Node* prev, Student* s, Node* current) {
  //use recursion
  if(head == NULL) {
    head = new Node(s);
    head->setNext(NULL); 
  }
  //if student id is at the beginning of list
  else if(s->getID() < head->getStudent()->getID()) {
    Node* temp = new Node(s);
    temp->setNext(head);
    head = temp; 
  }
  //if student id is at the end of list
  else if(current->getNext() == NULL) {
    if(s->getID() < current->getStudent()->getID()) {
      Node* temp = new Node(s);
      prev->setNext(temp);
      temp->setNext(current);
    }
    else {
      Node* temp = new Node(s); 
      current->setNext(temp);
      temp->setNext(NULL); 
    }
  }
  //if student id is in the middle of list
  else{
    if(s->getID() < current->getStudent()->getID()) {
      Node* temp = new Node(s);
      prev->setNext(temp);
      temp->setNext(current);
    }
    else{  
      add(head, current, s, current->getNext()); 
    }
  }
}

				   
void print(Node* head) {
  //use recursion
  Node* current = head;
  if(current != NULL) {
    cout << current->getStudent()->getFN() << " " << current->getStudent()->getLN() << ", " << current->getStudent()->getID();
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2); 
    cout << ", " << current->getStudent()->getGPA() << endl;
    print(current->getNext()); 
  }
}

void Delete(Node* head) {
  //make sure to confirm the deletion
  int stored; 
  cout << "Type in the student id of the student you want to delete" << endl; 
  cin >> stored;
  Node* current = head;
  if (current->getStudent()->getID() == stored) {
    delete current;
  }
  else{
    current =  
    Delete(head);
  }
}

void average() {


}

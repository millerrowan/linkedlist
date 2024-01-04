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
void Delete(Node* head, Node* prev);
void average(Node* head);

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
      Delete(head, prev);
    }

    if(strcmp(input, "AVERAGE")==0) {
      average(head);
    }
    
    if(strcmp(input, "QUIT")==0) {
      stillPlaying = false; 
    }
  }
}

//adds a student to the list
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

//prints out all students in list	   
void print(Node* head) {
  //use recursion
  Node* current = head;
  //if current exists
  if(current != NULL) {
    //prints out student
    cout << current->getStudent()->getFN() << " " << current->getStudent()->getLN() << ", " << current->getStudent()->getID();
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2); 
    cout << ", " << current->getStudent()->getGPA() << endl;
    print(current->getNext()); 
  }
}

//deletes a student from the list
void Delete(Node* head, Node* prev) {
  //make sure to confirm the deletion
  int stored; 
  cout << "Type in the student id of the student you want to delete" << endl; 
  cin >> stored;
  Node* current = head;
  //if the current value exists
  if (current != NULL) {
    //if the user id matches id of student
    if (current->getStudent()->getID() == stored) {
      delete current;
      prev->setNext(current->getNext());
      current = NULL;
    }
    //if user id doesn't match id of student
    else{
      //sets current to the next node
      current = current->getNext();
      Delete(head, prev);
    }
  }
  //if current equals NULL
  else {
    cout << "there is nothing to delete" << endl; 
  }
}

void average(Node* head) {
  int sum = 0;
  int studentCount = 0; 
  Node* current = head;
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  //if current exists
  if(current != NULL) {
    sum = sum + current->getStudent()->getGPA();
    studentCount++;
    current = current->getNext();
    average(head); 
  }
  //if current does not exist
  else {
    float average = sum/(float) studentCount; 
    cout << "Average: " << average << endl; 
  }
}

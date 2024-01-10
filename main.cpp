#include <iostream>
#include <vector>
#include <cstring>
#include "node.h"
#include "student.h"

/* Linked List creates a student list but uses linked lists instead of vectors
   Author: Rowan Miller
   1/9/24
 */

using namespace std;

void add(Node* &head, Node* prev, Student* s, Node* newnext);
void print(Node* head);
void Delete(Node* &head, Node* prev, Node* newnext, int stored);
void average(Node* current, int studentCount, float total);

int main() {
  
  bool stillPlaying = true; 
  
  Node* head = NULL;

  char input[10];


  while(stillPlaying == true) {
    cout << "Enter 'ADD', 'PRINT', 'DELETE', 'AVERAGE', or 'QUIT'" << endl;
    
    cin >> input;
    //if user input equals ADD
    if(strcmp(input, "ADD")==0) {
      Student* s = new Student();
      Node* nextNode = new Node(s);
      add(head, head, s, head);
    }
    //if user input equals PRINT
    if(strcmp(input, "PRINT")==0) {
      print(head);
    }

    //if user input equals DELETE
    if(strcmp(input, "DELETE")==0) {
      int stored;
      cout << "Type in the student id of the student you want to delete" << endl;
      cin >> stored;
      Delete(head, head, head, stored);
    }
    //if user input equals AVERAGE
    if(strcmp(input, "AVERAGE")==0) {
      average(head, 0, 0);
    }

    //if user input equals QUIT
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
  //if current exists
  Node* current = head; 
  if(current != NULL) {
    //prints out student
    cout << current->getStudent()->getFN() << " " << current->getStudent()->getLN() << ", " << current->getStudent()->getID();
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2); 
    cout << ", " << current->getStudent()->getGPA() << endl;
    print(current->getNext()); 
  }
  else if (current == NULL) {
    cout << "there is nothing to print" << endl;
  }
  //add other option
}

//deletes a student from the list
void Delete(Node* &head, Node* prev, Node* current, int stored) {
  //if stored id matches head
  if (head->getStudent()->getID() == stored) {
    //if head doesn't equal NULL
    if(head != NULL) {
      cout << "head doesn't equal NULL" << endl; 
      //if head exists
      if (head->getNext() != NULL) {
	cout << "head has a next" << endl;
	Node* temp = head->getNext();
	delete head;
	head = temp;
     }
      else {
	cout << "head doesn't have a next" << endl;
	delete head;
	head = NULL;
      }
    }
    else {
      cout << "there is nothing to delete head" << endl;
    }
  }
    //if current equals the id typed in
  else if (current->getStudent()->getID() == stored) {
    //if current does not equal NULL
    if (current != NULL) {
      cout << "current doesn't equal NULL" << endl;
      //cout << "current equals stored" << endl;
	prev->setNext(current->getNext());
	delete current;
	current = NULL;
      }
      //if current does equal NULL
      else{
	cout << "there is nothing to delete" << endl;
      }
  }
    //if head or current doesn't equal the stored id
    else {
      prev = current;
      current = current->getNext();
      Delete(head, prev, current, stored); 
    }
}

//averages the gpas of all students in the list
void average(Node* current, int studentCount, float total) {
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  //if current exists
  if(current != NULL) {
    total = total + current->getStudent()->getGPA(); 
    average(current->getNext(), studentCount+1, total); 
  }
  //if current does not exist
  else {
    cout << total << endl;
    cout << studentCount << endl;
    float average = total/(float) studentCount; 
    cout << "Average: " << average << endl; 
  }
}

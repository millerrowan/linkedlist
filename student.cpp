#include <iostream>
#include "student.h"
#include <cstring>
#include <vector>

using namespace std;

Student::Student() {
  cout << "student created" << endl;
  cout << "Enter the first name" << endl;
  firstName = new char[20];
  cin >> firstName;
  cout << "Enter the last name" << endl;
  lastName = new char[20];
  cin >> lastName;
  cout << "Enter the student id" << endl;
  cin >> id;
  cout << "Enter the gpa" << endl;
  cin >> gpa; 
}

char* Student::getFN() {
  return firstName;
}

char* Student::getLN() {
  return lastName;
}

int Student::getID() {
  return id;
}

float Student::getGPA() {
  return gpa; 
}

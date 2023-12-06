#include <iostream>
#include "student.h"
#include <cstring>
#include <vector>

using namespace std;

Student::Student() {
  cout << "student created" << end;
  cout << "Enter the first name" << endl;
    cin >> firstName;
  cout << "Enter the last name" << endl;
  cin >> lastName;
  cout << "Enter the student id" << endl;
  cin >> id;
  cout << "Enter the gpa" << endl;
  cin >> gpa; 
}



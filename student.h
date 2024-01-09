#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Student {
 public:
  Student();
  ~Student();
  char* getFN();
  char* getLN();
  int getID();
  float getGPA();
 protected:
  char* firstName;
  char* lastName;
  int id;
  float gpa;
};
#endif

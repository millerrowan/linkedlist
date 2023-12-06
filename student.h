#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Student {
 public:
  Student();  

 protected:
  char firstName[20];
  char lastName[20];
  int id;
  float gpa; 
};
#endif

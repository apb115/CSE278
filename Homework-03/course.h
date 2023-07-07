// Copyright 2022 by Andrew Boothe
// Homework-03
// April 21, 2022

#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <algorithm>

class Course {
 // define operator<< as a friend function for Course
 friend std::ostream& operator<<(std::ostream& out , Course c);
 public:
  Course(const std::string& acourseName, const std::string& asection, int acapacity);
  ~Course();
  Course(Course original);  // copy constructor, const?
  Course& operator=(Course& right);  // copy assignment operator, const?
  void setCourseName(std::string name);
  std::string getCourseName() const;
  void setSection(std::string section);
  std::string getSection() const;
  void addStudent(const std::string& name);
  void dropStudent(const std::string& name);
  int getNumberOfStudents() const;
  int getCourseCapacity()const;
  void shrinkCapacity();
  void increaseCapacity(unsigned inc);
  std::string getStudents(int index);

  //oveload operator+= as a member function
  Course operator+=(Course c);


 private:
  std::string courseName;
  std::string section;
  std::string* students;
  int numberOfStudents;
  int capacity;
};

#endif

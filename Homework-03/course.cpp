// Copyright 2022 by Andrew Boothe
// Homework-03
// April 21, 2022

#include <string>
#include <iostream>
#include<fstream>
#include "course.h"

Course::Course(const std::string& acourseName, const std::string& asection, int acapacity) {
    numberOfStudents = 0;
    courseName = acourseName;
    section = asection;
    capacity = acapacity;
    students = new std::string[capacity];
    std::cout << courseName << "-" << section << " has been created!" << std::endl;
}

Course::~Course() {
    std::cout << courseName << "-" << section << " has been deleted!" << std::endl;
    delete[] students;
    numberOfStudents = 0;
    capacity = 0;
    courseName = "";
    section = "";
}

Course::Course(Course& original) {
    this->capacity = original.capacity;
    this->numberOfStudents = original.numberOfStudents;
    this->courseName = original.courseName;
    this->section = original.section;
    students = new std::string[capacity];
    for (int i = 0; i < numberOfStudents; i++) {
      this->students[i] = original.students[i];
    }
}  // copy constructor

Course& Course::operator=(Course& right) {
    std::cout << "Course copy assignment operator " << std::endl;
    this->capacity = right.capacity;
    this->numberOfStudents = right.numberOfStudents;
    this->courseName = right.courseName;
    this->section = right.section;
    students = new std::string[capacity];
    for (int i = 0; i < numberOfStudents; i++) {
      this->students[i] = right.students[i];
    }
    delete[] students;
    return *this;
}

  void Course::setCourseName(std::string name) {
      std::string old = courseName;
      courseName = name;
      std::cout << "Course name " << old << "-" << section;
      std::cout << " has been changed to " << courseName << "-" << section << std::endl;
  }
  std::string Course::getCourseName() const {
      return courseName;
  }
  void Course::setSection(std::string section) {
      std::string old = section;
      this->section = section;
      std::cout << "Course section " << courseName << "-" << old << " has been changed to " << section << std::endl;
  }
  std::string Course::getSection() const {
      return section;
  }
  void Course::addStudent(const std::string& name) {
     if (capacity > numberOfStudents) {
         students[numberOfStudents] = name;
         numberOfStudents++;
         std::cout << name << " was added to "<< courseName << "-" << section << " successfully" << std::endl;
     } else {
         std::cout << "The course " << courseName << "-" << section << " has reached maximum capacity! " << std::endl;
         std::cout << "You need to increase the capacity!!" << std::endl;
     }
  }
  void Course::dropStudent(const std::string& name) {
      for (int i = 0; i < numberOfStudents; i++) {
          if (name == students[i]) {
             students[i] = students[numberOfStudents-1];
             students[numberOfStudents-1] = "";
             numberOfStudents--;
             std::cout << "Student: " << students[i];
             std::cout << " dropped the course " << courseName << "-" << section << std::endl;
             return;
          }
      }
  }
  int Course::getNumberOfStudents() const {
      return numberOfStudents;
  }
  int Course::getCourseCapacity()const {
      return capacity;
  }
  void Course::shrinkCapacity() {
      if (capacity > numberOfStudents) {
         capacity = numberOfStudents;
         std::string* students2 = new std::string[capacity];
         for (int i = 0; i < capacity; i++) {
            students2[i] = students[i];
         }
         delete[] students;
         students = students2;
         std::cout << "The capacity of " << courseName << "-" << section;
         std::cout << " is now equal to the number of students" << std::endl;
      } else {
         std::cout << "No need to shrink !! Capacity is equal to the number of students for ";
         std::cout << courseName << std::endl;
      }
  }
  void Course::increaseCapacity(unsigned inc) {
     capacity += inc;
      std::string* students2 = new std::string[capacity];
      for (int i = 0; i < numberOfStudents; i++) {
        students2[i] = this->students[i];
      }
      delete[] students;
      this->students = students2;
      std::cout << "The capacity of " << courseName << "-" << section << " has been increased by " << inc << std::endl;
  }
  std::string Course::getStudents(int index) {
      return students[index];
  }

  Course Course::operator+=(Course c) {
     int newCapacity = this->capacity += c.capacity;
     std::string* students2 = new std::string[newCapacity];
     for (int i = 0; i < this->numberOfStudents; i++) {
         students2[i] = students[i];
     }
     for (int i = 0; i < c.numberOfStudents; i++) {
         students2[i+numberOfStudents] = c.students[i];
         std::cout << "The students of " << c.courseName << "-" << c.section;
         std::cout << " have been added to " << this->courseName << "-";
         std::cout << this->section << " with the operator +=" << std::endl;
     }
      numberOfStudents += c.numberOfStudents;
      delete[] students;
      students = students2;
      return *this;
  }

    std::ostream& operator<<(std::ostream& out, Course c) {
      out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
      out << "Course Name: " << c.getCourseName() << std::endl;
      out << "Section    : " << c.getSection() << std::endl;
      out << "Capacity   : " << c.getCourseCapacity() << std::endl;
      out << "#ofStudents: " << c.getNumberOfStudents() << std::endl;
      out << "---------Student List------------" << std::endl;

    if (c.numberOfStudents == 0) {
        out << "(no students to list)" << std::endl;
    }
      for (int i = 0; i < c.getNumberOfStudents(); i++) {
          out << i+1 << ". " << c.getStudents(i) << std::endl;
      }
      return out;
    }

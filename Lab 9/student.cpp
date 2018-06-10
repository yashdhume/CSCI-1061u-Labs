#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
class Student
{
  public:
  std::string name_;
  int number_;
  std::vector<int> grades_;
  int num_courses_=5;

  // You need to implement the following four methods
  static std::string gen_name() {
    char charcter;
    int rnd;
    std::string name;
    for (int i=0; i<10; i++){
        rnd = rand() % 26;
        charcter = 'a' + rnd;
        name+= charcter;
    }
    return name;
  } // To do
  static int gen_number() {
    return (rand()%(100999999+1-100000000))+100000000;

  } // To do
  static int gen_grade() {
    return rand()%100+1;

  } // To do
  double compute_average() {
    int average;
    for (int i =0; i< num_courses_; i++){
        average+=gen_grade();
    }
    return average;
  } // To do

  Student() {
      name_=gen_name() ;
      number_=gen_number();
      for (int i=0; i<num_courses_; ++i) {
        grades_.push_back(gen_grade());
    }

  }


 friend std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Name = " << s.name_ << ", Number = " << s.number_;
    return os;
  }



  void print_grades(std::ostream& os) const
  {
    for (int i=0; i<num_courses_; ++i) {
      os << grades_[i] << ", ";
    }
  }
};

struct sortByNumber
{
    inline bool operator() (const Student& num1, const Student& num2)
    {
        return (num1.name_ < num2.name_);
    }
};
struct sortByName
{
    inline bool operator() (const Student& name1, const Student& name2)
    {
        return (name1.name_ < name2.name_);
    }
};
struct sortByGrade
{
    inline bool operator() (const Student& grade1, const Student& grade2)
    {
        return (grade1.grades_ < grade2.grades_);
    }
};
int main(int argc, char** argv)
{
  std::srand(time(0));

  std::vector<Student> x;

  int n = atoi(argv[1]);
  for (int i=0; i<n; ++i) {
    x.push_back(Student());
  }

  for (std::vector<Student>::iterator xi = x.begin(); xi != x.end(); xi++) {
    std::cout << *xi << std::endl;
  }
  std::cout << std::endl;
    std::cout << "Student Number sort: " << std::endl;

  std::sort(x.begin(), x.end(),sortByNumber());
  for (std::vector<Student>::iterator xi = x.begin(); xi != x.end(); xi++) {
    std::cout << *xi << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Name sort: " << std::endl;
  std::sort(x.begin(), x.end(),sortByName());
  for (std::vector<Student>::iterator xi = x.begin(); xi != x.end(); xi++) {
    std::cout << *xi << std::endl;
  }
  std::cout << std::endl;
    std::cout << "Grade sort: " << std::endl;
  std::sort(x.begin(), x.end(),sortByGrade());
  for (std::vector<Student>::iterator xi = x.begin(); xi != x.end(); xi++) {
    std::cout << *xi << std::endl;
  }



  return 0;
}

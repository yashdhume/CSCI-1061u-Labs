#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>

using namespace std;

char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
char digits[] = "0123456789";

// Converts a character between 0 and 9
// to an integer value
int char_to_int(char c){
  return c-48;
}

// Picks a random char from an array of
// characters with length n
char choose_char(char* ptr_c, int n){
    int rnd = rand()%n;
    return ptr_c[rnd];
}

// Generates a random name having length between
// 5 and 15 letters.
// The first letter of the name is capitalized.
string gen_random_name(int min_len, int max_len){
    string n;
    int nameLen = rand()%10 + 5;
    n+=choose_char(Alphabet, 26);
    for(int i = 0; i < nameLen-1; i++){
        n += choose_char(alphabet, 26);
    }
    return n;
}

//
struct Employee {
    string firstname;
    string lastname;
    char skill; // Between 0 and 9
    int bonus; // Between 0 and 9 - tied to skill
};

const int NUM_EMPLOYEES = 5;

void diagnostics_mem_layout(Employee* employees, int n){
  for(int i=0; i<5; i++)
        cout << "Address of the" << i << "employee: "  << &employees[i] << endl;


  //--------------------------------------------------------
  // Task 2: Compute the offset between employee 2 and 3, and
  // between employee 0 and 1.  Is it the same?

    cout << "Offset between employee 2 and 3: "  << ((long)&employees[3]-(long)&employees[2])<<  endl;
    cout << "Offset between employee 0 and 1: "  << ((long)&employees[1]-(long)&employees[0])<<endl;

  //--------------------------------------------------------
  // Task 3: How much space does employee 0-4 takes in the memory?
  //
  // Use sizeof() to compute the size of the Employee struct
    for(int i =0; i<5; i++)
        cout << "Size of employee: "<<i  << " " << sizeof(employees[i]) <<endl;

  //As the variables are in a struct no matter what the contnet is it will be the same size and it is fixed


  //--------------------------------------------------------
  // Task 4: Print the memory address where skill level and bonus for
  // employee 3 is stored.  How much space skill level takes and how
  // much space bonus takes?
  //
  // You'll notice that you need to cast to address of skill, which is a char,
  // to (void *).  This is because the << operator is treating this as
  // a char array.
  //
  // Pointers are arrays are intimately tied.


  cout << "Skill for employee 3: "  << (void *)&employees[3].skill << endl;
  cout << "Bonus for employee 3: "  << &employees[3].bonus  <<endl;
  cout << "Skill and Bonus are " <<(long)&employees[3].bonus - (long)&employees[3].skill +3 << " apart" << endl;

}

int main()
{
  srand(time(NULL));

  // Array of employees
  Employee employees[NUM_EMPLOYEES];

  for (int i=0; i<NUM_EMPLOYEES; ++i) {
    employees[i].firstname = gen_random_name(2, 10);
    employees[i].lastname = gen_random_name(2, 10);
    employees[i].skill = choose_char(digits, 10);
    employees[i].bonus = char_to_int(employees[i].skill);
  }

  // Print
  for (int i=0; i<NUM_EMPLOYEES; ++i) {
    cout << "Employee " << i << endl;
    cout << "\tFirst name: " << employees[i].firstname << endl;
    cout << "\tLast name: " << employees[i].lastname << endl;
    cout << "\tskill: "  << employees[i].skill << endl;
    cout << "\tbonus: "  << employees[i].bonus << endl;
  }

  // Call the following function to complete the following tasks
  diagnostics_mem_layout(employees, NUM_EMPLOYEES);

  return 0;
}

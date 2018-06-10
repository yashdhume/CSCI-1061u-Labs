#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


using namespace std;
int main() {
	string getContent;
    int emplyoee =1;
	ifstream fileInput("xyz-employee.dat");
	while (!fileInput.eof()) {
        getline(fileInput, getContent);
        cout << "Employee: " << emplyoee;
        cout << "\n "<<getContent <<endl;
        emplyoee++;
	}

	return 0;
}


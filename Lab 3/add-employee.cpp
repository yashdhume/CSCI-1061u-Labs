#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main(){
    string firstName, lastName, input;
    int wage, ID=0;
    ifstream fileInput("xyz-employee.dat");
    while (!fileInput.eof()) {
            getline(fileInput, input);
            ID++;
    }
    cout << "New Employee" << "\nFirst name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Wage: ";
    cin >> wage;

	ofstream fileOutput("xyz-employee.dat", ios::app);

    fileOutput << "\n" << firstName << " " << lastName << " (" << wage << ") ";

	fileOutput.close();


	cout << "New Employee ID " <<ID+1<< endl;

    return 0;
}


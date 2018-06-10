#include "average.h" 
#include <iostream> 
using namespace std;
int main() { 
	float a, b, c; 
	cout << "Enter a: "; 
	cin >> a; 
	cout << "Enter b: "; 
	cin >> b; 
	cout << "Enter c: "; 
	cin >> c;
	cout << "Average of a, b and c is " << average3(a, b, c) << endl;
	return 0;
}

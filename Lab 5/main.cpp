#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;
extern void count(char* , int , int* );
int main(int argc, char** argv){
    if(argc < 2) {
        cerr << "Usage: " << argv[0] << " <count>" << endl;
        cerr << "\t<count> is an integer between 10 and 10000\n";
        cerr << "\tExiting.";
        return -1;
    }
    int n = atoi(argv[1]);
    if (n < 10 || n > 10000) {
        cerr << "Usage: " << argv[0] << " <count>" << endl;
        cerr << "\t<count> is an integer between 10 and 10000\n";
        cerr << "\tExiting.";
        return -2;
    }
    srand(time(NULL));

    char* arr = new char[n];


    for(int i =0; i < n; i++){
        arr[i]= rand()%26+65;
    }
    for(int i=0; i<n; ++i) {
        cout << arr[i] <<' ';
    }
    int *counts = new int[26];
    count(arr, n , counts);
    for(int i=0; i < 26; i++){
        cout << (char)(i+65) << ": " << counts[i] << endl;
    }
    cout << endl;
    delete [] arr;
    return 0;
}

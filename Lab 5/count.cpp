#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;
void count(char* arr, int n, int* counts){
    for(int i=0;i< 26; i++){
        counts[i]= 0;
    }
    for(int i=0; i< n; i++){
        for(int j=0; j<26;j++){
            if(arr[i]==j+65){
                counts[j]++;
            }
        }
    }
}


#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]){
    string cipher;
    string cipherText[100];
    string userInput;
    int shift = 0;
    int choice =0;
    if(string(argv[1])=="-e"){
        choice= 0;
    }
    else if (string(argv[1]) == "-d"){
        choice = 1;
    }
    shift = atoi(argv[2]);
    int lineNum = 0;
	ifstream fileInput(argv[3]);
	while(fileInput.good()){
        getline(fileInput, cipherText[lineNum]);
        lineNum++;
	}
    for (int i=0; i<lineNum; i++){
        for(int j=0; j<cipherText[i].length(); j++){
            if (cipherText[i][j] >=  'A'&& cipherText[i][j] <= 'Z'){
                if (choice==0){
                    cipherText[i][j] = char(((cipherText[i][j] + shift - 'A' + 26) % 26) + 'A');
                }
                else if(choice == 1){
                    cipherText[i][j] = char(((cipherText[i][j] - shift - 'A'+  26) % 26) + 'A');
                }
            }
        }
        ofstream file_output(argv[4]);
        for (int index = 0; index < lineNum; index++) {
            file_output << cipherText[index] << endl;
        }
        file_output.close();
    }
    return 0;
}


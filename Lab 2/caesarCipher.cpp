#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    string cipher;
    char cipherText[100];
    string userInput;
    int shift = 0;
    cout << "Enter shift+/- 26: ";
    cin >> shift;
    cout<< "Enter a plaintext message (A-Z, no spaces:)";
    cin>>cipherText;
    int num = strlen(cipherText);
    for (int i=0; i < num; i++){
        if (cipherText[i] >= 'A' && cipherText[i] <= 'Z'){
            //cipher[i] = 65+(((cipherText[i]-65)+shift)%26);
            cipherText[i] = char(((cipherText[i] + shift - 'A' + 26) % 26) + 'A');
        }
        else{
            cout<< "Please enter only Uppercase Letters";
        }
    }
    cout<< "Cipher text: " <<cipherText;
    for (int i=0; i < num; i++){
        if (cipherText[i] >= 'A' && cipherText[i] <= 'Z'){
            cipherText[i] = char(((cipherText[i] - shift - 'A' + 26) % 26) + 'A');
        }
    }
    cout<< "\nPlain Text: "<<cipherText;

    return 0;
}

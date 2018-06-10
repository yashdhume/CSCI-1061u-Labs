#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;
class Filter{
protected:
  string _name;

public:
    Filter(const string& name) : _name(name) {}
    virtual ~Filter() {};

    virtual string apply(const string& input) = 0;

    string get_name() { return _name; }
};
class Capitalize:public Filter{

    public:
        string Cap;
        Capitalize(): Filter("Capitalize"){}
        ~Capitalize(){}
        virtual string apply(const string& input){
            for(int i = 0 ; i < input.size(); i++)
                Cap.push_back(input[i]);
            for ( int i =0; i < input.size(); i++){
                if(islower(Cap[i]))
                    Cap[i]=toupper(Cap[i]);

            }
            return Cap;
        }

};
class CapitalizeFirstLetter:public Filter{

    public:
        string CapFirst;
        CapitalizeFirstLetter(): Filter("CapitlizeFirstLetter"){}
        ~CapitalizeFirstLetter(){}
        virtual string apply(const string& input){
            for(int i = 0 ; i < input.size() ; i++)
                CapFirst.push_back(input[i]);
            int i =0;
            if(islower(CapFirst[i]))
                CapFirst[i]=toupper(CapFirst[i]);
            return CapFirst;
            }


};
class CapitalizeFirstLetterOfEveryWord:public Filter{

    public:
        CapitalizeFirstLetterOfEveryWord(): Filter("CapitlizeFirstLetterOfEveryWord"){}
        ~CapitalizeFirstLetterOfEveryWord(){}
        virtual string apply(const string& input){
        string CapFirstEv;

            for(int i = 0 ; i < input.size() ; i++)
                CapFirstEv.push_back(input[i]);

            for(int i=0;i<input.size()+1;i++){
                if(i==0){
                    if(islower(CapFirstEv[i]))
                    CapFirstEv[i]=toupper(CapFirstEv[i]);
                }
                else{
                    if(CapFirstEv[i]!=' '){
                        if(isupper(CapFirstEv[i]))
                        CapFirstEv[i]=tolower(CapFirstEv[i]);
                    }
                    else{
                        i++;
                        if(islower(CapFirstEv[i]))
                            CapFirstEv[i]=toupper(CapFirstEv[i]);
                    }
                }
            }
            return CapFirstEv;
        }

};
class Obenglobish:public Filter{


    public:
        Obenglobish(): Filter("Obinglobish"){}
        ~Obenglobish(){}
        bool isVowel(char val){
            if (val == 'a' || val == 'e' || val == 'i' || val == 'o' || val == 'u'||val == 'A' || val == 'E' || val == 'I' || val == 'O' || val == 'U'){
                    return true;
            }
            return false;
        }
        virtual string apply(const string& input){
        string obenglo;
        for (int i = 0; i < input.size(); i++){
            char letter = input[i];
            if (isVowel(letter)){
                if (isVowel(input[i-1])){
                    obenglo += letter;
                }
                else if (letter == 'e' && i == input.size
                ()-1){
                    obenglo += letter;
                }
                else{
                    obenglo = obenglo + "ob" + letter;
                }
            }
            else{
                obenglo += letter;
            }
        }
        return obenglo;
    }


};
class ReverseString:public Filter{

    public:
        ReverseString(): Filter("ReverseString"){}
        ~ReverseString(){}
        virtual string apply(const string& input){
            string rev;
            for(int i = 0 ; i < input.size(); i++)
                rev.push_back(input[i]);
             reverse(rev.begin(), rev.end());
            return rev;
        }

};
class ToSmall:public Filter{

    public:
        ToSmall(): Filter("toSmall"){}
        ~ToSmall(){}
        virtual string apply(const string& input){
            string small;
            for(int i = 0 ; i < input.size(); i++)
                small.push_back(input[i]);
            for ( int i =0; i < input.size(); i++){
                if(isupper(small[i]))
                    small[i]=tolower(small[i]);

            }
            return small;
        }

};
class Randomize:public Filter{

    public:
        Randomize(): Filter("Randimize"){}
        ~Randomize(){}
        virtual string apply(const string& input){
            string rnd;
            for(int i = 0 ; i < input.size(); i++)
                rnd.push_back(input[i]);
            srand(time(0));
            for(int i = input.size()-1; i>=0; i--){
                int ranNum = rand()%input.size();
                char temp = rnd[i];
                rnd[i] = rnd[ranNum];
                rnd[ranNum] = temp;
            }
            return rnd;
        }

};
int main(){

    const int num_filters = 7;
    Filter* filters[num_filters];

    filters[0] = new Capitalize();
    filters[1] = new CapitalizeFirstLetter();
    filters[2] = new CapitalizeFirstLetterOfEveryWord();
    filters[3] = new Obenglobish();
    filters[4] = new ReverseString();
    filters[5] = new ToSmall();
    filters[6] = new Randomize();

    string input;
    cout << "Enter srring: ";  getline(cin, input);
    cout << "Input string: " << input << endl;
    for (int i=0; i<num_filters; ++i) {
      cout << "Filter name:  " << filters[i]->get_name() << endl;
      cout << "Output:       " << filters[i]->apply(input) << endl;
    }

    for (int i=0; i<num_filters; ++i)
    delete filters[i];
}

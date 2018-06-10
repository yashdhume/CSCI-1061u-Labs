// str.cpp
#include "str.h"
#include <cstring>

str::str() : _n(0), _buf(0) {}
str::str(int n) : _n(n) { _buf = new char[_n]; }
str::str(char ch) : _n(1) {
  _buf = new char[_n];
  _buf[0] = ch;
}
str::str(const char* c_str) {
  _n = strlen(c_str);
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i) _buf[i] = c_str[i];
}
str::~str() {
  if (_buf) delete[] _buf;
}
ostream& operator<<(ostream& os, const str& s) {
  if (!s.is_empty()) {
    for (int i = 0; i < s.length(); ++i) {
      cout << s[i];
    }
  } else
    cout << "[null str]";
  return os;
}
istream& operator>>(istream& is, str& s) {
  char ch[20];
 // do {
    is>>ch;
   // if (ch == ' ' || ch =='\n' ) break;
    //s = s + ch;'
    s._n=strlen(ch);
    s._buf=new char[s._n+1];
    strcpy(s._buf,ch);
 // } while (true);
  return is;

}
// 1. TODO - assignment operator m=a
// 2. TODO - concatenation operator .concat()
const str& str::operator=(const str& s){
    delete[] this->_buf;
    for(int i=0; i<s._n;i++){
        this->_buf[i]= s._buf[i];
    }
    return *this;
}
str operator+(const str& a, const str& b){
    str c;
    c._n=a._n+b._n;
    c._buf=new char[c._n+1];
    strcpy(c._buf,a._buf);
    strcat(c._buf,b._buf);
    return c;
}



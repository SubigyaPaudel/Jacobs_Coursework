#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    cout << s.length();
    char* sd = new char[s.length()];
    int pos = 0;
    for(int i = s.length() - 1; i >= 0; i--){
        sd[pos] = s[i];
        pos++;
    }
    cout << sd <<endl;
    delete [] sd;
}

// to iterate through the string for(int i=0; strp[i]; i++)
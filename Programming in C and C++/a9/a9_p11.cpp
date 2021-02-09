/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a9_p11.c
*/

#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(string word){
    if(word.length() == 1)
        return 1;
    int length = word.length();
    char* reverse = new char[length];           // allocating memory to store the reversed word
    int pos = 0;
    bool result;
    for(int i = length - 1; i >= 0; i--){
        word[i] = toupper(word[i]);           // making sure that uppercase/lowercase characters are the same
        reverse[pos] = word[i];
        pos++;
    }
    if(word == reverse){
        result = 1;
    }else{
        result = 0;
    }
    delete [] reverse;
    return result;
}

int main(){
    string word;
    cout << "Enter a word, type exit to leave" << endl;
    cin >> word;
    while (1){
        if(isPalindrome(word)){
            cout << "True" << endl;
        }else{
            cout << "False"<< endl;
        }
        cout << "Enter a word, type exit to leave" << endl;
        cin >> word;
        if(word == "exit")   // this conditional statement is placed at the end to avoid printing "Enter a word...."
            break;
    }
    return 0;
}
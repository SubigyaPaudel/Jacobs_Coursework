/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a9_p7.c
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int myfirst (int *integers, int intnum){
    int inttarget, found = 0;
    for(int i = 0; i < intnum ; i++){
        if(integers[i] > 0 && (integers[i] % 2) == 0){
            inttarget = integers[i];
            found = 1;
            break;
        }
    }
    if(found == 1){
        return inttarget;
    }else{
        return -1;
    }
}

double myfirst(double* doubles, int numdoubles){
    double target;
    double difference;
    int found = 0;
    for(int i = 0; i < numdoubles; i++){
       difference = doubles[i] - (double) ((int) doubles[i]);
       if(difference == 0.0){
           target = doubles[i];
           found = 1;
           break;
       }
    }
    if(found == 1){
        return target;
    }else{
        return -1.1;
    }
}

char myfirst(char *array, int chars){
    char letter, target;
    int found = 0;
    char consonants[21] = {'b','c','d', 'f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
    for(int i = 0; i < chars; i++){
        letter = array[i];
        for(int j = 0; j < 21 ; j++){
            if(consonants[j] == letter){
                target = letter;
                found = 1;
                i = chars;
                break;
            }
        }
    }
    if(found == 1){
        return target;
    }else{
        return '0';
    }
}

int main(){
    int intnum, numdoubles, cnum;
    cout << "How many integers you want to enter" << endl;
    cin >> intnum;
    cout << "Enter the numbers" << endl;
    int* integers = new int[intnum];
    if(integers == NULL){
        cout << "Error allocating memory" << endl;
        exit(1);
    }
    for(int i = 0; i < intnum ; i++){
        cin >> integers[i];
    }
    int firstint = myfirst(integers, intnum);
    cout << firstint << endl; 
    cout << "How many doubles you want to enter" << endl;
    cin >> numdoubles;
    cout << "Enter the numbers" << endl;
    double* doubles = new double[numdoubles];
    if(doubles == NULL){
        cout << "Error allocating memory" << endl;
        exit(1);
    }
    for(int i = 0; i < numdoubles ; i++)
        cin >> doubles[i];
    double firstdouble = myfirst(doubles, numdoubles);
    cout << firstdouble<< endl; 
    cout << "How many characters do you want to enter?" << endl;
    cin >> cnum;
    char* chars = new char[cnum];
    if(chars == NULL){
        cout << "Error allocating memory" << endl;
        exit(1);
    }
    for(int i = 0; i < cnum; i++)
        cin >> chars[i];
    char cresult = myfirst(chars, cnum);
    cout << cresult << endl;
    delete [] chars;
    delete [] doubles;
    delete [] integers;
    return 0;
}


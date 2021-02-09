/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a9_p6.c
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    int enter, target, tries;
    tries = 1;                                // because the player will enter the number atleast once
    string name;
    srand(static_cast<unsigned int>(time(0)));         // making sure that the list of random number changes with time
    target = rand() % 101;
    cout << "What is your name?" << endl;
    getline(cin, name);
    cout << "Enter a number" << endl;
    cin >> enter;
    while (enter != target){
        if(enter > target){
            cout << "Higher than the number" << endl;
        }else{
            cout << "Lower than the number"<< endl;
        }
        tries++;
        cout << "Enter the number again" << endl;
        cin >> enter;
    }   
    cout << "Congratutlations! Your guess was correct. The number is " << target << "\nNumber of tries= " << tries << endl;      
    return 0;
}
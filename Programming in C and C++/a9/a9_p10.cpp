/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a9_p10.c
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    string* array = new string[17];
    int tries = 0;
    string target,guess;
    string leave = "no";
    string enter = "Not quit";
    char letter;
    array[0] = "computer";
    array[1] = "television";
    array[2] = "keyboard";
    array[3] = "laptop";
    array[4] = "mouse";
    array[5] = "hammer";
    array[6] = "telephone";
    array[7] = "smartphone"; 
    array[8] = "tablet";
    array[9] = "heater";
    array[10] = "table";
    array[11] = "chair";
    array[12] = "cupboard";
    array[13] = "chocolate";
    array[14] = "door";
    array[15] = "window";
    array[16] = "trees";
    while (leave != "quit"){
        tries = 0;
        srand(static_cast<unsigned int>(time(0)));
        target = array[rand() % 17];
        int i = 0;
        cout << "Guess this word" << endl;
        while(target[i] != '\0'){
            letter = target[i];
            if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u'){
                cout << '_';
            }else{
                cout << letter;
            }
            i++;
        }
        cout << endl;
        while(guess != target){
            if(tries > 0)
                cout << "Wrong guess, enter the word again" << endl;
            tries++;
            getline(cin, guess);
        }
        cout << "correct guess\n tries=" << tries << endl;
        cout << "Do you want to play again? Enter quit to leave" << endl;
        getline(cin, leave);
    }
    delete [] array;
    return 0;
}
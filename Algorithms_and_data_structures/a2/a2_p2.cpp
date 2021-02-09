#include <iostream>
#include <deque>
#include <cstdlib>

using namespace std;
int main(){
    deque<float> A;
    float input;
    while(true){
        cout << "Enter a floating point number" << endl;
        cin >> input;
        if(input == 0.0){
            break;
        }else if(input > 0.0){
            A.push_back(input);
        }else{
            A.push_front(input);
        }
    }
    deque<float>::iterator Aiterator, insert_position;
    for(Aiterator = A.begin(); Aiterator != A.end(); Aiterator++){
        cout << *Aiterator << " ";
        if(*Aiterator < 0 && *(Aiterator + 1) > 0){
            insert_position = Aiterator + 1;
        }
    }
    cout << endl << endl;
    A.insert(insert_position, 0.0);
    for(Aiterator = A.begin(); Aiterator != A.end(); Aiterator++)
        cout << *(Aiterator) << ";";
    cout << '\b';
    return 0;
}
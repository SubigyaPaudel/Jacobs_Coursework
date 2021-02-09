#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "queue.h"

using namespace std;

int main(){
    int size, input;
    string response;
    cout << "Enter the queue size" << endl;
    cin >> size;
    queue<int> line(size);
    while(true){
        cout << "Type 'add' to add an integer into the queue" << endl;
        cout << "Type 'remove' to pop an integer out of the queue" << endl;
        cout << "Type 'check' to see if the stack is empty" << endl;
        cout << "Type 'X' to see if the stack is empty" << endl;
        cin >> response;
        if(response == "add"){
            cout << "Enter an integer" << endl;
            cin >> input;
            line.add(input);
        }else if(response == "remove"){
            input = line.remove();
            cout << "The element on the front of the queue is" << input << endl;
        }else if(response == "check"){
            cout << line.isempty() << endl;
        }else if(response == "X"){
            break;
        }
        else{
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}
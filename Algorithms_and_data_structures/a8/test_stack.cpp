#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "stack.h"

using namespace std;

int main(){
    int size, input;
    string response;
    cout << "Enter the stack size" << endl;
    cin >> size;
    stack<int> heap(size);
    while(true){
        cout << "Type 'push' to push an integer into the stack" << endl;
        cout << "Type 'pop' to pop an integer out of the stack" << endl;
        cout << "Type 'check' to see if the stack is empty" << endl;
        cout << "Type 'X' to see if the stack is empty" << endl;
        cin >> response;
        if(response == "push"){
            cout << "Enter an integer" << endl;
            cin >> input;
            heap.push(input);
        }else if(response == "pop"){
            input = heap.pop();
            cout << "The element on the top of the list is" << input << endl;
        }else if(response == "check"){
            cout << heap.is_empty() << endl;
        }else if(response == "X"){
            break;
        }
        else{
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}
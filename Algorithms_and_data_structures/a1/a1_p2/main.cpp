#include "Stack.h"

using namespace std;

template <class T>
void loop(int value){
    Stack<T> heap(value);
    string choose;
    T element;
    bool success;
    while(true){
        cout << "Enter \'push\' to insert an element to the stack" << endl;
        cout << "Enter \'pop\' to remove an element from the stack" << endl;
        cout << "Enter \'back\' to get the last element of the stack" << endl;
        cout << "Enter \'end\' to exit the program" << endl;
        cin >> choose;
        if(choose == "push"){
            cin >> element;
            success = heap.push(element);            
        }else if(choose == "pop"){
            success = heap.pop(element);
        }else if(choose == "back"){
            cout << heap.back() << " is in the end of the stack" << endl;
        }else if(choose == "end"){
            break;
        }else{
            cout << "Invalid word, enter a valid word" << endl;
        }
        if(success == false)
            cout << "Last operation not successful" << endl;
    }
}

int main(){
    int choice, number;
    cout << "Enter 1 for int, 2 for double, and 3 for string" << endl;
    cin >> choice;
    cout << "How many elements do you want the stack to hold?" << endl;
    cin >> number;
    if(choice == 1)
        loop<int>(number);
    if(choice == 2)
        loop<double>(number);
    if(choice == 3)
        loop<string>(number);
    return 0;
}
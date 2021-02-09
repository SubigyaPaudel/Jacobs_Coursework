#include "Linked_list.h"
#include <cstring>

using namespace std;

template <class T>
void cycle(list<T>& my_list){
    string choice;
    T element;
    while(true){
        cout << "Type \'push_back\' to enter an element at the end of the list" << endl;
        cout << "Type \'push_front\' to enter an element at the end of the list" << endl;
        cout << "Type \'pop_back\' to remove an element from the end of the list" << endl;
        cout << "Type \'pop_front\' to remove an element from the beginning of the list" << endl;
        cout << "Type \'get_front\' to check the first element of the list" << endl;
        cout << "Type \'back\' to check the last element of the list" << endl;
        cout << "Type \'get_number\' to check the number of elements in the list" << endl;
        cout << "Type \'leave\' to leave." << endl;
        cin >> choice;
        if(choice == "push_back"){
            cout << "Enter the element" << endl;
            cin >> element;
            my_list.push_back(element);
        }else if(choice == "push_front"){
            cout << "Enter the element" << endl;
            cin >> element;
            my_list.push_front(element);
        }else if(choice == "pop_front"){
             if(my_list.start != NULL){
                cout << "Popping out " << my_list.pop_front() << " from the beginning of the list" << endl;
             }else{
                cout << "List empty, nothing to pop" << endl;
             }
        }else if(choice == "pop_back"){
            if(my_list.start != NULL){
                cout << "Popping out " << my_list.pop_back() << " from the end of the list" << endl;
            }else{
                cout << "List empty, nothing to pop" << endl;
            }
        }else if(choice == "get_front"){
            cout << my_list.get_front() << " is in the beginning of the list" << endl;
        }else if(choice == "back"){
            cout << my_list.get_back() << " is on the end of the list" << endl;
        }else if(choice == "get_number"){
            cout << "There are" << my_list.get_number() << "elements in the list" << endl;
        }else if(choice == "leave"){
            break;
        }else{
            cout << "Invalid command, enter a valid command." << endl;
        }
    }
}

int main(){
    string choice;
    cout << "Which data type's linked list do you want?" << endl;
    cout << "int/double/string/float" << endl;
    cin >> choice;
    if(choice == "int"){
        list<int> mylist;
        cycle(mylist); 
    }else if(choice == "double"){
        list<double> mylist;
        cycle(mylist);
    }else if(choice == "string"){
        list<string> mylist;
        cycle(mylist);
    }else if(choice == "float"){
        list<float> mylist;
        cycle(mylist);
    }
    return 0;  
}
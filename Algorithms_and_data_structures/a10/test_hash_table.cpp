#include <iostream>
#include <cstdlib>
#include "hash_table.h"
#include <time.h>
#include <string>

using namespace std;

int main(){
    string action;
    Hashtable mytable(100);
    int query;
    int receptor;
    srand(time(0));
    for(int i = 0; i < 49; i++){
        int newkey = rand();
        int newvalue = rand();
        cout << "Inserting (" << "Key = " << newkey << "," << "Value" << newvalue << ") in the table" << endl;
        mytable.insertnode(newkey, newvalue);
    } 
    while(true){
        cout << "Enter 'x' to exit this session" << endl;
        cout << "Enter 'get' to get an element from hashtable" << endl;
        cout << "Enter 'print to print the hash table'"<< endl;
        cin >> action;
        if(action == "x"){
            break;
        }else if(action == "get"){
            cout << "Enter the key" << endl;
            cin >> query;
            receptor = mytable.get(query);
            cout << "The corresponding key of " << query << " is " << receptor << endl;
        }else if(action == "print"){
            mytable.printtable();
        }else{
            cout << "Invalid command, enter a valid command" << endl;
        }
    }
    return 0;  
}
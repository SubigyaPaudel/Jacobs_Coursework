#include <iostream>
#include "Access.h"

using namespace std;

int main(){
    Access doors;
    int enter;
    doors.activate(1234);
    doors.activate(9999);
    doors.activate(9876);
    while(true){
    cout << "Enter a access code" << endl;
    cin >> enter;
    if(doors.isactive(enter)){
        cout << "Welcome" << endl;
        break;
    }else{
        cout << "Access denied" << endl;
    }
    }
    doors.activate(1111);
    doors.deactivate(enter);
    doors.deactivate(9999);
    while(true){
    cout << "Enter a access code" << endl;
    cin >> enter;
    if(doors.isactive(enter)){
        cout << "Welcome" << endl;
        break;
    }else{
        cout << "Access denied" << endl;
    }
    }
    return 0;
}
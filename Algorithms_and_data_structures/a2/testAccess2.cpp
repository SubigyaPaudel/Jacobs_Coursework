#include <iostream>
#include "Access2.h"

using namespace std;

int main(){
    Access secure;
    int enter;
    secure.activate(1234,1);
    secure.activate(9999,5);
    secure.activate(9876,9);
    while(true){
        cout << "Enter the code" << endl;
        cin >> enter;
        if(secure.isactive(enter,5)){
            break;
        }else{
            cout << "Access denied" << endl;
        }
    }
    cout << "Door opened successfully. Welcome" << endl;
    secure.deactivate(enter);
    secure.change_access_level(9999,8);
    secure.activate(1111,7);
    while(true){
        cout << "Enter the code" << endl;
        cin >> enter;
        if(secure.isactive(enter,7)){
            break;
        }else{
            cout << "Access denied" << endl;
        }
    }
    cout << "Door opened successfully. Welcome" << endl;
    return 0;
}
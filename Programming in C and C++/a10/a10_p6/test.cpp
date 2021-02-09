#include <iostream>

using namespace std;

int main(){
    int i = 8;
    switch(i){
        case 5:
            cout << "True";
            break;
        case 7:
            cout << "true";
            break;
        case 9:
            cout << "true";
            break;
        case 10:
            cout << "true";
            break;
        default:
            cout << 8;
    }
    return 0;
}
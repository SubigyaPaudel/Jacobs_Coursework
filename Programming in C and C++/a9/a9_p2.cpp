#include <iostream>

using namespace std;

int main(){
    int n;
    double x;
    string s;
    cin >> n;
    cin >> x;
    cin >> s;
    for(int i = 0; i < n ; i++){
        cout << s <<':' << x << endl;
    }
    return 0;
}

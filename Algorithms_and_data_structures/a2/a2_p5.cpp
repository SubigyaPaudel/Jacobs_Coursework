#include <iostream>
#include <cstdlib>
#include <set>
#include <ctime>

using namespace std;

int main(){
    set<int> A;
    srand((unsigned) time(0));
    for(int i = 1; i <= 6; i++)
        A.insert(rand() % 49 + 1);
    set<int>::iterator it;
    for(it = A.begin(); it != A.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}
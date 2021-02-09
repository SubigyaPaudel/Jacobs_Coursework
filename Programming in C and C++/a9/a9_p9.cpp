/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a9_p9.c
*/

#include <iostream>

using namespace std;

void subtract_max(int* &a, int n){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > max)
            max = a[i];
    }
    for(int i = 0; i < n; i++)
        a[i] -= max;
}

void deallocate(int* &a){
    delete [] a;
}

int main(){
    int n;
    cout << "Enter the number of values" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "Enter the numbers" << endl;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    subtract_max(a,n);
    cout << "After the subtract max function, the values are" << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << endl;
    deallocate(a);
    return 0;
}
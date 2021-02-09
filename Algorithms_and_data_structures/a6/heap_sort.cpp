#include <iostream>
#include <cstdlib>
#include "heap.h"

using namespace std;

int main(){
    int input;
    int number;
    cout << "Enter the number of integers you want to enter" << endl;
    cin >> number;
    int* array = new int[number]; 
    if(array == NULL){
        cerr << "Error allocating memory" << endl;
        exit(1);
    }
    for(int i = 0; i < number; i++){
        cout << "Enter a number" << endl;
        cin >> input;
        array[i] = input;  
    }
    heap<int> pile1(array, number);
    heap<int> pile2(array, number);
    // no zeroes introduced at input
    heapsort<int>(pile1); 
    cout << "The numbers, sorted by normal heap_sort, are" << endl;
    for(int i = 0; i < number; i++){
        cout << pile1[i] << " "; 
    }
    cout << endl;
    cout << "The numbers, sorted by the different variant of heap_sort, are" << endl;
    heapsort_different<int>(pile2);
    for(int i = 0; i < number; i++){
        cout << pile2[i] << " "; 
    }
    cout << endl;
    return 0;
}

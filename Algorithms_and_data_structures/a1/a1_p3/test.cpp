#include <iostream>

using namespace std;

void ascend_insertion_sort(int array[], int number){
    for(int j = 1; j < number; j++){
       int key = array[j];
       int i = j - 1;
       while(i > 0 && array[i] > key){
           array[i+1] = array[i];
           i--;
       }
       array[i+1] = key;
    }
}

int main(){
    int number;
    int* numbers;
    cout << "Enter the number of elements in an array" << endl;
    cin >> number;
    numbers = new int[number];
    if(numbers == NULL){
        cerr << "Failed to allocate memory" << endl;
        exit(1);
    }
    for(int i = 0; i < number; i++){
        cout << "Enter the number" << endl;
        cin >> numbers[i];
    }
    ascend_insertion_sort(numbers, number);
    for(int i = 0; i < number; i++)
        cout << numbers[i] << endl;
    delete numbers;
    return 0;
}
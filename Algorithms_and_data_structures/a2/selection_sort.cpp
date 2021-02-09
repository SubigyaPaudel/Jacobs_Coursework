#include <iostream>
#include <cstdlib>
#include <ctime>

template <class T>
void selection_sort(T array[], int number){
    T copy, smallest;
    int pos;
    for(int i = 0; i < number; i++){
        smallest = array[i];
        pos = i;
        for(int j = i; j < number; j++){
            if(array[j] < smallest){
                smallest = array[j];
                pos = j;
            }
        }
        copy = array[i];
        array[i] = array[pos];
        array[pos] = copy;
    }
}

template <class T>
void generate_worst_case(T array[], int number){    
    int largest_pos = 0;
    selection_sort<T>(array, number);
    T copy = array[0];
    array[0] = array[number-1];
    for(int i = 1; i < number -1; i++)
        array[i+1] = array[i];
}

/*The above function */

void random_number_generator(int* array, int number){// a function that generates an array of 'number' random numbers 
    srand((unsigned) time(0));
    for(int i = 0; i < number; i++){
        array[i] = rand() % 100;
    }
}

int main(){
    int *array1;
    array1 = new int[10];
    random_number_generator(array1, 10);
    std::cout << "Yo mama" << std::endl;
    generate_worst_case(array1,10);
    for(int i = 0; i < 10; i++)
        std::cout << array1[i] << std::endl;
    free(array1);
}
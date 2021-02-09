#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

template <class T>
void selection_sort(T array[], int number){
    T copy, smallest;
    int pos;
    for(int i = 0; i < number; i++){
        smallest = array[i];
        pos = i;
        for(int j = i; j < number; j++){//searching for the position of the smallest element on the right hand side of the array
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
    selection_sort<T>(array, number);
    T copy = array[number - 1];
    for(int i = number-1; i != 0; i--){
        array[i] = array[i-1];
    }
    array[0] = copy;
}

void random_number_generator(int* array, int number){// a function that generates an array of 'number' random numbers 
    srand((unsigned) time(0));
    for(int i = 0; i < number; i++){
        array[i] = rand() % 100;
    }
}

using namespace std;

int main(){
    int *array1;
    ofstream file1("Data_worst_case.txt");
    ofstream file2("only_time_worst_case.txt"); // files that will store only the times in order to draw the graph in Matlab
    ofstream file3("Data_best_case.txt");
    ofstream file4("only_time_best_case.txt");
    ofstream file5("Data_avg_case.txt");
    ofstream file6("only_time_avg_case.txt");
    file1.seekp(ios::beg);
    file2.seekp(ios::beg);
    file3.seekp(ios::beg);
    file4.seekp(ios::beg);
    file5.seekp(ios::beg);
    file6.seekp(ios::beg);
    cout << "Data for the worst case" << endl;
    file1 << "Data for the worst case" << endl;
    // Generating data for the worst case
    for(int i = 1000; i <= 50000; i+= 1000){
        array1 = new int[i];
        if(array1 == NULL){
            cerr << "Error allocating memory" << endl;
            exit(1);
        }
        random_number_generator(array1,i);
        generate_worst_case<int>(array1, i);
        auto start = std::chrono::high_resolution_clock::now(); 
        selection_sort<int>(array1,i);
        auto stop = std::chrono::high_resolution_clock::now();
        auto time_period = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        cout << "For" << i << "numbers:" << time_period << endl;
        file1 << "For" << i << "numbers:" << time_period << endl;
        file2 << time_period << "," << endl;
        free(array1);
    }// Now generating data for the best case
    cout << "Data for the best case" << endl;
    file3 << "Data for the best case" << endl;
    for(int i = 1000; i <= 50000; i+= 1000){
        array1 = new int[i];
        if(array1 == NULL){
            cerr << "Error allocating memory" << endl;
            exit(1);
        }
        random_number_generator(array1,i);
        selection_sort<int>(array1, i);
        auto start = std::chrono::high_resolution_clock::now(); 
        selection_sort<int>(array1,i);
        auto stop = std::chrono::high_resolution_clock::now();
        auto time_period = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        cout << "For" << i << "numbers:" << time_period << endl;
        file3 << "For" << i << "numbers:" << time_period << endl;
        file4 << time_period << "," << endl;
        free(array1);
    }
    cout << "Data for the average case" << endl;
    file5 << "Data for the average case" << endl;
    int** arr = new int*[3];//Two-dimentional array to hold three copies of the same array
    if(arr == NULL){
            cerr << "Error allocating memory" << endl;
            exit(1);
    }
    for(int i = 1000; i <= 50000; i+= 1000){
        for(int k = 0; k < 3; k++){ //allocating memory for three arrays
            arr[k] = new int[i];
            if(arr[k] == NULL){
                cerr << "Error allocating memory" << endl;
                exit(1);
            }
        }
        random_number_generator(arr[0],i); // generating random numbers for an array
        for(int t = 0; t < i; t++){ // copying the random numbers to the other arrays
            arr[1][t] = arr[0][t];  
            arr[2][t] = arr[0][t];
        }
        long long sum = 0;
        for(int j = 0; j < 3; j++){
            auto start = std::chrono::high_resolution_clock::now(); 
            selection_sort<int>(arr[j],i);
            auto stop = std::chrono::high_resolution_clock::now();
            auto period = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
            sum += period;
        }
        long long avg_period = sum / 3;
        cout << "For " << i << " numbers: " << avg_period << endl;
        file5 << "For " << i << " numbers: " << avg_period << endl;
        file6 << avg_period << "," << endl;
        for(int y = 0; y < 3; y++){ // freeing memory of the arrays
            free(arr[y]);
        }
    } 
    free(arr);
}
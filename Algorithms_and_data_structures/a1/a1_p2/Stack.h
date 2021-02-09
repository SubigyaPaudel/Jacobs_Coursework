#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>

template <class T>
class Stack{
    private:
        T* array;
        int max_size;
        int current_occupancy;
    public:
        Stack();
        Stack(const Stack&);
        Stack(int size);
        ~Stack();
        bool push(T element);
        bool pop(T& out);
        T back(void){return array[current_occupancy];}
        int getNumentries() {return (current_occupancy + 1);}
};

template <class T>
Stack<T>::Stack(){
    array = new T[10];
    max_size = 10;
    current_occupancy = -1;
}

template <class T>
Stack<T>::Stack(const Stack<T>& a){
    this->max_size = a.max_size;
    this->current_occupancy = a.current_occupancy;
    for(int i = 0; i <= current_occupancy; i++)
        array[i] = a.array[i];
}

template <class T>
Stack<T>::Stack(int size){
    array = new T[size];
    max_size = size;
    current_occupancy = -1;
}

template <class T>
Stack<T>::~Stack(){
    delete [] array;
}

template <class T>
bool Stack<T>::push(T element){
    if(current_occupancy+1 == max_size){
        std::cout << "Stack full. Unable to push" << element << std::endl;
        return false;
    }else{
        current_occupancy++;
        std::cout << "Putting" << element << "into the Stack" << std::endl; 
        array[current_occupancy] = element;
        return true;
    }
}

template <class T>
bool Stack<T>::pop(T& out){
    if(current_occupancy < 0){
        std::cout << "Stack empty, unable to pop" << std::endl; 
        return false;
    }else{
        std::cout << "Popping" << array[current_occupancy] << "out of the stack" << std::endl;
        out = array[current_occupancy];
        current_occupancy--;
        return true;
    }
}

#endif
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstdlib>
#include "stack.h"

template <class T>
class queue{
    private:
        stack<T> input;
        stack<T> output;
        int current_size;
        int size;
    public:
        queue(int size);
        ~queue();
        T sync(stack<T> input, stack<T> output);
        void add(T);
        T remove();
        bool isempty();
};

template <class T>
queue<T>::queue(int size){
    input = stack<T>(size);
    output = stack<T>(size);
    this->size = size;
    current_size = -1;
}

template <class T>
queue<T>::~queue(){
    input.~stack();
    output.~stack();
}

template <class T>
T queue<T>::sync(stack<T> source, stack<T> sink){
    while(!sink.is_empty())
        std::cout << "Popping the sink" << std::endl;
        T thing = sink.pop();
    while(!source.is_empty())
        sink.push(source.pop());
    T ret = sink.pop();
    while(!sink.is_empty())
        source.push(sink.pop());
    return ret;
}

template <class T>
T queue<T>::remove(){
    try{
        if(current_size == -1){
            std::string error = "Queue is empty";
            throw error; 
        }
        current_size--;
        T copy = this->sync(output,input);
        return copy;
    }catch(std::string error){
        std::cout << error << std::endl;
    }
}

template <class T>
bool queue<T>::isempty(){
    if(current_size == -1){
        return true;
    }else{
        return false;
    }
}

template <class T>
void queue<T>::add(T thing){
    try{
        if(current_size == size - 1){
            std::string error = "Queue full";
            throw error;
        }
        input.push(thing);
        current_size++;
    }catch(std::string error){
        std::cout << error << std::endl;
    }
}

#endif
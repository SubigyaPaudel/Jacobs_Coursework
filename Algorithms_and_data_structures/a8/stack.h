#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
#include <string>

template <class T>
class node{
    public:
        T key;
        node<T>* next;
        node();
        node(T thing, node<T>* next);
};

template <class T>
node<T>::node(){
    next = NULL;
}

template <class T>
node<T>::node(T thing, node<T>* next){
    std::cout << "This is the node constructor" << std::endl;
    this->key = thing;
    this->next = next;
}

template <class T>
class stack : public node<T>{
    private:
        int max_size;
        int current_size; 
        node<T>* top;
    public:
        stack();
        stack(int new_size);
        ~stack();
        void push(T thing);
        T pop();
        bool is_empty();
};

template <class T>
stack<T>::stack(){
    max_size = 0;
    current_size = -1;
    top = NULL;
}

template <class T>
stack<T>::stack(int new_size){
    max_size = new_size;
    current_size = -1;
    top = NULL;
}

template <class T>
void stack<T>::push(T thing){
   try{
       if(current_size == max_size -1){
           std::string message = "Stack full. Overflow!";
           throw message;
       }
       node<T>* new_node = new node<T>(thing,top);
       top = new_node;
       current_size ++;
   }catch(std::string error){
       std::cout << error << std::endl;
   }
}

template <class T>
T stack<T>::pop(){
    try{
        if(is_empty()){
            std::string error = "Stack empty. Underflow!";
            throw error;
        }else{
            T copy = top->key;
            node<T>* dummy = top;
            top = top->next;
            delete dummy;
            current_size--;
            return copy;
        }
    }
    catch(std::string error){
        std::cout << error << std::endl;
    }
}

template <class T>
bool stack<T>::is_empty(){
    if(current_size == -1){
        return true;
    }else{
        return false;
    }
}

template <class T>
stack<T>::~stack(){
    while(!this->is_empty()){
        this->pop();
    }
}

#endif
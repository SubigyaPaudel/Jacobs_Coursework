#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstdlib>
#include <iostream>

template <class T>
class node{
    public:
        T item;
        node<T>* next;
        node<T>* prev;
};

template <class T>
class list{
    private:
        node<T>* start;
    public:
        list();
        list(const list<T>&);
        ~list();
        bool push_front(T item);
        bool push_back(T item);
        T pop_front();
        T pop_back();
        T get_front();
        T get_back();
        int get_number();
};

template <class T>
list<T>::list(){
    start = NULL; // constructor up and running
}

template <class T>
list<T>::list(const list<T>& a){
    node<T>* cursor = a.start;
    T item = cursor->item;
    while(cursor!= NULL){
        this->push_front(item);
        cursor = cursor->next;
        if(cursor != NULL)
            item = cursor->item;        
    }
}

template <class T>
bool list<T>::push_front(T item){
    node<T>* new_node = new node<T>;
    if(new_node == NULL){
        std::cout << "Error allocating memory" << std::endl;
        return false;
    }
    new_node->item = item;
    if(start == NULL){
       start = new_node;
       start->next = NULL;
       start->prev = NULL;
    }else{
        new_node->next = start;
        new_node->prev = NULL;
        start->prev = new_node;
        start = new_node;
    }
    return true;
}

template <class T>
bool list<T>::push_back(T item){
    node<T>* new_node = new node<T>;
    if(new_node == NULL){
        std::cout << "Error allocating memory" << std::endl;
        return false;
    }
    new_node->item = item;
    if(start == NULL){
        new_node->next = NULL;
        new_node->prev = NULL;
        start = new_node;
    }else{
        node<T>* cursor = start;
        while(cursor->next != NULL){
            cursor = cursor->next;
        }
        cursor->next = new_node;
        new_node->prev = cursor;
        new_node->next = NULL;
    }
    return true;
}

template <class T>
T list<T>::pop_front(){
    T itemcopy = start->item;
    node<T>* copy = start;
    if(start->next != NULL){
        start = start->next;
        start->prev = NULL;
        delete copy;
        return itemcopy;
    }else{
        delete copy;
        start = NULL;
        return itemcopy;
    }
}

template <class T>
T list<T>::pop_back(){
    node<T>* cursor = start;
    while(cursor->next != NULL)
        cursor = cursor->next;
    T copyitem = cursor->item;
    if(cursor->prev != NULL){
        cursor->prev->next = NULL;
        delete cursor;
    }else{
        delete cursor;
        start = NULL;
    }
    return copyitem;
}

template <class T>
T list<T>::get_front(){
    return start->item;
}

template <class T>
T list<T>::get_back(){
    node<T>* cursor = start;
    while(cursor->next != NULL){
        cursor = cursor->next;
    }
    T item = cursor->item;
    return item;            
}

template <class T>
int list<T>::get_number(){
    node<T>* cursor = start;
    int i = 0;
    while(cursor != NULL){
        cursor = cursor->next;
        ++i;
    }
    return i;
}

template <class T>
list<T>::~list(){
    node<T>* cursor = start;
    node<T>* copy;
    while(cursor != NULL){
        copy = cursor;
        cursor = cursor->next;
        delete copy;
    }
}
#endif
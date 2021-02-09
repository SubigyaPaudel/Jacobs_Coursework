#include "hash_table.h"
#include <iostream>
#include <cstdlib>

node::node(int new_key, int new_value){
    key = new_key;
    value = new_value;
}

Hashtable::Hashtable(int maxsize){
    this->maxSize = maxsize;
    currentSize = 0;
    arr = new node*[maxsize];
}

int Hashtable::hashcode(int key, int attempt){
    return (key % 337 + attempt) % maxSize;     // this function is suited for the data in 
                                                // in test_hash_table.cpp as 337 is a prime number
                                                // which is far from the powers of 2 and 10 and 
                                                // is greater than the size of the elements in our data   
}

void Hashtable::insertnode(int key, int value){
    int attempt = 0;
    int desired_position = hashcode(key, attempt);
    while(arr[desired_position] != NULL && attempt < maxSize){
        attempt++;
        desired_position = hashcode(key, attempt);
    }
    if (attempt + 1 == maxSize){
        std::cout << "Hash table full." << std::endl;
    }
    node* newnode = new node(key, value);
    arr[desired_position] = newnode;
    currentSize++;      
}

int Hashtable::get(int key){
    int attempt = 0;
    int target = hashcode(key, attempt);
    while(attempt < maxSize && arr[target] != NULL && arr[target]->key != key ){
        attempt++;
        target = hashcode(key, attempt);
    }
    if(attempt + 1 == maxSize || arr[target] == NULL){
        std::cout << "Pair with " << key << " as key not found" << std::endl;
        return -1; 
    }
    return arr[target]->value;
}

void Hashtable::printtable(){
    for(int i = 0; i < maxSize; i++){
        if(arr[i] == NULL){
            std::cout << i << " = NULL" << std::endl;
        }else{
            std::cout << i << " = (key = " << arr[i]->key << ", value = " << arr[i]->value << ")" << std::endl; 
        }
    }
}

bool Hashtable::isEmpty(){
   return (currentSize == 0);
}

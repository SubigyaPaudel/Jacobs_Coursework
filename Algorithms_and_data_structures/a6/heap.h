#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstdlib>

template <class T>
class heap{
    public:
        T* array;
        heap(T* array, int no);
        heap(const heap&);
        ~heap();
        T operator[](int index) const;
        int size;
};

template <class T>
heap<T>::heap(T* copy, int number){
    array = new T[number];
    for(int i = 0; i < number; i++)
        array[i] = copy[i];
    size = number;
}

template <class T>
T heap<T>::operator[](int index) const{
    return array[index];
}

template <class T>
heap<T>::heap(const heap<T>& copy){
    array = new T[copy.size];
    size = copy.size;
    for(int i = 0; i < copy.size; i++)
        array[i] = copy[i];
}

template <class T>
heap<T>::~heap(){
    delete array;
}

template <class T>
void max_heapify(heap<T> &a, int index){
    int largest;
    int l = index * 2 + 1;  // since the index starts from 0 the adjustments in the two following lines had to be made 
    int r = (index + 1) * 2;
    if(a[l] > a[index] && l < a.size)
        largest = l;
    else
        largest = index;
    if(a[r] > a[largest] && r < a.size)
        largest = r;
    if(largest != index){
        T copy = a[index];
        a.array[index] = a[largest];
        a.array[largest] = copy;
        max_heapify<T>(a, largest);
    }
}

template <class T>
void build_max_heap(heap<T>& a){
    for(int i = (a.size-1)/2; i >= 0; i--){
        max_heapify<T>(a, i);
    }
}

template <class T>
void heapsort(heap<T>& a){
    build_max_heap<T>(a);
    int length = a.size;
    for(int i = length-1; i >= 0; i--){
        T copy = a[0];
        a.array[0] = a[i];
        a.array[i] = copy;
        a.size--;
        max_heapify<T>(a, 0); 
    }
    a.size = length;
}

//Another variant of heap-sort for problem 6.2 b.)

template <class T>
void heapsort_different(heap<T>& pile){
    build_max_heap<T>(pile);
    int length = pile.size;
    for(int i = length-1; i >= 0; i--){
        T copy = pile[0];
        pile.array[0] = pile[i];
        pile.array[i] = copy;
        pile.size--;
        int pos = float_to_bottom(pile, 0);
        sink_to_place(pile, pos);
    }   
    pile.size = length;
}

template <class T>
int float_to_bottom(heap<T>& pile, int pos){
    int swap_index = pos;
    int left = 2 * pos + 1;
    int right = (pos + 1) * 2;
    if(left >= pile.size && right >= pile.size){
        return pos;
    }
    if(right >= pile.size){ // in the case that the right branch doesn't exist
        T copy = pile[left];
        pile.array[left] = pile[pos];
        pile.array[pos] = copy;
        return left;
    }
    if(pile[left] > pile[right])
        swap_index = left;
    else
        swap_index = right;
    T copy = pile[swap_index];
    pile.array[swap_index] = pile[pos];
    pile.array[pos] = copy;
    pos = float_to_bottom(pile, swap_index);
    return pos;
}

template <class T>
void sink_to_place(heap<T>& pile, int index){
    int parent = index >> 1;
    if(pile[parent] < pile[index]){
        T copy = pile[index];
        pile.array[index] = pile[parent];
        pile.array[parent] = copy;
        sink_to_place(pile, index);
    }
}

#endif
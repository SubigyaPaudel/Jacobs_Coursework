#ifndef HASH_TABLE_H
#define HASH_TABLE_H

class node{
    public:
        int key;
        int value;
        node(int key, int value); 
};

class Hashtable{
    private:
        node** arr;
        int maxSize;
        int currentSize;
    public:
        Hashtable(int maxsize);
        hashcode(int key, int attempt);
        void insertnode(int key, int value);
        int get(int key);
        bool isEmpty();
        void printtable();
};

#endif
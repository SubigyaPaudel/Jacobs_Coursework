#ifndef RB_TREES_H
#define RB_TREES_H

#include <cstdlib>
enum color {red, black};

class node{
    public:
        int key;
        node* parent; 
        node* left;
        node* right;
        color itscolor;
        node();
        node(int , node*, node*, node* = NIL, color);
};

class RedBlackTree{
    private:
        node* root;
    protected:
        void rotateLeft(node*&);
        void rotateRight(node*&);
        void RB_insertfixup(node*&);
        void RB_deletefixup(node*&);
        void transplant(node*& , node*&);
    public:
        RedBlackTree();
        void insert(int);
        //void del(node*&);
        node* predecessor(const node*);
        node* successor(const node*);
        node* get_tree_maximum();
        node* get_tree_minimum();
        node* getminimumfrom(const node* rooted_at);
        node* getmaximumfrom(const node* rooted_at);
        node* search(int);
        void preorder_print_rooted_at(node*&);
        void print_tree();
};

node* NIL = new node(0,NULL, NULL, NULL, black);

#endif
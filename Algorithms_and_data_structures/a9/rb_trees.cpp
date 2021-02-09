#include "rb_trees.h"
#include <iostream>
#include <cstdlib>
#include <string>

node::node(){
    key = 0;
    parent = NIL;
    left = NIL;
    right = NIL;
    itscolor = black;
}

node::node(int number, node* parent, node* left, node* right, color mycolor){
    key = number;
    this->parent = parent;
    this->left = left;
    this->right = right;
    itscolor = mycolor;
}

RedBlackTree::RedBlackTree(){
    root = NIL;
}

void RedBlackTree::rotateLeft(node*& x){
    node* y = x->right;
    if(y ==NIL){
        std::cout << "Right child for" << x->key << "doesn't exist" << std::endl;
        return;
    }
    x->right = y->left;
    if(y->left !=NIL)
        y->left->parent = x;
    y->parent = x->parent;
    if(x->parent ==NIL)
        this->root = y;
    else if(x->parent->left == x)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y; 
}

void RedBlackTree::rotateRight(node*& y){
    node* x = y->left;
    if (x ==NIL){
        std::cout << "Left child for" << y->key << "doesn't exist" << std::endl;
        return;
    }
    if(x->right !=NIL)
        x->right->parent = y;
    x->parent = y->parent;
    if(y->parent ==NIL)
        this->root = x;
    else if(y->parent->left == y)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

node* RedBlackTree::getminimumfrom(const node* rooted_at){
    if(rooted_at->left == NIL){
       return const_cast<node*> (rooted_at);
    }else{
       return getminimumfrom(rooted_at->right);
    }
}

node* RedBlackTree::getmaximumfrom(const node* rooted_at){
   if(rooted_at->right == NIL){
       return const_cast<node*> (rooted_at);
   }else{
       return getminimumfrom(rooted_at->right);
   }
}

node* RedBlackTree::predecessor(const node* place){
    return getmaximumfrom(place->left);
}

node* RedBlackTree::successor(const node* place){
    return getminimumfrom(place->right);
}

node* RedBlackTree::search(int value){
    node* start = root;
    while(start->key != value || start !=NIL){
        if(value < start->key)
            start = start->left;
        else
            start = start->right;
    }
    if(start ==NIL){
        std::cout << value << "not found in the tree" << std::endl;
        return NIL;
    }else{
        return start;
    }
}

void RedBlackTree::insert(int number){
    node* newnode = new node(number);
    node* y =NIL;
    node* x = this->root;
    while(x !=NIL){
        y = x;
        if(number > x->key){
            x = x->right;
        }else{
            x = x->left;        
        }
    }
    std::cout << "Past the while loop" << std::endl;
    newnode->parent = y;
    if(y == NIL){
        this->root = newnode;
    }else if(newnode->key > y->key){
        y->right = newnode;
    }else{
        y->left = newnode;
    }
    std::cout << "calling fixup" << std::endl;
    RB_insertfixup(newnode);
}

void RedBlackTree::RB_insertfixup(node*& place){
    while(place->parent->itscolor == red){
        if(place->parent == place->parent->parent->left){
            node* uncle = place->parent->parent->right;
            if(uncle->itscolor == red){
                place->parent->itscolor = black;
                uncle->itscolor = black;
                uncle->parent->itscolor = red;
                place = uncle->parent;
            }else{
                if(place == place->parent->right){
                    place = place->parent;
                    rotateLeft(place);
                }
                place->parent->itscolor = black;
                place->parent->parent->itscolor = red;
                rotateRight(place->parent->parent);
            }
        }else{
            node* uncle = place->parent->parent->left;
            if(uncle->itscolor == red){
                place->parent->itscolor = black;
                uncle->itscolor = black;
                place->parent->parent->itscolor = red;
                place = place->parent->parent;
             }else{
                if(place == place->parent->left){
                    place = place->parent;
                    rotateRight(place);
                }
                place->parent->itscolor = black;
                place->parent->parent->itscolor = red;
                rotateLeft(place->parent->parent);
            }
        }
    }
}

void RedBlackTree::preorder_print_rooted_at(node*& start){
    if(start ==NIL){
        return;
    }else{
        preorder_print_rooted_at(start->left);
        std::cout << start->key;
        preorder_print_rooted_at(start->right);
    }
}

void RedBlackTree::transplant(node*& a, node*& b){
    if(a->parent == NIL){
        this->root = a;
    }else if(a->parent->left == a){
        a->parent->right = b;
    }else{
        a->parent->left = b;
    }if(b !=NIL){
        b->parent = a->parent;
    }
}

void RedBlackTree::print_tree(){
    preorder_print_rooted_at(this->root);
}
node* RedBlackTree::get_tree_maximum(){
    return this->getmaximumfrom(this->root);
}

node* RedBlackTree::get_tree_minimum(){
    return this->getminimumfrom(this->root);
}
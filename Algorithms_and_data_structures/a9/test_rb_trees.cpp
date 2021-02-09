#include <iostream>
#include <cstdlib>
#include "rb_trees.h"

using namespace std;

int main(){
    RedBlackTree tree;
    int input;
    char action;
    while(true){
        cout << "Type 'i' to insert a value to the RB tree" << endl;
        //cout << "Type 'd' to delete a value from the RB tree" << endl;
        cout << "Type 'p' to print the values inside the RB tree" << endl;
        cout << "Type '+' to get the maximum value stored in the tree" << endl;
        cout << "Type '-' tp get the minimum value stored in the tree" << endl;
        cout << "Type 'n' to get the successor of a value" << endl;
        cout << "Type 'b' to get the predecessor of a value" << endl;
        cout << "Type 'x' tp leave this session" << endl;
        cin >> action;
        if(action == 'x'){
            break;
        }else if(action == 'i'){
            cout << "Enter an integer" << endl;
            cin >> input;
            tree.insert(input);
        /*
        }else if(action == 'd'){
            cout << "Enter an integer to delete" << endl;
            cin >> input;
            node* position = tree.search(input);
            if(position ==NIL){
                cout << input << " is not in tree" << endl;
            }else{
                tree.del(position);
            }
        */
        }else if(action == 'p'){
            tree.print_tree();
        }else if(action == '+'){
            const node* target = tree.get_tree_maximum();
            cout << "Max value of the tree:" << target->key << endl;            
        }else if(action == '-'){
            const node* target = tree.get_tree_minimum();
            cout << "Min value of the tree" << target->key << endl;
        }else if(action == 'n'){
            cout << "Enter an integer" << endl;
            cin >> input;
            node* target = tree.search(input);
            if(target == NIL){
                cout << input << "is not in the tree" << endl;
            }else{
                node* target2 = tree.successor(target);
                cout << input << "'s successor is" << target2->key << endl;
            }
        }else if(action == 'b'){
            cout << "Enter an integer" << endl;
            cin >> input;
            const node* target = tree.search(input);
            if(target == NIL){
                cout << input << "is not in the tree" << endl;
            }else{
                node* target2 = tree.predecessor(target);
                cout << input << "'s predecessor is" << target2->key << endl;
            }
        }
    }
}
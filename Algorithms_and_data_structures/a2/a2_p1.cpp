#include <iostream>
#include <cstdlib>
#include <list>
#include <fstream>


using namespace std;

int main(){
    list<int> A, B;
    list<int>::iterator Aiterator, Biterator;
    int input;
    int count = 0;
    do{
        cout << "Enter a number" << endl;
        cin >> input;
        count++;
        if(input <= 0){
            break;
        }else{
            A.push_back(input);
            B.push_front(input);
        }
    }while(true);
    Aiterator = A.begin();
    Biterator = B.begin();
    ofstream file1("listB.txt");
    if(file1.bad()){
        cerr << "Failed to open file file1.txt" << endl;
        exit(1);
    }
    for(int i = 0; i < count - 1; i++){
        cout << *Aiterator;
        Aiterator++;
        file1 << *Biterator;
        Biterator++;
    }
    cout << endl;
    file1.close();
    cout << "Moving the first element of both the lists to the end" << endl;
    int receive = A.front();
    A.pop_front();
    A.push_back(receive);
    receive = B.front();
    B.pop_front();
    B.push_back(receive);
    cout << "Elements of the list A are :";
    for(Aiterator = A.begin(); Aiterator != A.end(); Aiterator++){
        cout << *Aiterator << ",";
    }
    cout << "\b and Elements of list B are: ";
    for(Biterator = B.begin(); Biterator != B.end(); Biterator++){
        cout << *Biterator << ",";
    }
    cout << "\b \n";
    cout << "Merging the two lists" << endl;
    A.merge(B);
    cout << "The elements of the new list are" << endl;
    for(Aiterator = A.begin(); Aiterator != A.end(); Aiterator++)
        cout << *Aiterator << " ";
    return 0;
}
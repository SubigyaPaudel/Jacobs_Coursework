#include <iostream>
#include <vector>

using namespace std;

int main(){
    string entry;
    vector<string> container;
    vector<string>::iterator it;
    int num_of_entries = 0;
    while(true){
        cout << "Enter a word" << endl;
        cin >> entry;
        if(entry == "END")
            break;
        container.push_back(entry);
        num_of_entries++;
    }
    for(int i = 0; i < num_of_entries; i++)
        cout << container[i] << ' ';
    cout << endl;
    for(it = container.begin(); it != container.end(); it++)
        cout << *it << ",";
    cout << "\b" << endl;
    return 0;
}
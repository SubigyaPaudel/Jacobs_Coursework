#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string entry;
    vector<string> container;
    while(true){
        cout << "Enter a string" << endl;
        getline(cin,entry);
        if(entry == "END"){
            break;
        }else{
            container.push_back(entry);
        }
    }
    if(container.size() >= 5){
        string copy = container[1];
        container[1] = container[4];
        container[4] = copy;
    }else if(container.size() < 2){
        cout << "Swap unsuccessful since second and fifth elements are not present" << endl;
    }else{
        cout << "Swap unsuccessful since fifth element does not exist" << endl;
    }  
    vector<string>::iterator it;
    container.pop_back();
    container.push_back("???");
    for(unsigned int i = 0; i < container.size(); i++){
        if(i + 1 != container.size())
            cout << container[i] << ",";
        else
            cout << container[i] << endl;
    }
    for(it = container.begin(); it != container.end(); it++){   
        if(it + 1 != container.end())
            cout << *it << ";";
        else
            cout << *it << endl;        
    }
    for(it = container.end(); it!= container.begin(); it--)
        cout << *it << " ";
    cout << *it;
    return 0;
}
    
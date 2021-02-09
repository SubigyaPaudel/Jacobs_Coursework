#include <iostream>
#include <exception>

using namespace std;

class Ownexception: public exception{
    private:
        string message;
    public:
        Ownexception();
        const char* what(){return "Ownexception\n";}
};

Ownexception::Ownexception(): exception() {
    message = "Default case exception";
}

void function(int x){
    if(x == 1){
        throw 'a';
    }else if(x == 2){
        throw (int) 12;
    }else if(x == 3){
        throw true;
    }else{
        Ownexception a;
        throw a;
    }
}

int main(){
    int x;
    cout << "Enter an integer" << endl;
    cin >> x;
    try{
        function(x);
    }catch (int i){
        cerr << "Caught in main " << i << endl;
    }catch (char a){
        cerr << "Caught in main " << a << endl;
    }catch (bool t){
        cerr << "Caught in main " << t << endl;
    }catch(Ownexception a){
        cerr << a.what() << endl;
    }
    return 0;
}
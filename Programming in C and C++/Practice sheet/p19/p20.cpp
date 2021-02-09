#include <iostream>
#include <fstream>

using namespace std;

class worker{
    private:
        int id;
        string name;
    public:
        worker(int, const std::string&);
        friend ofstream& operator <<(const worker& a, ofstream& file);
};

worker::worker(int id, const string& name){
    this->id = id;
    this->name = name;
}

ofstream& operator<<(const worker& a, ofstream& file){
    file << "Name: " << a.name << "ID: " << a.id;
    return file;
}

int main() {
    worker a(234, "John McEnroe");
    worker b(324, "Jack Nicholson");
    cout << a << b;
    return 0;
}
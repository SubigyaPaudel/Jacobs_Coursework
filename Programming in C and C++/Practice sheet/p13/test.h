#include <iostream>
#include <cstring>

class person{
    private:
        std::string name;
        int age;
    public:
        person();
        person(std::string, int);
        person(const person&);
        std::string getname() const{return name;}
        int getage() const{return age;}
        void setage(int age){this->age = age;}
        void setname(std::string){this->name = name;}
};

class family{
    private:
        int number;
        std::string lastname;
        person* members;
    public:
        family();
        family(number,lastname,person*);
        family(const family&);
};



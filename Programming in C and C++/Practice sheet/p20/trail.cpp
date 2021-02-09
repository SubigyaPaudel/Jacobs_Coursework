#include <iostream>

class me{
    protected:
        std::string name;
    public:
        me(){name = "Me";}
        me(const me& a){this->name = a.name;}
        virtual void print() const{std::cout<<name<<std::endl;}
        virtual ~me(){;}
};

class you : public me{
    protected:
        int age;
    public:
        you();
        you(const you&);
        void print() const{std::cout<<name<<age<< "?"<<std::endl;}
        ~you(){;}
};

you::you():me(){
    age = 53;
}

you::you(const you& copy){
    this->name = copy.name;
    this->age = copy.age;
}

int main(){
    me** slew = new me*[2];
    slew[0] = new me;
    slew[1] = new you;
    slew[0]->print();
    slew[1]->print();
    delete slew[0];
    delete slew[1];
    delete []slew;
    return 0;
}

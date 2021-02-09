#include <cstring>
#include <iostream>

class one{
    protected:
        std::string name;
        int age;
    public:
        one();
        one(std::string, int);
        one(const one&);
        std::string getname() const{return name;}
        void setname(std::string name){this->name = name;}
        int getage() const{return name;}
        void setage(int age){this->age = age;}
};


class two: public one{
    protected:
        std::string profession;
        int yearsofexp;
    public:
        two();
        two(std::string, int, std::string, int);
        two(const two&);
        std::string getprofession() const{return profession;}
        int getyearsofexp() const{return yearsofexp;}
        void setprofession(std::string profession){this->profession = profession;}
        void setyearsofexp(int yearsofexp){this->yearsofexp = yearsofexp;}
};

class three: public one{
    protected:
        double height;
    public:
        three();
        three(std::string, int, double);
        three(const three&);
        double getheight() const{return height;}
        void setheight(double height){this->height = height;}
};

class four: public two, public three{
    private:
        float weight;
    public:
        four();
        four(std::string, int, std::string, int, double, float);
        four(const four&);
        float getweight() const{return weight;} 
        void setweight(float weight){this->weight = weight;}
}
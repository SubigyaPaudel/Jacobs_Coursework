#include <iostream>

class Car{
    protected:
        std::string brand_name;
        std::string model_name;
        double price;
    public:
        Car(const std::string&, const std::string&, double);
        ~Car();
        void setmodel(const std::string&);
};

inline Car::Car(const std::string& brand, const std::string& model, double price){
    brand_name = brand;
    model_name = model;
    this->price = price;
}

Car::~Car(){
}

void Car::setmodel(const std::string& newmodel){
    model_name = newmodel;
}

class Taxi :public Car{
    private:
        int capacity;
    public:
        Taxi(const std::string&, const std::string&, double, int);
        void print();
};

Taxi::Taxi(const std::string& brand, const std::string& model, double theprice, int max) : Car(brand, model, theprice) {
    brand_name = brand;
    model_name = model_name;
    price = theprice;
    capacity = max;
}


void Taxi::print(){
    using namespace std;
    cout << "Brand Name: " << brand_name << endl;
    cout << "Model Name: " << model_name << endl; 
    cout << "Price: " << price << endl;
    cout << "Maximum number of passengiere" << capacity << endl;
}

int main(){
    Taxi one("Mercedes", "Maybach", 255000, 4);
    one.print();
    return 0;
}
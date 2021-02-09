#include "two.h"
#include <iostream>
#include <cstring>

one::one() : name("Unknown"), age(0){
}

one(std::string name, int age){
    this->name = name;
    this->age = age;
}

one::one(const one& copy){
    this->name = copy.name;
    this->age = copy.age;
}

two::two() : one(){
    profession = "Unknown";
    yearsofexp = 0;
}

two::two(std::string name, int age, std::string profession, int yearsofexp): one(name, age){
    
}


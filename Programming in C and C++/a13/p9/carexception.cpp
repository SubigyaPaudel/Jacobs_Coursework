#include "carexception.h"
#include <cstring>
#include <iostream>

Motor::Motor(){
    power = 11.0;
    std::string error;
    error = "This motor has errors";
    throw error;
}

Car::Car(){
    Motor a;
    move = a;
}

Garage::Garage(){
    try{
        Car l;
        vehicle = l;
    }catch(std::string s){
        std::string errormsg = "The car in this Garage has problem with its motor";
        throw errormsg;
    }
}
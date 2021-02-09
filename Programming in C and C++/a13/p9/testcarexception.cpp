#include <iostream>
#include "carexception.h"

int main(void){
    try{
        Garage l;
    }catch(std::string x){
        std::cerr << x << std::endl;
    }
    return 0;
}
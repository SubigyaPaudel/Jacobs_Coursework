#include "Access.h"
#include <iostream>

void Access::activate(unsigned int code){
    std::pair<std::set<int>::iterator, bool> complete;
    complete = codes.insert(code);
    if(complete.second){
        std::cout << "Code activated successfully" << std::endl; 
    }else{
        std::cout << "Code activation unsuccessful" << std::endl;
    }
}

void Access::deactivate(unsigned int code){
    codes.erase(code);
    std::cout << "Code deactivated" << std::endl;
}

bool Access::isactive(unsigned int code) const{
    if(codes.count(code) != 0){
        return true;
    }else{
        return false;
    }
}
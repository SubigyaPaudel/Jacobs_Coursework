#include "Access2.h"
#include <map>

void Access::activate(unsigned int code, unsigned int access_level){
    codes[code] = access_level;
}

void Access::deactivate(unsigned int code){
    codes.erase(code);
}

bool Access::isactive(unsigned int code, unsigned int access_level) const{
    if(codes.count(code)){
        if(access_level >= codes.find(code)->second){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void Access::change_access_level(unsigned int code, unsigned int new_level){
    codes[code] = new_level;
}
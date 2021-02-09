#include "vector.h"

vector::vector(double* array, int members){
    this->array = array;
    this->members = members;
}

vector::vector(){
    double set[1] = {1};
    members = 1;
    array = set;
}

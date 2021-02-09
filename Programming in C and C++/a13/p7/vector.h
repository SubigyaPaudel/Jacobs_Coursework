#ifndef VECTOR_H_
#define VECTOR_H_

class vector{
    private:
        double* array;
        int members;
    public:
        vector();
        vector(double*, int);
        void setcomponent(int index,double value) {array[index] = value;}
        double getcomponent(int index) {return array[index];}
};

#endif